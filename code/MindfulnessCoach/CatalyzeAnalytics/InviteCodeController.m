//
//  InviteCodeController.m
//  CBTiCoach
//
//  Created by Josh Ault on 1/6/15.
//

#import "InviteCodeController.h"
#import "Client.h"
#import "AppConstants.h"
#import "WebPage.h"
#import "Catalyze.h"
#import "AFNetworking.h"
#import "Heartbeat.h"
#import "AnalyticsConstants.h"

@interface InviteCodeController()

@property UIView *spinnerContainer;
@property UIActivityIndicatorView *spinner;

@end

@implementation InviteCodeController

#pragma mark - Lifecycle

/**
 *  initWithClient:filename
 */
- (id)initWithClient:(Client *)client filename:(NSString *)filename {
    self = [super initWithClient:client filename:filename];
    if (self != nil) {
        self.title = NSLocalizedString(@"Mindfulness Coach", nil);
    }

    return self;
}

#pragma mark - Instance Methods

/**
 *  webView:shouldStartLoadWithRequest:navigationType
 */
- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType {
    NSString *lastPathComponent = request.URL.path.lastPathComponent;
    BOOL shouldLoadRequest = NO;

    if ([lastPathComponent isEqualToString:kContentHTMLURLViewIntroductionScreen]) {
        [self confirmInviteCode];
    } else if ([lastPathComponent isEqualToString:kContentHTMLURLViewHomeScreen]) {
        self.client.viewedLegalScreens = YES;

        [self dismissViewControllerAnimated:NO completion:nil];
    } else {
        shouldLoadRequest = [super webView:webView shouldStartLoadWithRequest:request navigationType:navigationType];
    }

    return shouldLoadRequest;
}

- (void)showLegalIntroduction {
    self.title = NSLocalizedString(@"Mindfulness Coach", nil);

    WebPage *webPage = [[WebPage alloc] initWithFilename:kContentHTMLURLLegalIntroduction];
    [self loadWebPage:webPage];
    [Heartbeat logEvent:@"legalIntroduction" withParameters:nil];
    
}

- (void)confirmInviteCode {
    NSString *code = [self.webView stringByEvaluatingJavaScriptFromString:@"document.getElementById('inviteCode').value"];
    if (!code || code.length == 0) {
        return;
    }
    if (!_spinner) {
        [self initSpinner];
    }
    [self setSpinnerAnimating:YES];
    NSDictionary *body = @{@"username" : @"VAUser", @"password": @"d42654ff3fe423c2544fc945aa62d0bf"};
    AFHTTPRequestOperationManager *manager = [AFHTTPRequestOperationManager manager];
    manager.requestSerializer = [AFJSONRequestSerializer serializer];
    manager.responseSerializer = [AFJSONResponseSerializer serializer];
    [manager.requestSerializer setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    [manager.requestSerializer setValue:@"application/json" forHTTPHeaderField:@"Accept"];
    [manager.requestSerializer setValue:@"969ad33b-fcc9-494a-acc6-66bfe2f2d1b6" forHTTPHeaderField:@"X-Api-Key"]; // this is (and should be) the CBT-i API key
    [manager POST:@"https://api.catalyze.io/v2/auth/signin" parameters:body success:^(AFHTTPRequestOperation *operation, id responseObject) {
        NSString *sessionToken = [responseObject objectForKey:@"sessionToken"];
        [manager.requestSerializer setValue:[NSString stringWithFormat:@"Bearer %@", sessionToken] forHTTPHeaderField:@"Authorization"];

        [manager GET:[NSString stringWithFormat:@"https://api.catalyze.io/v2/classes/inviteCodes/query?pageSize=10&pageNumber=1&field=code&searchBy=%@", code] parameters:nil success:^(AFHTTPRequestOperation *operation, id responseObject) {
            if ([responseObject count] == 1) {
                NSDictionary *entry = (NSDictionary *)[responseObject objectAtIndex:0];
                NSString *subjectId = [[entry objectForKey:@"content"] valueForKey:@"subjectId"];
                [[NSUserDefaults standardUserDefaults] setValue:code forKey:@"userInviteCode"];
                if (subjectId && subjectId != [NSNull null]) {
                    [[NSUserDefaults standardUserDefaults] setValue:subjectId forKey:@"subjectId"];
                }
                [[NSUserDefaults standardUserDefaults] synchronize];

                // for the rest of the analytics to work, we still need to login to this app and not the PTSD app
                [CatalyzeUser logInWithUsernameInBackground:[body valueForKey:@"username"] password:[body valueForKey:@"password"] success:^(CatalyzeUser *result) {
                    [self setSpinnerAnimating:NO];
                    [Heartbeat logEvent:kEventInviteCodeConfirmed withParameters:nil];
                    [self showLegalIntroduction];
                } failure:^(NSDictionary *result, int status, NSError *error) {
                    [self setSpinnerAnimating:NO];
                    //fix this or analytics won't work, likely a bad username/password
                    NSLog(@"Login failed %@. Catalyze Analytics will fail!", result);
                    [[[UIAlertView alloc] initWithTitle:@"Error" message:@"Could not confirm the invite code, please try again." delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil, nil] show];
                }];
            } else {
                [self setSpinnerAnimating:NO];
                [[[UIAlertView alloc] initWithTitle:@"Error" message:@"That invite code is invalid. Please enter a new invite code." delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil, nil] show];
            }
        } failure:^(AFHTTPRequestOperation *operation, NSError *error) {
            [self setSpinnerAnimating:NO];
            NSLog(@"failed to query for invite code %ld - %@", [[operation response] statusCode], [operation responseString]);
            [[[UIAlertView alloc] initWithTitle:@"Error" message:@"That invite code is invalid. Please enter a new invite code." delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil, nil] show];
        }];
    } failure:^(AFHTTPRequestOperation *operation, NSError *error) {
        [self setSpinnerAnimating:NO];
        //fix this or analytics won't work, likely a bad username/password
        NSLog(@"Login failed %@. Catalyze Analytics will fail!", [operation responseString]);
        [[[UIAlertView alloc] initWithTitle:@"Error" message:@"Could not confirm the invite code, please try again." delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil, nil] show];
    }];
}

- (void)initSpinner {
    _spinner = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
    _spinnerContainer = [[UIView alloc] initWithFrame:CGRectMake(0, 0, _spinner.frame.size.width, _spinner.frame.size.height)];
    [_spinnerContainer addSubview:_spinner];
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:_spinnerContainer];
}

- (void)setSpinnerAnimating:(BOOL)animating {
    if (animating) {
        [_spinner startAnimating];
    } else {
        [_spinner stopAnimating];
    }
    NSString *enabledString = animating ? @"true" : @"false";
    [self.webView stringByEvaluatingJavaScriptFromString:[NSString stringWithFormat:@"document.getElementById('inviteCode').disabled=%@", enabledString]];
    [self.webView stringByEvaluatingJavaScriptFromString:[NSString stringWithFormat:@"document.getElementById('inviteCodeConfirm').disabled=%@", enabledString]];
}

@end

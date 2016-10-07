//
//  HomeViewController.m
//  MindfulnessCoach
//

#import "HomeViewController.h"
#import "AppConstants.h"
#import "ButtonMenuViewController.h"
#import "Client.h"
#import "RoundedButton.h"
#import "UIView+VPDView.h"
#import "Heartbeat.h"

@implementation HomeViewController

#pragma mark - Lifecycle

/**
 *  viewDidLoad
 */
- (void)viewDidLoad {
  [super viewDidLoad];
  
  UIBarButtonItem *aboutButtonItem = [[UIBarButtonItem alloc] initWithTitle:NSLocalizedString(@"About", nil)
                                                                      style:UIBarButtonItemStyleBordered
                                                                     target:self
                                                                     action:@selector(handleAboutButtonTouched:)];
  self.navigationItem.leftBarButtonItem = aboutButtonItem;
  [aboutButtonItem release];
}

#pragma mark - Event Handlers

/**
 *  handleMenuButtonWasTouched
 */
- (void)handleMenuButtonWasTouched:(id)sender {
  RoundedButton *button = (RoundedButton *)sender;
  [self performActionBlockForAction:button.action];


    NSLog(@"action is %@", button.action);
    
    // attempting to convert NSManagedObject button.action into accessible NSDictionary
    NSArray *keys = [[[button.action entity] attributesByName] allKeys];
    NSDictionary *dict = [button.action dictionaryWithValuesForKeys:keys];
    
    // get title property
    // NSString *buttonActionTitle = [dict objectForKey:title];
    NSString *buttonActionTitle = dict[@"title"];
    NSLog(@"The dictionary for displaying main content area is: %@", dict);
    
    NSLog(@"I have the name of the button!: %@", buttonActionTitle);
    NSLog(@"CATALYZE...CATALYZE...CATALYZE...CATALYZE...CATALYZE");
    [Heartbeat logEvent:buttonActionTitle withParameters:nil];
}

/**
 *  handleAboutButtonTouched
 */
- (void)handleAboutButtonTouched:(id)sender {
  ButtonMenuViewController *aboutMenuViewController = [[ButtonMenuViewController alloc] initWithClient:self.client];
  aboutMenuViewController.action = [self.client rootActionForGroup:kActionGroupAbout];
  
  [self.navigationController pushViewController:aboutMenuViewController animated:YES];
  
  [aboutMenuViewController release];
}

@end

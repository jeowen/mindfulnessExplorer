//
//  HelpViewController.m
//

#import "HelpViewController.h"
#import "Action.h"
#import "Heartbeat.h"

@implementation HelpViewController

/**
 *  initWithClient:filename
 */
- (id)initWithClient:(Client *)client filename:(NSString *)filename {
  self = [super initWithClient:client filename:filename];
  if (self != nil) {
    self.title = NSLocalizedString(@"Help", nil);

    UIBarButtonItem *doneBarButtonItem = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemDone
                                                                                       target:self
                                                                                       action:@selector(handleDoneButtonTapped:)];

    self.navigationItem.leftBarButtonItem = doneBarButtonItem;
    [doneBarButtonItem release];
  }
  
  return self;
}

/**
 *  handleDoneButtonTapped
 */
- (void)handleDoneButtonTapped:(id)sender {
    [Heartbeat logEvent:@"HelpDoneButtonTapped" withParameters:nil];
    NSLog(@"Heartbeat .. ... logEvent:HelpDoneButtonTapped");
    
  [self dismissViewControllerAnimated:YES completion:nil];
}

@end

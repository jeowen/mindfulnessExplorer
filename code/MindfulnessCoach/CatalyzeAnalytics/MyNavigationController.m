//
//  MyNavigationController.m
//  MindfulnessCoach
//
//  Created by CatalyzeIntern on 6/25/15.
//
//

#import "MyNavigationController.h"
#import "Heartbeat.h"
#import "AnalyticsConstants.h"

@interface MyNavigationController ()

@end

@implementation MyNavigationController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Navigation

- (void)navigationBar:(UINavigationBar *)navigationBar didPopItem:(UINavigationItem *)item {
    NSString *title = item.title;
    if (!title) {
        title = @"Unknown";
    }
    [Heartbeat logEvent:kEventNavBack withParameters:@{@"From": title}];
}

@end

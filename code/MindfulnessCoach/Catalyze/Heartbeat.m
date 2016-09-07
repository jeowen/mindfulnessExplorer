//
//  Heartbeat.m
//  CBTiCoach
//
//  Created by Josh Ault on 10/27/14.
//  Copyright (c) 2014 Catalyze, Inc.
//

#import <Foundation/Foundation.h>
#import "Catalyze.h"
#import "Heartbeat.h"
#import "BackedQueue.h"
#import "Reachability.h"

@implementation Heartbeat

+ (NSString *)tokenIfValid {
    if ([[CatalyzeUser currentUser] isAuthenticated]) {
        return [[NSUserDefaults standardUserDefaults] valueForKey:kCatalyzeAuthorizationKey];
    }
    return nil;
}

+ (void)checkQueue {
    NSLog(@"checking queue...");
    if ([[BackedQueue sharedQueue] count] > 0) {
        NSLog(@"emptying queue...");
        // dispatch async job to pop items off and send them one by one
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            while ([[BackedQueue sharedQueue] count] > 0 && [[NSUserDefaults standardUserDefaults] boolForKey:@"__catalyze_reachability"]) {
                [Heartbeat makeRequestWithContent:[[BackedQueue sharedQueue] pop]];
            }
        });
    }
}

+ (void) logEvent:(NSString *)eventName withParameters:(NSDictionary *)parameters{
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        NSString *token = [self tokenIfValid];
        if (!token) {
            [self signIn:^(CatalyzeUser *result) {
                [self createEntry:eventName withParameters:parameters];
            }];
        } else {
            [self createEntry:eventName withParameters:parameters];
        }
    });
}

+ (void)createEntry:(NSString *)eventName withParameters:(NSDictionary *)parameters {
    NSMutableDictionary *content = [NSMutableDictionary dictionary];
    [content setObject:eventName forKey:@"event"];
    if (parameters) {
        [content setObject:parameters forKey:@"metadata"];
    }
    [content setObject:[[NSUserDefaults standardUserDefaults] valueForKey:@"sessionId"] forKey:@"sessionId"];
    NSString *subjectId = [[NSUserDefaults standardUserDefaults] valueForKey:@"subjectId"];
    if (subjectId) {
        [content setObject:subjectId forKey:@"subjectId"];
    }
    NSString *userInviteCode = [[NSUserDefaults standardUserDefaults] valueForKey:@"userInviteCode"];
    if (userInviteCode) {
        [content setObject:userInviteCode forKey:@"userInviteCode"];
    }
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss'Z'"];
    [content setObject:[formatter stringFromDate:[NSDate date]] forKey:@"timestamp"];
    [content setObject:[Catalyze applicationId] forKey:@"appId"];
    if ([[NSUserDefaults standardUserDefaults] boolForKey:@"__catalyze_reachability"]) {
        [Heartbeat makeRequestWithContent:content];
    } else {
        // add it to the disk backed queue
        [[BackedQueue sharedQueue] push:content];
    }
}

+ (void)makeRequestWithContent:(NSDictionary *)content {
    NSLog(@"posting %@", content);
    CatalyzeEntry *myEntry = [CatalyzeEntry entryWithClassName:@"event"];
    [myEntry setContent:[NSMutableDictionary dictionaryWithDictionary:content]];
    [myEntry createInBackgroundWithSuccess:^(id result) {
        NSLog(@"Successfully posted event!");
    } failure:^(NSDictionary *result, int status, NSError *error) {
        NSLog(@"Failed to track analytics event %@! %@", result, content);
    }];
}

+ (void)signIn:(CatalyzeUserSuccessBlock)completionBlock {
    [CatalyzeUser logInWithUsernameInBackground:@"VAUser" password:@"d42654ff3fe423c2544fc945aa62d0bf" success:^(CatalyzeUser *result) {
        if (completionBlock) completionBlock(result);
    } failure:^(NSDictionary *result, int status, NSError *error) {
        if (completionBlock) completionBlock(nil);
    }];
}

#pragma mark - Lifecycle

+ (void)stop {
    [Heartbeat logEvent:@"session_end" withParameters:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:kReachabilityChangedNotification object:nil];
    [[BackedQueue sharedQueue] synchronizeToDisk];
}

+ (void)start {
    [[BackedQueue sharedQueue] readQueueFromDisk];
    
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:@"__catalyze_reachability"];
    NSString *sessionId = [[NSUUID UUID] UUIDString];
    [[NSUserDefaults standardUserDefaults] setValue:sessionId forKey:@"sessionId"];
    [[NSUserDefaults standardUserDefaults] synchronize];
    [Heartbeat logEvent:@"session_start" withParameters:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(reachabilityChanged:) name:kReachabilityChangedNotification object:nil];
    Reachability *reachability = [Reachability reachabilityForInternetConnection];
    
    [reachability startNotifier];
    NSNotification *notification = [NSNotification notificationWithName:@"reachability" object:reachability];
    [self reachabilityChanged:notification];
}

+ (void)reachabilityChanged:(NSNotification *)note {
    Reachability *curReach = [note object];
    NSParameterAssert([curReach isKindOfClass:[Reachability class]]);
    
    if ([curReach currentReachabilityStatus] == ReachableViaWiFi || [curReach currentReachabilityStatus] == ReachableViaWWAN) {
        NSLog(@"network is reachable");
        [[NSUserDefaults standardUserDefaults] setBool:YES forKey:@"__catalyze_reachability"];
        [Heartbeat checkQueue];
        
    } else {
        NSLog(@"network unreachable");
        [[NSUserDefaults standardUserDefaults] setBool:NO forKey:@"__catalyze_reachability"];
    }
}

@end

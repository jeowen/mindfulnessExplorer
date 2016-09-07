//
//  Heartbeat.h
//  CBTiCoach
//
//  Created by Josh Ault on 10/27/14.
//  Copyright (c) 2014 Catalyze, Inc.
//


#import "Catalyze.h"
#import "AnalyticsConstants.h"

@interface Heartbeat : NSObject

+ (void)start;
+ (void)stop;

+ (void)checkQueue;

+ (void)logEvent:(NSString *)eventName withParameters:(NSDictionary *)parameters;

+ (void)signIn:(CatalyzeUserSuccessBlock)completionBlock;

@end
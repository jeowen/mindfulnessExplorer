//
//  Heartbeat.h
//  catalyze-analytics
//
//  Created by Josh Ault on 2/12/15.
//  Copyright (c) 2015 Catalyze, Inc. All rights reserved.
//


#import "Catalyze.h"

@interface Heartbeat : NSObject

+ (void)start;
+ (void)stop;

+ (void)checkQueue;

+ (void)logEvent:(NSString *)eventName withParameters:(NSDictionary *)parameters;

@end
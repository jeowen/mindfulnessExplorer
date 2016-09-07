//
//  BackedQueue.m
//  CBTiCoach
//
//  Created by Josh Ault on 1/7/15.
//  Copyright (c) 2015 Catalyze, Inc. All rights reserved.
//

#import "BackedQueue.h"

#define BACKING_KEY @"__catalyze_req_queue"

@implementation BackedQueue : NSObject

+ (BackedQueue *)sharedQueue {
    static BackedQueue *sharedBackedQueue = nil;
    
    static dispatch_once_t backedQueueOncePredicate;
    dispatch_once(&backedQueueOncePredicate, ^{
        sharedBackedQueue = [[BackedQueue alloc] init];
    });
    return sharedBackedQueue;
}

- (id)init {
    self = [super init];
    if (self) {
        queue = [[NSMutableArray alloc] init];
        NSArray *storedQueue = [[NSUserDefaults standardUserDefaults] objectForKey:BACKING_KEY];
        if (storedQueue) {
            [queue addObjectsFromArray:[NSMutableArray arrayWithArray:storedQueue]];
        }
    }
    return self;
}

- (void)readQueueFromDisk {
    queue = [[NSMutableArray alloc] init];
    NSArray *storedQueue = [[NSUserDefaults standardUserDefaults] objectForKey:BACKING_KEY];
    if (storedQueue) {
        [queue addObjectsFromArray:[NSMutableArray arrayWithArray:storedQueue]];
    }
}

- (void)synchronizeToDisk {
    [[NSUserDefaults standardUserDefaults] setObject:queue forKey:BACKING_KEY];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

- (void)push:(id)item {
    [queue addObject:item];
}

- (id)pop {
    id item = [queue firstObject];
    if (item) {
        [queue removeObjectAtIndex:0];
    }
    return item;
}

- (id)peek {
    return [queue firstObject];
}

- (NSUInteger)count {
    return [queue count];
}

@end
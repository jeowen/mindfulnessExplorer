//
//  BackedQueue.h
//  catalyze-analytics
//
//  Created by Josh Ault on 2/12/15.
//  Copyright (c) 2015 Catalyze, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BackedQueue : NSObject {
    NSMutableArray *queue;
}

+ (BackedQueue *)sharedQueue;

- (void)readQueueFromDisk;
- (void)synchronizeToDisk;

- (void)push:(id)item;
- (id)pop;
- (id)peek;
- (NSUInteger)count;

@end

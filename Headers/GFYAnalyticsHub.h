//
//  GFYAnalyticsHub.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 4/11/17.
//  Copyright © 2017 Gfycat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 `GFYAnalyticsHub` is a central point where all analytics data is submitted.
 The hub forwards all method calls to registered tracker objects.
 */
@interface GFYAnalyticsHub: NSObject

/**
 Singleton hub istance
 */
@property (class, nonatomic, readonly) GFYAnalyticsHub *sharedHub;

/**
 Extension point allowing library client to collect analytics events reported via hub.

 @param tracker tracker object to consume analytic events
 */
- (void)addTracker:(id)tracker;

@end

NS_ASSUME_NONNULL_END

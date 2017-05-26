//
//  GFYAnalyticsTrackerBase.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 4/11/17.
//  Copyright © 2017 Gfycat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface _GFYAnalyticsTrackerBase : NSObject

- (void)trackEvent:(NSString *)name withParameters:(NSDictionary<NSString *, NSString *> *)parameters;

@end

NS_ASSUME_NONNULL_END

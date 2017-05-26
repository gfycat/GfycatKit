//
//  GFYSearchHistorySettings.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 4/10/17.
//  Copyright © 2017 Gfycat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <Foundation/Foundation.h>
#import "GfycatInterfaceCache.h"

NS_ASSUME_NONNULL_BEGIN

/**
 <#Description#>
 */
NS_SWIFT_NAME(GFYSearchHistorySettingsProtocol)
@protocol GFYSearchHistorySettings <NSObject, NSCopying>

/**
 <#Description#>
 */
@property (nonatomic, strong) id<GfycatInterfaceCache> interfaceCache;

@end

/**
 <#Description#>
 */
@interface GFYSearchHistorySettings : NSObject <GFYSearchHistorySettings>

/**
 <#Description#>

 @param settings <#settings description#>
 */
+ (void)fillWithDefaults:(id<GFYSearchHistorySettings>)settings;

@end

NS_ASSUME_NONNULL_END

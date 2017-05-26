//
//  GFYFlagMediaViewControllerSettings.h
//  GfycatKit
//
//  Created by Oleksii Chubenko on 3/31/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <Foundation/Foundation.h>
#import "GfycatCachedApi.h"
#import "GfycatBlackListCache.h"

NS_ASSUME_NONNULL_BEGIN

/**
 <#Description#>
 */
NS_SWIFT_NAME(GFYFlagMediaViewControllerSettingsProtocol)
@protocol GFYFlagMediaViewControllerSettings <NSObject, NSCopying>

/**
 <#Description#>
 */
@property (nonatomic, strong) id<GfycatApi> gfycatApi;

/**
 <#Description#>
 */
@property (nonatomic, strong) id<GfycatBlackListCache> blackListCache;

@end

/**
 <#Description#>
 */
@interface GFYFlagMediaViewControllerSettings : NSObject <GFYFlagMediaViewControllerSettings>

/**
 <#Description#>

 @param settings <#settings description#>
 */
+ (void)fillWithDefaults:(id<GFYFlagMediaViewControllerSettings>)settings;

@end

NS_ASSUME_NONNULL_END

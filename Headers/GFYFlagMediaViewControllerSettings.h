//
//  GFYFlagMediaViewControllerSettings.h
//  GfycatComponents
//
//  Created by Oleksii Chubenko on 3/31/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol GfycatApi;
@protocol GfycatBlackListCache;

NS_SWIFT_NAME(GFYFlagMediaViewControllerSettingsProtocol)
@protocol GFYFlagMediaViewControllerSettings <NSObject, NSCopying>

@property (nonatomic, strong) id<GfycatApi> gfycatApi;
@property (nonatomic, strong) id<GfycatBlackListCache> blackListCache;

@end

@interface GFYFlagMediaViewControllerSettings : NSObject <GFYFlagMediaViewControllerSettings>

+ (void)fillWithDefaults:(id<GFYFlagMediaViewControllerSettings>)settings;

@end

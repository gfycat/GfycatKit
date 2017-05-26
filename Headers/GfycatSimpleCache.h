//
//  GfycatSimpleCache.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 3/16/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <Foundation/Foundation.h>
#import "GfycatApiCache.h"
#import "GfycatInterfaceCache.h"
#import "GfycatBlackListCache.h"

NS_ASSUME_NONNULL_BEGIN

@interface GfycatSimpleCache : NSObject <GfycatApiCache, GfycatInterfaceCache, GfycatBlackListCache>

@property (class, nonatomic, readonly) GfycatSimpleCache *sharedCache;

@end

NS_ASSUME_NONNULL_END

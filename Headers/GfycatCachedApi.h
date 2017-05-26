//
//  GfycatCachedApi.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 3/7/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <GfycatApiKit/GfycatApiKit.h>
#import "GfycatApiCache.h"

NS_ASSUME_NONNULL_BEGIN

@interface GfycatCachedApi : NSObject <GfycatApi>

+ (instancetype)apiWithCache:(id<GfycatApiCache>)cache;
- (instancetype)initWithCache:(id<GfycatApiCache>)cache;

@end

NS_ASSUME_NONNULL_END

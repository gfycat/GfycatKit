//
//  GfycatCachedApi.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 3/7/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <GfycatApiKit/GfycatApiKit.h>
#import "GfycatApiCache.h"

@interface GfycatCachedApi : NSObject <GfycatApi>

+ (instancetype)apiWithCache:(id<GfycatApiCache>)cache;
- (instancetype)initWithCache:(id<GfycatApiCache>)cache;

@end

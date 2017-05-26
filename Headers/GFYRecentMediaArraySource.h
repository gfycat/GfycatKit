//
//  GFYRecentMediaArraySource.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 3/16/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <Foundation/Foundation.h>
#import "GfycatInterfaceCache.h"
#import "GFYArraySource.h"

NS_ASSUME_NONNULL_BEGIN

@interface GFYRecentMediaArraySource : NSObject <GFYArraySource>

+ (instancetype)sourceWithCache:(id<GfycatInterfaceCache>)cache;
- (instancetype)initWithCache:(id<GfycatInterfaceCache>)cache;

@property (nonatomic, readonly) id<GfycatInterfaceCache> cache;

@end

NS_ASSUME_NONNULL_END

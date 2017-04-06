//
//  GFYRecentMediaArraySource.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 3/16/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GfycatInterfaceCache.h"
#import "GFYArraySource.h"

@interface GFYRecentMediaArraySource : NSObject <GFYArraySource>

+ (instancetype)sourceWithCache:(id<GfycatInterfaceCache>)cache;
- (instancetype)initWithCache:(id<GfycatInterfaceCache>)cache;

@property (nonatomic, readonly) id<GfycatInterfaceCache> cache;

@end

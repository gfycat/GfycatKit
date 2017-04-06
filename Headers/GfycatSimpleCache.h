//
//  GfycatSimpleCache.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 3/16/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GfycatApiCache.h"
#import "GfycatInterfaceCache.h"
#import "GfycatBlackListCache.h"

@interface GfycatSimpleCache : NSObject <GfycatApiCache, GfycatInterfaceCache, GfycatBlackListCache>

+ (instancetype)sharedCache;

@end

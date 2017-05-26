//
//  GFYCategoryMediaArraySource.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 3/16/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <Foundation/Foundation.h>
#import "GFYArraySource.h"

NS_ASSUME_NONNULL_BEGIN

@interface GFYCategoryMediaArraySource : NSObject <GFYArraySource>

+ (instancetype)sourceWithCategory:(GfycatCategory *)category;
- (instancetype)initWithCategory:(GfycatCategory *)category;

@property (nonatomic, readonly) GfycatCategory *category;

@end

NS_ASSUME_NONNULL_END

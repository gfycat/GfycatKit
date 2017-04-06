//
//  GFYCategoryMediaArraySource.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 3/16/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GFYArraySource.h"

@interface GFYCategoryMediaArraySource : NSObject <GFYArraySource>

+ (instancetype)sourceWithCategory:(GfycatCategory *)category;
- (instancetype)initWithCategory:(GfycatCategory *)category;

@property (nonatomic, readonly) GfycatCategory *category;

@end

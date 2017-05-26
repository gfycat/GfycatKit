//
//  GFYRecentCategoryCollectionViewCellModel.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 5/3/17.
//  Copyright © 2017 Gfycat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <Foundation/Foundation.h>
#import <GfycatApiKit/GfycatApiKit.h>
#import "GFYArrayDiff.h"

NS_ASSUME_NONNULL_BEGIN

/**
 <#Description#>
 */
@interface GFYRecentCategoryCollectionViewCellModel : NSObject <NSCopying, GFYArrangable>

/**
 <#Description#>
 
 @return <#return value description#>
 */
+ (instancetype)model;

/**
 <#Description#>
 
 @param recentMedia <#recentMedia description#>
 @return <#return value description#>
 */
+ (instancetype)modelWithMedia:(GfycatMedia * _Nullable)recentMedia;

/**
 <#Description#>
 
 @param recentMedia <#recentMedia description#>
 @return <#return value description#>
 */
- (instancetype)initWithMedia:(GfycatMedia * _Nullable)recentMedia;

/**
 <#Description#>
 */
@property (nonatomic, readonly, nullable) GfycatMedia *recentMedia;

@end

NS_ASSUME_NONNULL_END

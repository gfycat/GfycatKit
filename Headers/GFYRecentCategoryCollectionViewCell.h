//
//  GFYRecentCategoryCollectionViewCell.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 3/21/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GFYArrayDiff.h"
#import "GFYCollectionViewCell.h"
#import "GFYMediaView.h"

@interface GFYRecentCategoryCollectionViewCellModel : NSObject <NSCopying, GFYArrangable>

+ (instancetype)model;
+ (instancetype)modelWithMedia:(GfycatMedia *)recentMedia;
- (instancetype)initWithMedia:(GfycatMedia *)recentMedia;

@property (nonatomic, readonly) GfycatMedia *recentMedia;

@end

@interface GFYRecentCategoryCollectionViewCell : GFYCollectionViewCell<GFYRecentCategoryCollectionViewCellModel *>

@end

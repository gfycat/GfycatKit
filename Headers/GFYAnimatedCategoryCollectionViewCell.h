//
//  GFYAnimatedCategoryCollectionViewCell.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 2/23/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GfycatApiKit/GfycatApiKit.h>
#import "GFYCollectionViewCell.h"
#import "GFYMediaView.h"

@interface GFYAnimatedCategoryCollectionViewCell : GFYCollectionViewCell<GfycatCategory *>

@property (nonatomic, assign) GFYMediaViewFormal mediaFormat;

@end

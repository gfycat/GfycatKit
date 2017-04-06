//
//  GFYCategoryPickerSettings.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 2/23/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GfycatCachedApi.h"
#import "GfycatInterfaceCache.h"
#import "GFYArrayDiff.h"
#import "GFYCollectionViewCell.h"
#import "GFYMediaView.h"

NS_SWIFT_NAME(GFYCategoryPickerSettingsProtocol)
@protocol GFYCategoryPickerSettings <NSObject, NSCopying>

@property (nonatomic, strong) id<GfycatApi> gfycatApi;
@property (nonatomic, strong) id<GfycatInterfaceCache> interfaceCache;

@property (nonatomic, assign) CGFloat cornerRadius;
@property (nonatomic, assign) CGFloat itemSpacing;
@property (nonatomic, assign) UIEdgeInsets contentInset;
@property (nonatomic, assign) UICollectionViewScrollDirection scrollDirection;

@property (nonatomic, assign) NSInteger categoryGridSize;
@property (nonatomic, assign) CGSize categoryAspectRatio;
@property (nonatomic, assign) GFYMediaViewFormal categoryMediaFormat;

@property (nonatomic, copy) NSDictionary<Class<GFYArrangable>, Class<GFYCollectionViewCell>> *categoryCellViews;

@end

@interface GFYCategoryPickerSettings : NSObject <GFYCategoryPickerSettings>

+ (void)fillWithDefaults:(id<GFYCategoryPickerSettings>)settings;

- (void)registerCellView:(Class<GFYCollectionViewCell>)cellView forCategoryModel:(Class<GFYArrangable>)model;

@end

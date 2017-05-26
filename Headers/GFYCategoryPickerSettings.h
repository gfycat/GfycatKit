//
//  GFYCategoryPickerSettings.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 2/23/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <UIKit/UIKit.h>
#import "GfycatCachedApi.h"
#import "GfycatInterfaceCache.h"
#import "GFYArrayDiff.h"
#import "GFYCollectionViewCell.h"
#import "GFYMediaView.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(GFYCategoryPickerSettingsProtocol)
/**
 <#Description#>
 */
@protocol GFYCategoryPickerSettings <NSObject, NSCopying>

/**
 GfycatApi implementation. Either cached, or plain one
 */
@property (nonatomic, strong) id<GfycatApi> gfycatApi;

/**
 GfycatInterfaceCache implementation. Most applications should just use default GfycatSimpleCache
 */
@property (nonatomic, strong) id<GfycatInterfaceCache> interfaceCache;

/**
 Cell corner radius
 */
@property (nonatomic, assign) CGFloat cornerRadius;

/**
 Item spacing in collection view
 */
@property (nonatomic, assign) CGFloat itemSpacing;

/**
 Edge insets in collection view
 */
@property (nonatomic, assign) UIEdgeInsets contentInset;

/**
 Scroll direction
 */
@property (nonatomic, assign) UICollectionViewScrollDirection scrollDirection;

/**
 Number of rows or colums, depending on scroll direction
 */
@property (nonatomic, assign) NSInteger categoryGridSize;

/**
 CGSize struct defining aspect ratio for category item views
 */
@property (nonatomic, assign) CGSize categoryAspectRatio;

/**
 Media format to be played as a category thumbnail
 */
@property (nonatomic, assign) GFYMediaViewFormat categoryMediaFormat;

/**
 Toggles recent items category
 */
@property (nonatomic, assign) BOOL enableRecentItems;

/**
 Defines mapping between model and view classes for custom items
 */
@property (nonatomic, copy) NSDictionary<Class<GFYArrangable>, Class<GFYCollectionViewCell>> *categoryCellViews;

/**
 The host application should call the `registerCellView:forCategoryModel:` method to register view
 classes for any custom model classes it will inject in the category list.

 @param cellView Cell view class
 @param model Cell model class
 */
- (void)registerCellView:(Class<GFYCollectionViewCell>)cellView forCategoryModel:(Class<GFYArrangable>)model;

@end

/**
 <#Description#>
 */
@interface GFYCategoryPickerSettings : NSObject <GFYCategoryPickerSettings>

/**
 <#Description#>

 @param settings <#settings description#>
 */
+ (void)fillWithDefaults:(id<GFYCategoryPickerSettings>)settings;

@end

NS_ASSUME_NONNULL_END

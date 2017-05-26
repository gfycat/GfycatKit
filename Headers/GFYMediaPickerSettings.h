//
//  GFYMediaPickerSettings.h
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
#import "GfycatBlackListCache.h"
#import "GFYArrayDiff.h"
#import "GFYCollectionViewCell.h"
#import "GFYMediaView.h"

NS_ASSUME_NONNULL_BEGIN

/**
 <#Description#>
 */
NS_SWIFT_NAME(GFYMediaPickerSettingsProtocol)
@protocol GFYMediaPickerSettings <NSObject, NSCopying>

/**
 GfycatApi implementation, either cached, or plain one
 */
@property (nonatomic, strong) id<GfycatApi> gfycatApi;

/**
 GfycatInterfaceCache implementation. Most applications should just use default GfycatSimpleCache
 */
@property (nonatomic, strong) id<GfycatInterfaceCache> interfaceCache;

/**
 GfycatBlackListCache implementation. Most applications should just use default GfycatSimpleCache
 */
@property (nonatomic, strong) id<GfycatBlackListCache> blackListCache;

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
@property (nonatomic, assign) NSInteger videoGridSize;

/**
 Media format to be played in media list
 */
@property (nonatomic, assign) GFYMediaViewFormat videoMediaFormat;

/**
 <#Description#>
 */
@property (nonatomic, assign) BOOL showMediaCellControllsOnTap;

/**
 Defines mapping between model and view classes for custom items
 */
@property (nonatomic, copy) NSDictionary<Class<GFYArrangable>, Class<GFYCollectionViewCell>> *mediaCellViews;

/**
 The host application should call the `registerCellView:forMediaModel:` method to register view
 classes for any custom model classes it will inject in the media list.

 @param cellView Cell view class
 @param model Cell model class
 */
- (void)registerCellView:(Class<GFYCollectionViewCell>)cellView forMediaModel:(Class<GFYArrangable>)model;

@end

/**
 <#Description#>
 */
@interface GFYMediaPickerSettings : NSObject <GFYMediaPickerSettings>

/**
 <#Description#>

 @param settings <#settings description#>
 */
+ (void)fillWithDefaults:(id<GFYMediaPickerSettings>)settings;

@end

NS_ASSUME_NONNULL_END

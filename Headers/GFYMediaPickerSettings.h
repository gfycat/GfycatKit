//
//  GFYMediaPickerSettings.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 2/23/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GfycatCachedApi.h"
#import "GfycatInterfaceCache.h"
#import "GfycatBlackListCache.h"
#import "GFYArrayDiff.h"
#import "GFYCollectionViewCell.h"
#import "GFYMediaView.h"

NS_SWIFT_NAME(GFYMediaPickerSettingsProtocol)
@protocol GFYMediaPickerSettings <NSObject, NSCopying>

@property (nonatomic, strong) id<GfycatApi> gfycatApi;
@property (nonatomic, strong) id<GfycatInterfaceCache> interfaceCache;
@property (nonatomic, strong) id<GfycatBlackListCache> blackListCache;

@property (nonatomic, assign) CGFloat cornerRadius;
@property (nonatomic, assign) CGFloat itemSpacing;
@property (nonatomic, assign) UIEdgeInsets contentInset;
@property (nonatomic, assign) UICollectionViewScrollDirection scrollDirection;

@property (nonatomic, assign) NSInteger videoGridSize;
@property (nonatomic, assign) GFYMediaViewFormal videoMediaFormat;

@property (nonatomic, copy) NSDictionary<Class<GFYArrangable>, Class<GFYCollectionViewCell>> *mediaCellViews;

@end

@interface GFYMediaPickerSettings : NSObject <GFYMediaPickerSettings>

+ (void)fillWithDefaults:(id<GFYMediaPickerSettings>)settings;

- (void)registerCellView:(Class<GFYCollectionViewCell>)cellView forMediaModel:(Class<GFYArrangable>)model;

@end

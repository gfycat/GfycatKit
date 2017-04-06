//
//  GFYMediaPickerViewController.h
//  Gfycat
//
//  Created by Victor Pavlychko on 1/15/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GfycatApiKit/GfycatApiKit.h>
#import "GFYArraySource.h"
#import "GFYMediaPickerSettings.h"

@class GFYMediaPickerViewController;

@protocol GFYMediaPickerDelegate <NSObject>
@optional

- (void)gfycatMediaPicker:(GFYMediaPickerViewController *)picker customizeView:(UICollectionViewCell *)view forMedia:(GfycatMedia *)media;
- (void)gfycatMediaPicker:(GFYMediaPickerViewController *)picker customizeView:(UICollectionViewCell *)view forItem:(id)model;
- (void)gfycatMediaPicker:(GFYMediaPickerViewController *)picker didSelectMedia:(GfycatMedia *)media withSource:(id<GFYArraySource>)source;
- (void)gfycatMediaPicker:(GFYMediaPickerViewController *)picker didSelectItem:(id)item withSource:(id<GFYArraySource>)source;
- (void)gfycatMediaPicker:(GFYMediaPickerViewController *)picker setActivityIndicatorActive:(BOOL)active;
- (UIViewController *)gfycatMediaPicker:(GFYMediaPickerViewController *)picker previewMedia:(GfycatMedia *)media withSource:(id<GFYArraySource>)source;
- (void)gfycatMediaPicker:(GFYMediaPickerViewController *)picker previewMedia:(GfycatMedia *)media withSource:(id<GFYArraySource>)source commitViewController:(UIViewController *)viewController;
- (void)gfycatMediaPicker:(GFYMediaPickerViewController *)picker longPressMedia:(GfycatMedia *)media withSource:(id<GFYArraySource>)source;
- (void)gfycatMediaPicker:(GFYMediaPickerViewController *)picker didFlagMedia:(GfycatMedia *)media withSource:(id<GFYArraySource>)source;

@end

@interface GFYMediaPickerViewController : UIViewController

+ (instancetype)pickerWithSettings:(id<GFYMediaPickerSettings>)settings;
- (instancetype)initWithSettings:(id<GFYMediaPickerSettings>)settings;

@property (nonatomic, copy) id<GFYMediaPickerSettings> settings;
@property (nonatomic, weak) id<GFYMediaPickerDelegate> delegate;

@property (nonatomic, strong) id<GFYArraySource> arraySource;
- (void)refreshMediaArraySource;

@property (nonatomic, readonly) UICollectionView *collectionView;

@end

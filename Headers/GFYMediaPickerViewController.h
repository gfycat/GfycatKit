//
//  GFYMediaPickerViewController.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 1/15/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <UIKit/UIKit.h>
#import <GfycatApiKit/GfycatApiKit.h>
#import "GFYArraySource.h"
#import "GFYMediaPickerSettings.h"

NS_ASSUME_NONNULL_BEGIN

@class GFYMediaPickerViewController;

/**
 The delegate of a `GFYMediaPickerViewController` object must adopt the `GFYMediaPickerDelegate` protocol.
 */
@protocol GFYMediaPickerDelegate <NSObject>
@optional

/**
 Delegate method `gfycatMediaPicker:customizeView:forMedia:` is called by `GFYMediaPickerViewController` before presenting the media item view in the list.
 
 If this methiod is not implemented, `GFYMediaPickerViewController` will proceed with calling the
 `gfycatMediaPicker:customizeView:forItem:` method.

 @param picker <#picker description#>
 @param view <#view description#>
 @param media <#media description#>
 */
- (void)gfycatMediaPicker:(GFYMediaPickerViewController *)picker customizeView:(UICollectionViewCell *)view forMedia:(GfycatMedia *)media;

/**
 Delegate method `gfycatMediaPicker:customizeView:forItem:` is called by `GFYMediaPickerViewController` before presenting
 a custom item in the media list.
 
 If this method is not implemented, not customization is performed.

 @param picker <#picker description#>
 @param view <#view description#>
 @param model <#model description#>
 */
- (void)gfycatMediaPicker:(GFYMediaPickerViewController *)picker customizeView:(UICollectionViewCell *)view forItem:(id)model;

/**
 Delegate method `gfycatMediaPicker:didSelectMedia:` is called by `GFYMediaPickerViewController` when user taps
 media item in the list.
 
 If this methiod is not implemented, `GFYMediaPickerViewController` will proceed with calling
 `gfycatMediaPicker:didSelectItem:` method.

 @param picker <#picker description#>
 @param media <#media description#>
 @param source <#source description#>
 */
- (void)gfycatMediaPicker:(GFYMediaPickerViewController *)picker didSelectMedia:(GfycatMedia *)media withSource:(id<GFYArraySource>)source;

/**
 Delegate method `gfycatMediaPicker:didSelectItem:withSource:` is called by `GFYMediaPickerViewController` when user taps
 a custom item in the media list.
 
 If this method is not implemented, the user interaction is ignored.

 @param picker <#picker description#>
 @param item <#item description#>
 @param source <#source description#>
 */
- (void)gfycatMediaPicker:(GFYMediaPickerViewController *)picker didSelectItem:(id)item withSource:(id<GFYArraySource>)source;

/**
 Delegate method `gfycatCategoryPicker:setActivityIndicatorActive:` is called by `GFYCategoryPickerViewController` when
 network activity is happening to allow the host application to display a custom progress indicator.
 
 If this method is not implemented, the default indicatior is displayed.

 @param picker <#picker description#>
 @param active <#active description#>
 */
- (void)gfycatMediaPicker:(GFYMediaPickerViewController *)picker setActivityIndicatorActive:(BOOL)active;

/**
 Delegate method `gfycatMediaPicker:previewMedia:withSource:` is called by `GFYMediaPickerViewController` when user uses 3D Touch to preview a media item in the list.
 
 When implemented in the host application, this method should return previewing view controller.
 
 If this method is not implemented, default implementation presents simple media preview.

 @param picker <#picker description#>
 @param media <#media description#>
 @param source <#source description#>
 @return <#return value description#>
 */
- (UIViewController *)gfycatMediaPicker:(GFYMediaPickerViewController *)picker previewMedia:(GfycatMedia *)media withSource:(id<GFYArraySource>)source;

/**
 Delegate method `gfycatMediaPicker:previewMedia:withSource:commitViewController:` is called by `GFYMediaPickerViewController` when user uses 3D Touch to pop the previewed media item in the list.
 
 If this method is not implemented, the default implementation calls `gfycatMediaPicker:didSelectMedia:withSource:` and dismisses the preview.

 @param picker <#picker description#>
 @param media <#media description#>
 @param source <#source description#>
 @param viewController <#viewController description#>
 */
- (void)gfycatMediaPicker:(GFYMediaPickerViewController *)picker previewMedia:(GfycatMedia *)media withSource:(id<GFYArraySource>)source commitViewController:(UIViewController *)viewController;

/**
 Delegate method `gfycatMediaPicker:longPressMedia:withSource:` is called by `GFYMediaPickerViewController` when user uses long tap on a media item in the list.
 
 If this method is not implemented, the user interaction is ignored.

 @param picker <#picker description#>
 @param media <#media description#>
 @param source <#source description#>
 */
- (void)gfycatMediaPicker:(GFYMediaPickerViewController *)picker longPressMedia:(GfycatMedia *)media withSource:(id<GFYArraySource>)source;

/**
 Delegate method `gfycatMediaPicker:didFlagMedia:withSource:` is called by `GFYMediaPickerViewController` when user uses flag button on a media item in the list.
 
 If this method is not implemented, the user interaction is ignored.

 @param picker <#picker description#>
 @param media <#media description#>
 @param source <#source description#>
 */
- (void)gfycatMediaPicker:(GFYMediaPickerViewController *)picker didFlagMedia:(GfycatMedia *)media withSource:(id<GFYArraySource>)source;

/**
 <#Description#>
 */
- (UIView * _Nullable)gfycatMediaPicker:(GFYMediaPickerViewController *)picker overlayViewForMedia:(GfycatMedia *)media;

@end

/**
 `GFYMediaPickerViewController` provides a convenient interface to pick media from Gfycat.
 */
@interface GFYMediaPickerViewController : UIViewController

/**
 <#Description#>

 @param settings <#settings description#>
 @return <#return value description#>
 */
+ (instancetype)pickerWithSettings:(id<GFYMediaPickerSettings> _Nullable)settings;

/**
 <#Description#>

 @param settings <#settings description#>
 @return <#return value description#>
 */
- (instancetype)initWithSettings:(id<GFYMediaPickerSettings> _Nullable)settings;

/**
 <#Description#>
 */
@property (nonatomic, copy) id<GFYMediaPickerSettings> settings;

/**
 <#Description#>
 */
@property (nonatomic, weak) id<GFYMediaPickerDelegate> delegate;

/**
 <#Description#>
 */
@property (nonatomic, strong) id<GFYArraySource> arraySource;

/**
 <#Description#>
 */
- (void)refreshMediaArraySource;

/**
 <#Description#>
 */
@property (nonatomic, readonly) UICollectionView *collectionView;

@end

NS_ASSUME_NONNULL_END

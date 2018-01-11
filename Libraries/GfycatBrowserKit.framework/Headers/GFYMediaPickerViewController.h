//
//  GFYMediaPickerViewController.h
//  GfycatBrowserKit
//
//  Created by Victor Pavlychko on 1/15/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  End-User License Agreement for Gfycat Software Product
//  
//  This End-User License Agreement (“EULA”) is a legal agreement between you
//  (either an individual or a single entity) (“the End User”) and Gfycat, Inc.
//  for the software product identified above, which includes computer software
//  and may include associated media, printed materials, and “online” or
//  electronic documentation (“Software Product”).
//  
//  By download, installing, copying or otherwise using the Software Product,
//  you agree to be bound by the terms of this EULA.
//  
//  Software Product License
//  
//  Gfycat is providing the Software Product solely for the purpose of allowing
//  the End User to avail of or enjoy the benefits of the services provided by
//  Gfycat. Except as expressly set forth herein, the End User is NOT allowed to
//  distribute this Software (either for profit or merely to recover your media and
//  distribution costs) whether as a stand-alone product, or as part of a
//  compilation or anthology, nor to use it for supporting your business or
//  customers. It may be distributed freely on any website or through any other
//  distribution mechanism, as long as no part of it is modified in any manner
//  whatsoever.
//  
//  1. Grant of License
//  
//  This EULA grants you the following rights: 
//  
//  a. Installation and Use. You may install and use an unlimited number of copies
//  of the Software Product.
//  
//  b. Reproduction and Distribution. You may reproduce and distribute an unlimited
//  number of copies of the Software Product; provided that each copy shall be a
//  true and complete copy, including all copyright and trademark notices, and
//  shall be accompanied by a copy of this EULA.
//  
//  c. Copies of the Software Product may be distributed as a standalone product or
//  included with your own product as long as the Software Product is not sold or
//  included in a product or package that intends to receive benefits through the
//  inclusion of the Software Product.
//  
//  2. Description Of Other Rights And Limitations
//  
//  a. Limitations. You may not reverse engineer, decompile, or disassemble the
//  Software Product.
//  
//  b. Update and Maintenance. Gfycat SDK upgrades shall be free of charge.
//  However, the End User shall be responsible to ensure that the Gfycat SDK is
//  updated as and when Gfycat releases new updates or upgrades.
//  
//  c. Separation of Components. The Software Product is licensed as a single
//  product. Its component parts may not be separated for use on more than one
//  computer.
//  
//  d. Assignment. You may assign all of your rights under this EULA, provided the
//  recipient agrees to the terms of this EULA and subject to the prior written
//  consent of Gfycat.
//  
//  e. Termination. Without prejudice to any other rights, Gfycat may terminate
//  this EULA if you fail to comply with the terms and conditions of this EULA. In
//  such event, you shall destroy all copies of the Software Product and all of its
//  component parts.
//  
//  3. Copyright
//  
//  Except as expressly provided herein, all title and copyrights in and to the
//  Software Product (including but not limited to any images, photographs,
//  clipart, libraries, and examples incorporated into the Software Product), the
//  accompanying printed materials, and any copies of the Software Product are
//  owned by Gfycat. The Software Product is protected by copyright laws and
//  international treaty provisions. 
//  
//  4. Limited Warranty
//  
//  a. No Warranties. Gfycat expressly disclaims any and all warranties for the
//  Software Product. The Software Product and any related documentation is
//  provided “as is” without warranty of any kind, either express or implied,
//  including, without limitation, the implied warranties or merchantability,
//  fitness for a particular purpose, or non-infringement. The entire risk arising
//  out of use or performance of the Software Product shall remain with the End
//  User.
//  
//  b. No Liability For Damages. In no event shall Gfycat be liable for any direct,
//  special, consequential, incidental or indirect damages whatsoever (including,
//  without limitation, damages for loss of business profits, business
//  interruption, loss of business information, or any other pecuniary loss)
//  arising out of the use of or inability to use this product, even if Gfycat is
//  aware of the possibility of such damages and known defects.
//  
//  5. Third Party License
//  
//  The Software Product may contain third party software which shall be separately
//  licensed as applicable. This license will be included within the Software
//  Product.
//  
//  6. Governing Law
//  
//  This EULA and all disputes arising thereof shall be subject to internal laws of
//  the State of California, USA, where the state and federal courts located in
//  Santa Clara County, California shall exclusive jurisdiction.
//

#import <UIKit/UIKit.h>
#import <GfycatApiKit/GfycatApiKit.h>
#import "GFYArraySource.h"
#import "GFYMediaPickerSettings.h"
#import "GFYCollectionViewSection.h"

NS_ASSUME_NONNULL_BEGIN

@protocol GFYArrayConsumer;
@class GFYMediaPickerViewController;
@class GFYCollectionViewManager;

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
 Delegate method `gfycatMediaPicker:longPressItem:withSource:` is called by `GFYMediaPickerViewController` when user uses long tap on a custom item in the list.
 
 If this method is not implemented, the user interaction is ignored.
 
 @param picker <#picker description#>
 @param item <#item description#>
 @param source <#source description#>
 */
- (void)gfycatMediaPicker:(GFYMediaPickerViewController *)picker longPressItem:(id)item withSource:(id<GFYArraySource>)source;

/**
 Delegate method `gfycatMediaPicker:didFlagMedia:withSource:` is called by `GFYMediaPickerViewController` when user uses flag button on a media item in the list.
 
 If this method is not implemented, the user interaction is ignored.

 @param picker <#picker description#>
 @param media <#media description#>
 @param source <#source description#>
 */
- (void)gfycatMediaPicker:(GFYMediaPickerViewController *)picker didFlagMedia:(GfycatMedia *)media withSource:(id<GFYArraySource>)source;

/**
 The host application implements `gfycatMediaPicker:customizeModel:` delegate method to modify media picker contents with custom items.
 
 The collection view model is represented as an array of arrays of models representing section and items correspondingly.
 
 All item models should conform to `GFYArrangable` and `NSCopying` protocols.
 
 @param picker <#picker description#>
 @param model <#model description#>
 @return <#return value description#>
 */
- (NSArray<id<GFYCollectionViewSection>> *)gfycatMediaPicker:(GFYMediaPickerViewController *)picker customizeModel:(NSArray<id<GFYCollectionViewSection>> *)model;


- (BOOL)isMediaPickerInCompactState;

/**
 <#Description#>
 */
- (UIView * _Nullable)gfycatMediaPicker:(GFYMediaPickerViewController *)picker overlayViewForMedia:(GfycatReferencedMedia *)media;

- (void)gfycatMediaPicker:(GFYMediaPickerViewController *)picker didFailWithError:(NSError * _Nullable)error withSource:(id<GFYArraySource>)source;
- (void)gfycatMediaPicker:(GFYMediaPickerViewController *)picker gotEmptyListWithSource:(id<GFYArraySource>)source;

- (void)gfycatMediaPickerWillBeginDragging:(GFYMediaPickerViewController *)picker;

@end

/**
 `GFYMediaPickerViewController` provides a convenient interface to pick media from Gfycat.
 */
@interface GFYMediaPickerViewController : UIViewController <GFYArrayConsumer>

/**
 <#Description#>

 @param settings <#settings description#>
 @return <#return value description#>
 */
+ (instancetype)pickerWithSettings:(GFYMediaPickerSettings * _Nullable)settings;

/**
 <#Description#>

 @param settings <#settings description#>
 @return <#return value description#>
 */
- (instancetype)initWithSettings:(GFYMediaPickerSettings * _Nullable)settings;

/**
 <#Description#>
 */
@property (nonatomic, copy) GFYMediaPickerSettings *settings;

/**
 <#Description#>
 */
@property (nonatomic, weak, nullable) id<GFYMediaPickerDelegate> delegate;

/**
 <#Description#>
 */
@property (nonatomic, strong) id<GFYArraySource> arraySource;

@property (nonatomic, assign, readonly, getter=isLoadingContent) BOOL loadingContent;

/**
 <#Description#>
 */
- (void)refreshMediaArraySource;

/**
 <#Description#>
 */
@property (nonatomic, readonly) UICollectionView *collectionView;

/**
 <#Description#>
 */
- (void)scrollModel:(id)model toVisibleAnimated:(BOOL)animated;

/**
 <#Description#>
 */
- (void)hideOverlayViewForModel:(id)model;

/**
 <#Description#>
 */
@property (nonatomic, assign, getter=isContentEditingEnabled) BOOL contentEditingEnabled;

- (void)closeAction:(id)sender;

@end

NS_ASSUME_NONNULL_END

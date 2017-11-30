//
//  GFYBrowserViewController.h
//  GfycatBrowserKit
//
//  Created by Victor Pavlychko on 1/17/17.
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

#import "GFYSimpleContainerViewController.h"
#import "GFYBrowserSettings.h"
#import "GFYBrowserController.h"
#import "GFYCategoryPickerViewController.h"
#import "GFYMediaPickerViewController.h"
#import "GFYNavigationView.h"

NS_ASSUME_NONNULL_BEGIN

@class GFYBrowserViewController;

/**
 <#Description#>

 @param item <#item description#>
 @param feed <#feed description#>
 */
typedef void (^GFYBrowserSelectionHandler)(GfycatMedia *item, GfycatCategory *feed);

/**
 The delegate of a `GFYBrowserViewController` object must adopt the `GFYBrowserDelegate` protocol.
 
 `GFYBrowserViewController` also forwards delegate methods called by
 `GFYCategoryPickerViewController`, `GFYMediaPickerViewController`, `GFYSearchHistoryViewController`
 and `GFYFlagMediaViewControllerViewController` which it presents as needed.
 */
@protocol GFYBrowserDelegate <NSObject, GFYCategoryPickerDelegate, GFYMediaPickerDelegate>
@optional

/**
 Delegate method `gfycatBrowser:requestExpandedState:` is called by `GFYBrowserViewController`
 to switch between fullscreen and compact modes. The host application should adjust the user interface
 accordingly in response to this event.

 @param browser `GFYBrowserViewController` instance
 @param expanded specifies if the UI should be expanded
 */
- (void)gfycatBrowser:(GFYBrowserViewController *)browser requestExpandedState:(BOOL)expanded completion:(void(^)(void))completion;

@end

/**
 `GFYBrowserViewController` serves as a façade for all browsing functionality provided by the *GfycatKeyboardKit*.
 
 Most applications will just instantiate `GFYBrowserViewController`, present it as needed and listen to the delegate
 events it reports.
 */
@interface GFYBrowserViewController : GFYSimpleContainerViewController <GFYBrowserControllerDelegate, GFYNavigationViewDelegate>

/**
 Creates new `GFYBrowserViewController` with the settings specified.

 @param settings browser settings
 @return `GFYBrowserViewController` instance
 */
+ (instancetype)browserWithSettings:(GFYBrowserSettings * _Nullable)settings;

/**
 Initialized `GFYBrowserViewController` with the settings specified.

 @param settings browser settings
 @return `GFYBrowserViewController` instance
 */
- (instancetype)initWithSettings:(GFYBrowserSettings * _Nullable)settings;

/**
 Browser settings
 */
@property (nonatomic, copy) GFYBrowserSettings *settings;

/**
 Browser delegate
 */
@property (nonatomic, weak) id<GFYBrowserDelegate> delegate;

/**
 Called by the browser controller when user selects a video
 */
@property (nonatomic, copy, nullable) GFYBrowserSelectionHandler selectionHandler;

/**
 Resets browser view controller to the category list state
 */
- (void)showCategories;

/**
 Cancels search if it's active
 */
- (void)cancelSearch;

- (void)showPhotoMoments;

- (void)refreshContent;

- (void)performSearchWithQuery:(NSString *)query;

/**
 Navigation view
 */
@property (nonatomic, strong) IBOutlet GFYNavigationView *navigationView;

@end

NS_ASSUME_NONNULL_END

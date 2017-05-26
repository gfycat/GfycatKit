//
//  GFYBrowserViewController.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 1/17/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import "GFYSimpleContainerViewController.h"
#import "GFYBrowserSettings.h"
#import "GFYCategoryPickerViewController.h"
#import "GFYMediaPickerViewController.h"

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
@interface GFYBrowserViewController : GFYSimpleContainerViewController

/**
 Creates new `GFYBrowserViewController` with the settings specified.

 @param settings browser settings
 @return `GFYBrowserViewController` instance
 */
+ (instancetype)browserWithSettings:(id<GFYBrowserSettings> _Nullable)settings;

/**
 Initialized `GFYBrowserViewController` with the settings specified.

 @param settings browser settings
 @return `GFYBrowserViewController` instance
 */
- (instancetype)initWithSettings:(id<GFYBrowserSettings> _Nullable)settings;

/**
 Browser settings
 */
@property (nonatomic, copy) id<GFYBrowserSettings> settings;

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

@end

NS_ASSUME_NONNULL_END

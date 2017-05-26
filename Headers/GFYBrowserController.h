//
//  GFYBrowserController.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 2/24/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <UIKit/UIKit.h>
#import "GFYBrowserSettings.h"
#import "GFYCategoryPickerViewController.h"
#import "GFYMediaPickerViewController.h"
#import "GFYFlagMediaViewController.h"

NS_ASSUME_NONNULL_BEGIN

@class GFYBrowserController;

/**
 The delegate of a `GFYBrowserController` object must adopt the `GFYBrowserControllerDelegate` protocol.
 */
@protocol GFYBrowserControllerDelegate <NSObject, GFYCategoryPickerDelegate, GFYMediaPickerDelegate, GFYFlagMediaViewControllerDelegate>

/**
 <#Description#>

 @param browser <#browser description#>
 @param viewController <#viewController description#>
 */
- (void)gfycatBrowser:(GFYBrowserController *)browser presentViewController:(UIViewController * _Nullable)viewController;

/**
 <#Description#>

 @param browser <#browser description#>
 @param viewController <#viewController description#>
 */
- (void)gfycatBrowser:(GFYBrowserController *)browser presentModalViewController:(UIViewController *)viewController;

/**
 <#Description#>

 @param browser <#browser description#>
 */
- (void)gfycatBrowserDismissModalViewController:(GFYBrowserController *)browser;

/**
 <#Description#>

 @param browser <#browser description#>
 @param active <#active description#>
 */
- (void)gfycatBrowser:(GFYBrowserController *)browser setSearchActive:(BOOL)active;

/**
 <#Description#>

 @param browser <#browser description#>
 @param searchText <#searchText description#>
 */
- (void)gfycatBrowser:(GFYBrowserController *)browser setSearchText:(NSString * _Nullable)searchText;

@end

/**
 <#Description#>
 */
@interface GFYBrowserController : NSObject

/**
 <#Description#>
 */
@property (nonatomic, copy) id<GFYBrowserSettings> settings;

/**
 <#Description#>
 */
@property (nonatomic, weak) id<GFYBrowserControllerDelegate> delegate;

/**
 <#Description#>
 */
- (void)clearAll;

/**
 <#Description#>
 */
- (void)showCategories;

/**
 <#Description#>
 */
- (void)beginSearch;

/**
 <#Description#>
 */
- (void)cancelSearch;

/**
 <#Description#>

 @param query <#query description#>
 */
- (void)updateSearchPreviewWithQuery:(NSString *)query;

/**
 <#Description#>

 @param query <#query description#>
 */
- (void)performSearchWithQuery:(NSString *)query;

@end

NS_ASSUME_NONNULL_END

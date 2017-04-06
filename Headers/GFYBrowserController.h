//
//  GFYBrowserController.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 2/24/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GFYBrowserSettings.h"
#import "GFYCategoryPickerViewController.h"
#import "GFYMediaPickerViewController.h"
#import "GFYFlagMediaViewController.h"

@class GFYBrowserController;

@protocol GFYBrowserControllerDelegate <NSObject, GFYCategoryPickerDelegate, GFYMediaPickerDelegate, GFYFlagMediaViewControllerDelegate>

- (void)gfycatBrowser:(GFYBrowserController *)browser presentViewController:(UIViewController *)viewController;
- (void)gfycatBrowser:(GFYBrowserController *)browser setSearchActive:(BOOL)active;
- (void)gfycatBrowser:(GFYBrowserController *)browser setSearchText:(NSString *)searchText;

@optional

- (void)gfycatBrowser:(GFYBrowserController *)browser requestExpandedState:(BOOL)expanded;

@end

@interface GFYBrowserController : NSObject

@property (nonatomic, copy) id<GFYBrowserSettings> settings;
@property (nonatomic, weak) id<GFYBrowserControllerDelegate> delegate;

- (void)clearAll;
- (void)showCategories;
- (void)beginSearch;
- (void)cancelSearch;
- (void)updateSearchPreviewWithQuery:(NSString *)query;
- (void)performSearchWithQuery:(NSString *)query;

@end

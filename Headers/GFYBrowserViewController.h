//
//  GFYBrowserViewController.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 1/17/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import "GFYSimpleContainerViewController.h"
#import "GFYBrowserSettings.h"
#import "GFYCategoryPickerViewController.h"
#import "GFYMediaPickerViewController.h"

@class GFYBrowserViewController;

typedef void (^GFYBrowserSelectionHandler)(GfycatMedia *item, GfycatCategory *feed);

@protocol GFYBrowserDelegate <NSObject, GFYCategoryPickerDelegate, GFYMediaPickerDelegate>
@optional

- (void)gfycatBrowser:(GFYBrowserViewController *)browser requestExpandedState:(BOOL)expanded;

@end

@interface GFYBrowserViewController : GFYSimpleContainerViewController

+ (instancetype)browserWithSettings:(id<GFYBrowserSettings>)settings;
- (instancetype)initWithSettings:(id<GFYBrowserSettings>)settings;

@property (nonatomic, copy) id<GFYBrowserSettings> settings;
@property (nonatomic, weak) id<GFYBrowserDelegate> delegate;
@property (nonatomic, copy) GFYBrowserSelectionHandler selectionHandler;

@end

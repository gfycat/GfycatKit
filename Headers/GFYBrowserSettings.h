//
//  GFYBrowserSettings.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 2/23/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "GFYCategoryPickerSettings.h"
#import "GFYMediaPickerSettings.h"
#import "GFYFlagMediaViewControllerSettings.h"

NS_SWIFT_NAME(GFYBrowserSettingsProtocol)
@protocol GFYBrowserSettings <NSObject, NSCopying, GFYCategoryPickerSettings, GFYMediaPickerSettings, GFYFlagMediaViewControllerSettings>

@property (nonatomic, assign) BOOL enableSearchHistory;

@end

@interface GFYBrowserSettings : NSObject <GFYBrowserSettings>

+ (void)fillWithDefaults:(id<GFYBrowserSettings>)settings;

@end

//
//  GFYBrowserSettings.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 2/23/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <UIKit/UIKit.h>
#import "GFYCategoryPickerSettings.h"
#import "GFYMediaPickerSettings.h"
#import "GFYSearchHistorySettings.h"
#import "GFYFlagMediaViewControllerSettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 <#Description#>
 */
NS_SWIFT_NAME(GFYBrowserSettingsProtocol)
@protocol GFYBrowserSettings <NSObject, NSCopying, GFYCategoryPickerSettings, GFYMediaPickerSettings, GFYSearchHistorySettings, GFYFlagMediaViewControllerSettings>

/**
 Toggles search history
 */
@property (nonatomic, assign) BOOL enableSearchHistory;

@end

/**
 <#Description#>
 */
@interface GFYBrowserSettings : NSObject <GFYBrowserSettings>

/**
 <#Description#>

 @param settings <#settings description#>
 */
+ (void)fillWithDefaults:(id<GFYBrowserSettings>)settings;

@end

NS_ASSUME_NONNULL_END

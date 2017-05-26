//
//  GfycatKit.h
//  GfycatKit
//
//  Created by Oleksii Chubenko on 4/3/17.
//  Copyright © 2017 Gfycat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <UIKit/UIKit.h>

//! Project version number for GfycatKit.
FOUNDATION_EXPORT double GfycatKitVersionNumber;

//! Project version string for GfycatKit.
FOUNDATION_EXPORT const unsigned char GfycatKitVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <GfycatKit/PublicHeader.h>

// Utils.Common
#import <GfycatKit/GFYArrayDiff.h>
// Utils.UIKit
#import <GfycatKit/UICollectionView+GfycatInterface.h>
#import <GfycatKit/UIColor+GfycatInterface.h>
#import <GfycatKit/UINib+GfycatInterface.h>
#import <GfycatKit/UIScrollView+GfycatInterface.h>
#import <GfycatKit/UITableView+GfycatInterface.h>
#import <GfycatKit/UIView+GfycatInterface.h>
#import <GfycatKit/UIStoryboard+GfycatInterface.h>
// Utils.UICollectionView
#import <GfycatKit/GFYPresenterView.h>
#import <GfycatKit/GFYReusableView.h>
#import <GfycatKit/GFYCollectionViewCell.h>
#import <GfycatKit/GFYCollectionViewManager.h>
// Utils.ViewControllers
#import <GfycatKit/GFYSimpleContainerViewController.h>
// Utils.Views
#import <GfycatKit/GFYActivityGradientBar.h>
#import <GfycatKit/GFYActivityBarIndicator.h>
#import <GfycatKit/GFYBackgroundView.h>
// Providers.Cache
#import <GfycatKit/GfycatApiCache.h>
#import <GfycatKit/GfycatBlackListCache.h>
#import <GfycatKit/GfycatCachedApi.h>
#import <GfycatKit/GfycatInterfaceCache.h>
#import <GfycatKit/GfycatSimpleCache.h>
// Providers.Source
#import <GfycatKit/GFYArraySource.h>
#import <GfycatKit/GFYCategoryMediaArraySource.h>
#import <GfycatKit/GFYRecentMediaArraySource.h>
#import <GfycatKit/GFYSearchMediaArraySource.h>
// Categories
#import <GfycatKit/GfycatMedia+GFYArrangable.h>
#import <GfycatKit/GfycatCategory+GFYArrangable.h>
// Components.Browser
#import <GfycatKit/GFYBrowserSettings.h>
#import <GfycatKit/GFYBrowserController.h>
#import <GfycatKit/GFYBrowserViewController.h>
// Components.CategoryPicker
#import <GfycatKit/GFYCategoryPickerSettings.h>
#import <GfycatKit/GFYCategoryPickerViewController.h>
#import <GfycatKit/GFYRecentCategoryCollectionViewCellModel.h>
// Components.MediaPicker
#import <GfycatKit/GFYMediaPickerSettings.h>
#import <GfycatKit/GFYMediaPickerViewController.h>
// Components.MediaView
#import <GfycatKit/GFYMediaView.h>
// Components.SearchHistory
#import <GfycatKit/GFYSearchHistoryViewController.h>
// Components.Reporting
#import <GfycatKit/GFYFlagMediaViewControllerSettings.h>
#import <GfycatKit/GFYFlagMediaViewController.h>
// Analytics
#import <GfycatKit/GFYAnalyticsHub.h>
#import <GfycatKit/GFYAnalyticsTrackerBase.h>
#import <GfycatKit/GFYInterfaceAnalytics.h>

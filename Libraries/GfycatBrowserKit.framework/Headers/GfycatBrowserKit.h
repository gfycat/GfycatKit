//
//  GfycatBrowserKit.h
//  GfycatBrowserKit
//
//  Created by Oleksii Chubenko on 4/3/17.
//  Copyright © 2017 Gfycat. All rights reserved.
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

//! Project version number for GfycatBrowserKit.
FOUNDATION_EXPORT double GfycatBrowserKitVersionNumber;

//! Project version string for GfycatBrowserKit.
FOUNDATION_EXPORT const unsigned char GfycatBrowserKitVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import "PublicHeader.h"

// Utils.Common
#import "GFYArrayDiff.h"
#import "GFYFilesystemLock.h"
#import "GFYLocalizationManager.h"
#import "GFYGeometryUtils.h"
#import "UIView+GFYInterfaceLocalization.h"
#import "NSFileManager+GfycatInterface.h"
#import "GFYCommonUtils.h"
#import "GFYMulticastDelegate.h"
#import "GFYKeyboardObserver.h"
// Utils.UIKit
#import "UICollectionView+GfycatInterface.h"
#import "UIColor+GfycatInterface.h"
#import "UINavigationItem+GfycatInterface.h"
#import "UINib+GfycatInterface.h"
#import "UIScrollView+GfycatInterface.h"
#import "UITableView+GfycatInterface.h"
#import "UIView+GfycatInterface.h"
#import "UIStoryboard+GfycatInterface.h"
#import "NSBundle+GfycatInterface.h"
#import "UIApplication+GfycatInterface.h"
// Utils.UICollectionView
#import "GFYPresenterView.h"
#import "GFYReusableView.h"
#import "GFYCollectionViewCell.h"
#import "GFYCollectionViewManager.h"
#import "GFYMultiLineFillCollectionViewLayout.h"
// Utils.ViewControllers
#import "GFYSimpleContainerViewController.h"
// Utils.Views
#import "GFYActivityGradientBar.h"
#import "GFYActivityBarIndicator.h"
#import "GFYBackgroundView.h"
// Providers.Cache
#import "GfycatApiCache.h"
#import "GfycatBlackListCache.h"
#import "GfycatCachedApi.h"
#import "GfycatInterfaceCache.h"
#import "GfycatLikesCache.h"
#import "GfycatSimpleCache.h"
// Providers.Source
#import "GFYArraySource.h"
#import "GFYCategoryMediaArraySource.h"
#import "GFYRecentMediaArraySource.h"
#import "GFYSearchMediaArraySource.h"
#import "GFYLikedMediaArraySource.h"
#import "GFYCreatedMediaArraySource.h"
// Categories
#import "GfycatMedia+GFYArrangable.h"
#import "GfycatCategory+GFYArrangable.h"
// Components.Browser
#import "GFYBrowserSettings.h"
#import "GFYBrowserController.h"
#import "GFYBrowserViewController.h"
// Components.CategoryPicker
#import "GFYCategoryPickerSettings.h"
#import "GFYCategoryPickerViewController.h"
#import "GFYRecentCategoryCollectionViewCellModel.h"
#import "GFYCreatedMediaCollectionViewCell.h"
#import "GFYCategoryTitleCollectionViewCell.h"
#import "GFYCategoryTitleCollectionViewCell.h"
// Components.MediaPicker
#import "GFYMediaPickerSettings.h"
#import "GFYMediaPickerViewController.h"
#import "GFYRecentsMediaPickerSettings.h"
#import "GFYRecentsMediaPickerViewController.h"
// Components.MediaView
#import "GFYMediaView.h"
// Components.SearchHistory
#import "GFYSearchHistoryViewController.h"
// Components.Reporting
#import "GFYFlagMediaViewControllerSettings.h"
#import "GFYFlagMediaViewController.h"
// Components.NavigationView
#import "GFYNavigationViewDefinitions.h"
#import "GFYNavigationViewTabModel.h"
#import "GFYNavigationView.h"
// Components.Creation
// Components.VideoPlayerView
#import "GFYVideoPlayerView.h"
// Analytics
#import "GFYAnalyticsHub.h"
#import "GFYAnalyticsTrackerBase.h"
#import "GFYInterfaceAnalytics.h"
// Account
#import "GFYAccountManager.h"
// Ads
#import "GFYAdViewPlacement.h"
#import "GFYAdsManagerWrapper.h"

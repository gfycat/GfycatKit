//
//  SearchHistoryViewController.h
//  GfycatKit
//
//  Created by Oleksii Chubenko on 8/31/16.
//  Copyright © 2016 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <UIKit/UIKit.h>
#import "GFYSearchHistorySettings.h"

NS_ASSUME_NONNULL_BEGIN

@class GFYSearchHistoryViewController;

/**
 The delegate of a `GFYSearchHistoryViewController` object must adopt the `GFYSearchHistoryViewControllerDelegate` protocol.
 */
@protocol GFYSearchHistoryViewControllerDelegate <NSObject>

/**
 <#Description#>

 @param viewController <#viewController description#>
 @param searchTerm <#searchTerm description#>
 */
- (void)gfySearchHistory:(GFYSearchHistoryViewController *)viewController didSelectSearchTerm:(NSString *)searchTerm;

@end

/**
 <#Description#>
 */
@interface GFYSearchHistoryViewController: UIViewController

/**
 <#Description#>

 @param settings <#settings description#>
 @return <#return value description#>
 */
+ (instancetype)historyWithSettings:(id<GFYSearchHistorySettings> _Nullable)settings;

/**
 <#Description#>

 @param settings <#settings description#>
 @return <#return value description#>
 */
- (instancetype)initWithSettings:(id<GFYSearchHistorySettings> )settings;

/**
 <#Description#>
 */
@property (nonatomic, copy) id<GFYSearchHistorySettings> settings;

/**
 <#Description#>
 */
@property (nonatomic, weak) id<GFYSearchHistoryViewControllerDelegate> delegate;

/**
 <#Description#>
 */
@property (nonatomic, readonly) UITableView *tableView;

@end

NS_ASSUME_NONNULL_END

//
//  SearchHistoryViewController.h
//  Gfycat
//
//  Created by Oleksii Chubenko on 8/31/16.
//  Copyright © 2016 GfyCat. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GfycatInterfaceCache.h"

@class GFYSearchHistoryViewController;

@protocol GFYSearchHistoryViewControllerDelegate <NSObject>

- (void)gfySearchHistory:(GFYSearchHistoryViewController *)viewController didSelectSearchTerm:(NSString *)searchTerm;

@end

@interface GFYSearchHistoryViewController: UIViewController

+ (instancetype)historyWithSettings:(id)settings;
- (instancetype)initWithSettings:(id)settings;

@property (nonatomic, strong) id<GfycatInterfaceCache> interfaceCache;
@property (nonatomic, weak)   id<GFYSearchHistoryViewControllerDelegate> delegate;

@property (nonatomic, readonly) UITableView *tableView;

@end

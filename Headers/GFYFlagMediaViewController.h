//
//  GFYFlagMediaViewController.h
//  GfycatKit
//
//  Created by Oleksii Chubenko on 3/31/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <UIKit/UIKit.h>
#import <GfycatApiKit/GfycatApiKit.h>
#import "GFYFlagMediaViewControllerSettings.h"

NS_ASSUME_NONNULL_BEGIN

@class GFYFlagMediaViewController;

/**
 The delegate of a `GFYFlagMediaViewController` object must adopt the `GFYFlagMediaViewControllerDelegate` protocol.
 */
@protocol GFYFlagMediaViewControllerDelegate <NSObject>
@optional

/**
 <#Description#>

 @param flagController <#flagController description#>
 */
- (void)gfycatFlagMediaViewControllerDidCancel:(GFYFlagMediaViewController *)flagController;

/**
 <#Description#>

 @param flagController <#flagController description#>
 */
- (void)gfycatFlagMediaViewControllerDidFlag:(GFYFlagMediaViewController *)flagController;

@end

/**
 <#Description#>
 */
@interface GFYFlagMediaViewController : UIViewController

/**
 <#Description#>

 @param settings <#settings description#>
 @return <#return value description#>
 */
+ (instancetype)gfycatFlagMediaViewControllerSettings:(id<GFYFlagMediaViewControllerSettings> _Nullable)settings;

/**
 <#Description#>

 @param settings <#settings description#>
 @return <#return value description#>
 */
- (instancetype)initWithSettings:(id<GFYFlagMediaViewControllerSettings> _Nullable)settings;

/**
 <#Description#>
 */
@property (nonatomic, copy) id<GFYFlagMediaViewControllerSettings> settings;

/**
 <#Description#>
 */
@property (nonatomic, weak) id<GFYFlagMediaViewControllerDelegate> delegate;

/**
 <#Description#>
 */
@property (nonatomic, strong) GfycatMedia *media;

@end

NS_ASSUME_NONNULL_END

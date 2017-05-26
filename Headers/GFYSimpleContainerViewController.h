//
//  GFYSimpleContainerViewController.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 1/17/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Basic container view controller to display single child.
 */
@interface GFYSimpleContainerViewController : UIViewController

/**
 Container view to be used as a host for child view controller's view.
 */
@property (nonatomic, strong, nullable) IBOutlet UIView *containerView;

/**
 Active view controller.
 */
@property (nonatomic, strong, nullable) IBOutlet UIViewController *activeViewController;

/**
 Changes active view controller with an optional animation.

 @param newViewController View controller to present.
 @param animated Indicates if the transition should be animated.
 */
- (void)setActiveViewController:(UIViewController * _Nullable)newViewController animated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END

//
//  GFYPresenterView.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 1/15/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Generic data presenter view
 */
@protocol GFYPresenterView <NSObject>

/**
 Presents new view model.

 @param model View model to present.
 @param animated Indicates if the update should be animated.
 */
- (void)present:(id)model animated:(BOOL)animated;

@optional

/**
 Called by a container when view is about to be presented.
 */
- (void)willDisplay;

/**
 Called by a container after view is hidden.
 */
- (void)didEndDisplaying;

@end

NS_ASSUME_NONNULL_END

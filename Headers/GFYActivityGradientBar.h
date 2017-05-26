//
//  GFYActivityGradientBar.h
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
 Activity indicator bar view.
 Use UIAppearance to customize look of the bars in GfycatKit interface.
 */
IB_DESIGNABLE
@interface GFYActivityGradientBar : UIView

/**
 Primary color of the gradient.
 */
@property (nonatomic, strong, nullable) IBInspectable UIColor *primaryColor;

/**
 Secondary color of the gradient.
 */
@property (nonatomic, strong, nullable) IBInspectable UIColor *secondaryColor;

/**
 Current status of the animation.
 */
@property (nonatomic, assign) IBInspectable BOOL active;

@end

NS_ASSUME_NONNULL_END

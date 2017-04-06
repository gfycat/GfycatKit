//
//  GFYActivityGradientBar.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 1/15/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <UIKit/UIKit.h>

IB_DESIGNABLE
@interface GFYActivityGradientBar : UIView

@property (nonatomic, strong) IBInspectable UIColor *primaryColor;
@property (nonatomic, strong) IBInspectable UIColor *secondaryColor;

@property (nonatomic, assign) IBInspectable BOOL active;

@end

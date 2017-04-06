//
//  UIColor+GfycatInterface.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 3/24/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (GfycatInterface)

+ (UIColor *)gfy_colorWithRgb:(uint32_t)rgb NS_SWIFT_NAME(init(gfy_rgb:));
+ (UIColor *)gfy_colorWithRgb:(uint32_t)rgb opacity:(CGFloat)opacity NS_SWIFT_NAME(init(gfy_rgb:opacity:));
+ (UIColor *)gfy_colorWithRgba:(uint32_t)rgba NS_SWIFT_NAME(init(gfy_rgba:));
+ (UIColor *)gfy_colorWithString:(NSString *)colorString NS_SWIFT_NAME(init(gfy_string:));

@end

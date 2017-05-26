//
//  UIColor+GfycatInterface.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 3/24/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (GfycatInterface)

/**
 <#Description#>

 @param rgb <#rgb description#>
 @return <#return value description#>
 */
+ (UIColor *)gfy_colorWithRgb:(uint32_t)rgb NS_SWIFT_NAME(init(gfy_rgb:));

/**
 <#Description#>

 @param rgb <#rgb description#>
 @param opacity <#opacity description#>
 @return <#return value description#>
 */
+ (UIColor *)gfy_colorWithRgb:(uint32_t)rgb opacity:(CGFloat)opacity NS_SWIFT_NAME(init(gfy_rgb:opacity:));

/**
 <#Description#>

 @param rgba <#rgba description#>
 @return <#return value description#>
 */
+ (UIColor *)gfy_colorWithRgba:(uint32_t)rgba NS_SWIFT_NAME(init(gfy_rgba:));

/**
 <#Description#>

 @param colorString <#colorString description#>
 @return <#return value description#>
 */
+ (nullable UIColor *)gfy_colorWithString:(NSString *)colorString NS_SWIFT_NAME(init(gfy_string:));

@end

NS_ASSUME_NONNULL_END

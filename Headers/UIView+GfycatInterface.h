//
//  UIView+GfycatInterface.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 3/31/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (GfycatInterface)

/**
 <#Description#>

 @param animate <#animate description#>
 @param duration <#duration description#>
 @param animations <#animations description#>
 */
+ (void)gfy_animate:(BOOL)animate withDuration:(NSTimeInterval)duration animations:(void(^)(void))animations;

/**
 <#Description#>

 @param animate <#animate description#>
 @param duration <#duration description#>
 @param animations <#animations description#>
 @param completion <#completion description#>
 */
+ (void)gfy_animate:(BOOL)animate withDuration:(NSTimeInterval)duration animations:(void(^)(void))animations completion:(void(^)(BOOL))completion;

/**
 <#Description#>
 */
+ (instancetype _Nullable)gfy_loadFromDefaultNib;

@end

NS_ASSUME_NONNULL_END

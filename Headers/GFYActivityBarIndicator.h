//
//  GFYActivityBarIndicator.h
//  GfycatKit
//
//  Created by Yin Zhu on 2/16/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 <#Description#>
 */
@interface GFYActivityBarIndicator : NSObject

/**
 <#Description#>

 @return <#return value description#>
 */
+ (instancetype)sharedIndicator;

/**
 <#Description#>

 @param view <#view description#>
 */
- (void)showInView:(UIView *)view;

/**
 <#Description#>
 */
- (void)hide;

/**
 <#Description#>

 @param delay <#delay description#>
 */
- (void)hideAfterDelay:(NSTimeInterval)delay;

/**
 <#Description#>
 */
@property (nonatomic, readonly, getter=isHidden) BOOL hidden;

@end

NS_ASSUME_NONNULL_END

//
//  GFYActivityBarIndicator.h
//  Gfycat
//
//  Created by Yin Zhu on 2/16/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface GFYActivityBarIndicator : NSObject

+ (instancetype)sharedIndicator;

- (void)showInView:(UIView *)view;
- (void)hide;
- (void)hideAfterDelay:(NSTimeInterval)delay;

@property (nonatomic, readonly, getter=isHidden) BOOL hidden;

@end

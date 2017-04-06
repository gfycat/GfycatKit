//
//  GFYPresenterView.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 1/15/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol GFYPresenterView <NSObject>

- (void)present:(id)model animated:(BOOL)animated;

@optional

- (void)willDisplay;
- (void)didEndDisplaying;

@end

//
//  UIScrollView+GfycatInterface.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 3/16/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIScrollView (GfycatInterface)

- (void)gfy_setContentInset:(UIEdgeInsets)contentInset
             topLayoutGuide:(id<UILayoutSupport>)topLayoutGuide
          bottomLayoutGuide:(id<UILayoutSupport>)bottomLayoutGuide;

@end

//
//  UIScrollView+GfycatInterface.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 3/16/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIScrollView (GfycatInterface)

/**
 <#Description#>

 @param contentInset <#contentInset description#>
 @param topLayoutGuide <#topLayoutGuide description#>
 @param bottomLayoutGuide <#bottomLayoutGuide description#>
 */
- (void)gfy_setContentInset:(UIEdgeInsets)contentInset
             topLayoutGuide:(id<UILayoutSupport>)topLayoutGuide
          bottomLayoutGuide:(id<UILayoutSupport>)bottomLayoutGuide;

@end

NS_ASSUME_NONNULL_END

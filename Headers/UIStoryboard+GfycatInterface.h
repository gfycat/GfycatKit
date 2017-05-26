//
//  UIStoryboard+GfycatInterface.h
//  GfycatKit
//
//  Created by Andrii Novoselskyi on 5/25/17.
//  Copyright © 2017 Gfycat. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIStoryboard (GfycatInterface)

/**
 <#Description#>
 
 @return <#return value description#>
 */
+ (instancetype _Nullable)gfy_storyboardForClass:(Class)cls NS_SWIFT_NAME(init(gfy_class:));

@end

NS_ASSUME_NONNULL_END

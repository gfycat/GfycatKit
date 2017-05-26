//
//  UINib+GfycatInterface.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 1/15/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UINib (GfycatInterface)

/**
 <#Description#>

 @param cls <#cls description#>
 @return <#return value description#>
 */
+ (instancetype _Nullable)gfy_nibForClass:(Class)cls NS_SWIFT_NAME(init(gfy_class:));

/**
 <#Description#>

 @param cls <#cls description#>
 @return <#return value description#>
 */
+ (NSString * _Nullable)gfy_nibNameForClass:(Class)cls;

/**
 <#Description#>

 @param cls <#cls description#>
 @return <#return value description#>
 */
+ (NSBundle * _Nullable)gfy_nibBundleForClass:(Class)cls;

@end

NS_ASSUME_NONNULL_END

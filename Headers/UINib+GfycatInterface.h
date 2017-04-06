//
//  UINib+GfycatInterface.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 1/15/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UINib (GfycatInterface)

+ (instancetype)gfy_nibForClass:(Class)cls;

+ (NSString *)gfy_nibNameForClass:(Class)cls;
+ (NSBundle *)gfy_nibBundleForClass:(Class)cls;

@end

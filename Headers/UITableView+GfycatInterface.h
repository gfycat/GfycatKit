//
//  UITableView+GfycatInterface.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 3/16/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UITableView (GfycatInterface)

/**
 <#Description#>

 @param cellClass <#cellClass description#>
 */
- (void)gfy_registerCellClass:(Class)cellClass;

/**
 <#Description#>

 @param cellClass <#cellClass description#>
 @param indexPath <#indexPath description#>
 @return <#return value description#>
 */
- (id)gfy_dequeueReusableCellWithClass:(Class)cellClass forIndexPath:(NSIndexPath *)indexPath;

@end

NS_ASSUME_NONNULL_END

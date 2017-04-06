//
//  UITableView+GfycatInterface.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 3/16/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIScrollView+GfycatInterface.h"

@interface UITableView (GfycatInterface)

- (void)gfy_registerCellClass:(Class)cellClass;

- (id)gfy_dequeueReusableCellWithClass:(Class)cellClass forIndexPath:(NSIndexPath *)indexPath;

@end

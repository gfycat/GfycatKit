//
//  UICollectionView+GfycatInterface.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 1/15/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIScrollView+GfycatInterface.h"

@interface UICollectionView (GfycatInterface)

@property (nonatomic, getter=gfy_isPrefetchingEnabled, setter=gfy_setPrefetchingEnabled:) BOOL gfy_prefetchingEnabled;

- (void)gfy_registerCellClass:(Class)cellClass;
- (void)gfy_registerSupplementaryViewClass:(Class)cellClass ofKind:(NSString *)kind;

- (id)gfy_dequeueReusableCellWithClass:(Class)cellClass forIndexPath:(NSIndexPath *)indexPath;
- (id)gfy_dequeueReusableSupplementaryViewClass:(Class)viewClass ofKind:(NSString *)kind forIndexPath:(NSIndexPath *)indexPath;

@end

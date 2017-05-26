//
//  UICollectionView+GfycatInterface.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 1/15/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UICollectionView (GfycatInterface)

/**
 <#Description#>
 */
@property (nonatomic, getter=gfy_isPrefetchingEnabled, setter=gfy_setPrefetchingEnabled:) BOOL gfy_prefetchingEnabled;

/**
 <#Description#>

 @param cellClass <#cellClass description#>
 */
- (void)gfy_registerCellClass:(Class)cellClass;

/**
 <#Description#>

 @param cellClass <#cellClass description#>
 @param kind <#kind description#>
 */
- (void)gfy_registerSupplementaryViewClass:(Class)cellClass ofKind:(NSString *)kind;

/**
 <#Description#>

 @param cellClass <#cellClass description#>
 @param indexPath <#indexPath description#>
 @return <#return value description#>
 */
- (id)gfy_dequeueReusableCellWithClass:(Class)cellClass forIndexPath:(NSIndexPath *)indexPath;

/**
 <#Description#>

 @param viewClass <#viewClass description#>
 @param kind <#kind description#>
 @param indexPath <#indexPath description#>
 @return <#return value description#>
 */
- (id)gfy_dequeueReusableSupplementaryViewClass:(Class)viewClass ofKind:(NSString *)kind forIndexPath:(NSIndexPath *)indexPath;

@end

NS_ASSUME_NONNULL_END

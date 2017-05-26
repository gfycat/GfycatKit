//
//  GFYCollectionViewCell.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 1/15/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <UIKit/UIKit.h>
#import "GFYPresenterView.h"
#import "GFYReusableView.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Abstract collection view cell protocol.
 */
NS_SWIFT_NAME(GFYCollectionViewCellProtocol)
@protocol GFYCollectionViewCell <NSObject, GFYPresenterView, GFYReusableView>
@optional

/**
 Calculates size of the cell presenting a model.

 @param model Model to be inspected.
 @return Size of a cell on screen.
 */
+ (CGSize)sizeForModel:(id)model;

/**
 Calculates size of the cell presenting a model.

 @param model Model to be inspected.
 @param itemWidth Cell width as computed by a conteiner.
 @return Cell height.
 */
+ (CGFloat)heightForModel:(id)model width:(CGFloat)itemWidth;

/**
 Calculates size of the cell presenting a model.

 @param model Model to be inspected.
 @param itemHeight Cell height as computed by a conteiner.
 @return Cell width.
 */
+ (CGFloat)widthForModel:(id)model height:(CGFloat)itemHeight;

/**
 Library calls `playSelectAnimation` method each time a user taps an item view on screen.
 Use this method to customize a selection feedback animation to match your design.
 
 The default implementation plays a bouncing zoom animation.
 */
- (void)playSelectAnimation;

@end

/**
 Base class for collection view cells used by GfycatKit.
 */
@interface GFYCollectionViewCell<Model> : UICollectionViewCell <GFYCollectionViewCell>

/**
 View model of the cell.
 */
@property (nonatomic, readonly, null_unspecified) Model model;

/**
 Cell presentation status.
 */
@property (nonatomic, assign) BOOL presented;

/**
 Presents new view model.
 
 @param model View model to present.
 */
- (void)present:(Model)model NS_REQUIRES_SUPER;

/**
 Presents new view model.
 
 @param model View model to present.
 @param animated Indicates if the update should be animated.
 */
- (void)present:(Model)model animated:(BOOL)animated NS_REQUIRES_SUPER;

@end

NS_ASSUME_NONNULL_END

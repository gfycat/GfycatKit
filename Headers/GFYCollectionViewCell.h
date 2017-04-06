//
//  GFYCollectionViewCell.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 1/15/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GFYPresenterView.h"
#import "GFYReusableView.h"

NS_SWIFT_NAME(GFYCollectionViewCellProtocol)
@protocol GFYCollectionViewCell <NSObject, GFYPresenterView, GFYReusableView>

@optional

+ (CGSize)sizeForModel:(id)model;
+ (CGFloat)heightForModel:(id)model width:(CGFloat)itemWidth;
+ (CGFloat)widthForModel:(id)model height:(CGFloat)itemHeight;

- (void)playSelectAnimation;

@end

@interface GFYCollectionViewCell<Model> : UICollectionViewCell <GFYCollectionViewCell>

@property (nonatomic, readonly) Model model;
@property (nonatomic, assign)   BOOL presented;

- (void)present:(Model)model NS_REQUIRES_SUPER;
- (void)present:(Model)model animated:(BOOL)animated NS_REQUIRES_SUPER;

@end

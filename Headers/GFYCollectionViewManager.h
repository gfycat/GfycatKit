//
//  GFYCollectionViewManager.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 1/15/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <UIKit/UIKit.h>
#import "GFYArrayDiff.h"
#import "GFYCollectionViewCell.h"

NS_ASSUME_NONNULL_BEGIN

@protocol GFYCollectionViewDelegate <NSObject>
@optional

- (void)collectionView:(UICollectionView *)collectionView customizeView:(UICollectionViewCell *)cell forModel:(id)model atIndexPath:(NSIndexPath *)indexPath;
- (void)collectionView:(UICollectionView *)collectionView didSelectModel:(id)model atIndexPath:(NSIndexPath *)indexPath;
- (void)collectionView:(UICollectionView *)collectionView willDisplayModel:(id)model atIndexPath:(NSIndexPath *)indexPath;
- (void)collectionView:(UICollectionView *)collectionView willDisplayCell:(UICollectionViewCell *)cell withModel:(id)model atIndexPath:(NSIndexPath *)indexPath;
- (void)collectionView:(UICollectionView *)collectionView didEndDisplayingModel:(id)model atIndexPath:(NSIndexPath *)indexPath;
- (NSInteger)collectionView:(UICollectionView *)collectionView gridSizeForSection:(NSInteger)section;

- (void)scrollViewWillBeginDragging:(UIScrollView *)scrollView;
- (void)scrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate;
- (void)scrollViewDidEndDecelerating:(UIScrollView *)scrollView;
- (void)scrollViewDidScroll:(UIScrollView *)scrollView;
- (void)scrollViewDidScrollToTop:(UIScrollView *)scrollView;

@end

IB_DESIGNABLE
@interface GFYCollectionViewManager : NSObject

@property (nonatomic, assign) IBInspectable NSInteger gridSize;
@property (nonatomic, assign) IBInspectable CGSize cellAspectRatio;

@property (nonatomic, strong) IBOutlet UICollectionView *collectionView;
@property (nonatomic, weak) IBOutlet id<GFYCollectionViewDelegate> delegate;

@property (nonatomic, copy, nullable) NSArray<NSArray<id<GFYArrangable>> *> *model;
@property (nonatomic, copy, nullable) void (^selectionHandler)(id model, NSIndexPath *indexPath);

- (void)registerCellClass:(Class<GFYCollectionViewCell>)cellClass forModelClass:(Class)modelClass;
- (void)registerCellClassMapping:(NSDictionary<Class, Class<GFYCollectionViewCell>> *)mapping;

- (void)willAppear;
- (void)didAppear;
- (void)willDisappear;
- (void)didDisappear;
- (void)willLayoutSubviews;
- (void)didLayoutSubviews;

@end

NS_ASSUME_NONNULL_END

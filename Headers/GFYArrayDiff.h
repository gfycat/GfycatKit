//
//  GFYArrayDiff.h
//  GfycatKit
//
//  Created by Victor on 18.08.15.
//  Copyright (c) 2015 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 `GFYArrangable` protocol defines two properties that describes how items are rearranged in a collection view.
 
 A trivial implementation will return `self` or some kind of object identifier for both properties.
 */
@protocol GFYArrangable <NSObject, NSCopying>

/**
 Uniquely identifies an item, library relies on its equality to properly animate item rearrangement
 */
@property (nonatomic, readonly) id<NSObject, NSCopying> modelIdentity;

/**
 Identifies item visual state, library relies on its equality to animate item reloading as needed
 */
@property (nonatomic, readonly) id<NSObject, NSCopying> presentationIdentity;

@end

/**
 <#Description#>
 */
@interface GFYArrayDiffMove : NSObject

/**
 <#Description#>
 */
@property (nonatomic, readonly, assign) NSInteger from;

/**
 <#Description#>
 */
@property (nonatomic, readonly, assign) NSInteger to;

/**
 <#Description#>
 */
@property (nonatomic, readonly, assign) BOOL reload;

/**
 <#Description#>

 @param from <#from description#>
 @param to <#to description#>
 @param reload <#reload description#>
 @return <#return value description#>
 */
+ (instancetype)moveFrom:(NSInteger)from to:(NSInteger)to reload:(BOOL)reload;

@end

@interface GFYArrayDiff : NSObject

/**
 <#Description#>

 @param oldArray <#oldArray description#>
 @param newArray <#newArray description#>
 @return <#return value description#>
 */
+ (instancetype)differenceBetween:(NSArray<id<GFYArrangable>> *)oldArray and:(NSArray<id<GFYArrangable>> *)newArray;

/**
 <#Description#>

 @param oldList <#oldList description#>
 @param newList <#newList description#>
 @param keyForItem <#keyForItem description#>
 @param itemsAreEqual <#itemsAreEqual description#>
 @return <#return value description#>
 */
+ (instancetype)differenceBetween:(NSArray *)oldList
                              and:(NSArray *)newList
                    usingKeyBlock:(id (^)(id))keyForItem
                      andComparer:(BOOL (^)(id, id))itemsAreEqual __attribute__ ((deprecated("remove legacy code")));


/**
 <#Description#>
 */
@property (nonatomic, readonly) NSArray<NSNumber *> *deleteItems;

/**
 <#Description#>
 */
@property (nonatomic, readonly) NSArray<NSNumber *> *insertItems;

/**
 <#Description#>
 */
@property (nonatomic, readonly) NSArray<NSNumber *> *reloadItems;

/**
 <#Description#>
 */
@property (nonatomic, readonly) NSArray<GFYArrayDiffMove *> *moveItems;

/**
 <#Description#>
 */
@property (nonatomic, readonly, getter=isEmpty) BOOL empty;

@end

@interface UICollectionView (GFYArrangable)

/**
 <#Description#>

 @param section <#section description#>
 @param diff <#diff description#>
 */
- (void)gfy_moveInsertDeleteItemsInSection:(NSInteger)section withDifferece:(GFYArrayDiff *)diff;

/**
 <#Description#>

 @param section <#section description#>
 @param diff <#diff description#>
 */
- (void)gfy_reloadItemsInSection:(NSInteger)section withDifferece:(GFYArrayDiff *)diff;

@end

@interface UITableView (GFYArrangable)

/**
 <#Description#>

 @param section <#section description#>
 @param diff <#diff description#>
 @param rowAnimation <#rowAnimation description#>
 */
- (void)gfy_moveInsertDeleteItemsInSection:(NSInteger)section withDifferece:(GFYArrayDiff *)diff rowAnimation:(UITableViewRowAnimation)rowAnimation;

/**
 <#Description#>

 @param section <#section description#>
 @param diff <#diff description#>
 @param rowAnimation <#rowAnimation description#>
 */
- (void)gfy_reloadItemsInSection:(NSInteger)section withDifferece:(GFYArrayDiff *)diff rowAnimation:(UITableViewRowAnimation)rowAnimation;

@end

NS_ASSUME_NONNULL_END

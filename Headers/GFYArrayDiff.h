//
//  GFYArrayDiff.h
//  Gfycat
//
//  Created by Victor on 18.08.15.
//  Copyright (c) 2015 GfyCat. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol GFYArrangable

@property (nonatomic, readonly) id modelIdentity;
@property (nonatomic, readonly) id presentationIdentity;

@end

@interface GFYArrayDiffMove : NSObject

@property (nonatomic, readonly, assign) NSInteger from;
@property (nonatomic, readonly, assign) NSInteger to;
@property (nonatomic, readonly, assign) BOOL      reload;

+ (instancetype)moveFrom:(NSInteger)from to:(NSInteger)to reload:(BOOL)reload;

@end

@interface GFYArrayDiff : NSObject

+ (instancetype)differenceBetween:(NSArray<id<GFYArrangable>> *)oldArray and:(NSArray<id<GFYArrangable>> *)newArray;
+ (instancetype)differenceBetween:(NSArray *)oldList
                              and:(NSArray *)newList
                    usingKeyBlock:(id (^)(id))keyForItem
                      andComparer:(BOOL (^)(id, id))itemsAreEqual __attribute__ ((deprecated("remove legacy code")));


@property (nonatomic, readonly) NSArray<NSNumber *> *deleteItems;
@property (nonatomic, readonly) NSArray<NSNumber *> *insertItems;
@property (nonatomic, readonly) NSArray<NSNumber *> *reloadItems;
@property (nonatomic, readonly) NSArray<GFYArrayDiffMove *> *moveItems;

@property (nonatomic, readonly, getter=isEmpty) BOOL empty;

@end

@interface UICollectionView (GFYArrangable)

- (void)moveInsertDeleteItemsInSection:(NSInteger)section withDifferece:(GFYArrayDiff *)diff;
- (void)reloadItemsInSection:(NSInteger)section withDifferece:(GFYArrayDiff *)diff;

@end

@interface UITableView (GFYArrangable)

- (void)moveInsertDeleteItemsInSection:(NSInteger)section withDifferece:(GFYArrayDiff *)diff rowAnimation:(UITableViewRowAnimation)rowAnimation;
- (void)reloadItemsInSection:(NSInteger)section withDifferece:(GFYArrayDiff *)diff rowAnimation:(UITableViewRowAnimation)rowAnimation;

@end

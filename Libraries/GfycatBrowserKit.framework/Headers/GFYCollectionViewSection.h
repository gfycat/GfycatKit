//
//  GFYCollectionViewSection.h
//  GfycatBrowserKit
//
//  Created by Victor Pavlychko on 11/24/17.
//  Copyright © 2017 Gfycat. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GFYArrayDiff.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSString *GFYCollectionViewSectionIdentifier NS_EXTENSIBLE_STRING_ENUM;
extern const GFYCollectionViewSectionIdentifier GFYCollectionViewSectionIdentifierAd;
extern const GFYCollectionViewSectionIdentifier GFYCollectionViewSectionIdentifierTitle;
extern const GFYCollectionViewSectionIdentifier GFYCollectionViewSectionIdentifierContent;

@protocol GFYCollectionViewSection <GFYArrangable>

@property (nonatomic, readonly, copy) NSArray<id<GFYArrangable>> *items;
@property (nonatomic, readonly, copy) GFYCollectionViewSectionIdentifier identifier;
@property (nonatomic, readonly, assign) NSInteger gridSize;
@property (nonatomic, readonly, assign) CGSize cellAspectRatio;

@end

@interface GFYCollectionViewSectionArray: NSObject <GFYCollectionViewSection, NSCopying, NSMutableCopying>

+ (instancetype)sectionWithIdentifier:(GFYCollectionViewSectionIdentifier)identifier;
+ (instancetype)sectionWithIdentifier:(GFYCollectionViewSectionIdentifier)identifier item:(id<GFYArrangable>)item;
+ (instancetype)sectionWithIdentifier:(GFYCollectionViewSectionIdentifier)identifier items:(NSArray<id<GFYArrangable>> *)items;

- (instancetype)initWithIdentifier:(GFYCollectionViewSectionIdentifier)identifier items:(NSArray<id<GFYArrangable>> *)items;

@property (nonatomic, readonly, copy) NSArray<id<GFYArrangable>> *items;
@property (nonatomic, readonly, copy) GFYCollectionViewSectionIdentifier identifier;
@property (nonatomic, readonly, assign) NSInteger gridSize;
@property (nonatomic, readonly, assign) CGSize cellAspectRatio;

@end

@interface GFYMutableCollectionViewSectionArray: GFYCollectionViewSectionArray

@property (nonatomic, readwrite, copy) NSArray<id<GFYArrangable>> *items;
@property (nonatomic, readwrite, copy) GFYCollectionViewSectionIdentifier identifier;
@property (nonatomic, readwrite, assign) NSInteger gridSize;
@property (nonatomic, readwrite, assign) CGSize cellAspectRatio;

@end

NS_ASSUME_NONNULL_END

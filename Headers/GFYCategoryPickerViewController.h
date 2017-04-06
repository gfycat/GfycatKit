//
//  GFYCategoryPickerViewController.h
//  Gfycat
//
//  Created by Victor Pavlychko on 1/15/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GfycatApiKit/GfycatApiKit.h>
#import "GFYCategoryPickerSettings.h"

@class GFYCategoryPickerViewController;

@protocol GFYCategoryPickerDelegate <NSObject>
@optional

- (void)gfycatCategoryPicker:(GFYCategoryPickerViewController *)picker didSelectCategory:(GfycatCategory *)category;
- (void)gfycatCategoryPicker:(GFYCategoryPickerViewController *)picker didSelectItem:(id)model;
- (void)gfycatCategoryPicker:(GFYCategoryPickerViewController *)picker setActivityIndicatorActive:(BOOL)active;
- (NSArray<NSArray *> *)gfycatCategoryPicker:(GFYCategoryPickerViewController *)picker customizeModel:(NSArray<NSArray *> *)model;
- (NSInteger)gfycatCategoryPicker:(GFYCategoryPickerViewController *)picker gridSizeForSection:(NSInteger)section;

@end

@interface GFYCategoryPickerViewController : UIViewController

+ (instancetype)pickerWithSettings:(id<GFYCategoryPickerSettings>)settings;
- (instancetype)initWithSettings:(id<GFYCategoryPickerSettings>)settings;

@property (nonatomic, copy) id<GFYCategoryPickerSettings> settings;
@property (nonatomic, weak) id<GFYCategoryPickerDelegate> delegate;

@property (nonatomic, copy) NSString *filter;
@property (nonatomic, readonly) GfycatCategories *categories;

@property (nonatomic, readonly) UICollectionView *collectionView;

- (void)refreshModelCustomization;
- (BOOL)hasCategoryStartingWith:(NSString *)prefix;

@end

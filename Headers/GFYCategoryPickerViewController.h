//
//  GFYCategoryPickerViewController.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 1/15/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <UIKit/UIKit.h>
#import <GfycatApiKit/GfycatApiKit.h>
#import "GFYCategoryPickerSettings.h"

NS_ASSUME_NONNULL_BEGIN

@class GFYCategoryPickerViewController;

/**
 The delegate of a `GFYCategoryPickerViewController` object must adopt the `GFYCategoryPickerDelegate` protocol.
 */
@protocol GFYCategoryPickerDelegate <NSObject>
@optional

/**
 Delegate method `gfycatCategoryPicker:didSelectCategory:` is called by `GFYCategoryPickerViewController` when user taps
 the category item in the list.

 If this methiod is not implemented, `GFYCategoryPickerViewController` will proceed with calling the
 `gfycatCategoryPicker:didSelectItem:` method.

 @param picker <#picker description#>
 @param category <#category description#>
 */
- (void)gfycatCategoryPicker:(GFYCategoryPickerViewController *)picker didSelectCategory:(GfycatCategory *)category;

/**
 Delegate method `gfycatCategoryPicker:didSelectItem:` is called by the `GFYCategoryPickerViewController` when the user taps
 a custom item in the category list.
 
 If this method is not implemented, the user interaction is ignored.

 @param picker <#picker description#>
 @param model <#model description#>
 */
- (void)gfycatCategoryPicker:(GFYCategoryPickerViewController *)picker didSelectItem:(id)model;

/**
 Delegate method `gfycatCategoryPicker:setActivityIndicatorActive:` is called by `GFYCategoryPickerViewController` when
 network activity is happening to allow the host application to display a custom progress indicator.
 
 If this method is not implemented, the default indicator is displayed.

 @param picker <#picker description#>
 @param active <#active description#>
 */
- (void)gfycatCategoryPicker:(GFYCategoryPickerViewController *)picker setActivityIndicatorActive:(BOOL)active;

/**
 The host application implements `gfycatCategoryPicker:customizeModel:` delegate method to modify category picker contents with custom items.
 
 The collection view model is represented as an array of arrays of models representing section and items correspondingly.
 
 All item models should conform to `GFYArrangable` and `NSCopying` protocols.

 @param picker <#picker description#>
 @param model <#model description#>
 @return <#return value description#>
 */
- (NSArray<NSArray *> *)gfycatCategoryPicker:(GFYCategoryPickerViewController *)picker customizeModel:(NSArray<NSArray *> *)model;

/**
 Delegate method `gfycatCategoryPicker:gridSizeForSection:` is called by `GFYCategoryPickerViewController` to get the number of rows or columns for each section. This may be useful in conjuction with model customization.

 @param picker <#picker description#>
 @param section <#section description#>
 @return <#return value description#>
 */
- (NSInteger)gfycatCategoryPicker:(GFYCategoryPickerViewController *)picker gridSizeForSection:(NSInteger)section;

@end

/**
 `GFYCategoryPickerViewController` provides a convenient interface to pick categories from Gfycat.
 */
@interface GFYCategoryPickerViewController : UIViewController

/**
 <#Description#>

 @param settings <#settings description#>
 @return <#return value description#>
 */
+ (instancetype)pickerWithSettings:(id<GFYCategoryPickerSettings> _Nullable)settings;

/**
 <#Description#>

 @param settings <#settings description#>
 @return <#return value description#>
 */
- (instancetype)initWithSettings:(id<GFYCategoryPickerSettings> _Nullable)settings;

/**
 <#Description#>
 */
@property (nonatomic, copy) id<GFYCategoryPickerSettings> settings;

/**
 <#Description#>
 */
@property (nonatomic, weak) id<GFYCategoryPickerDelegate> delegate;

/**
 <#Description#>
 */
@property (nonatomic, copy, nullable) NSString *filter;

/**
 <#Description#>
 */
@property (nonatomic, readonly) UICollectionView *collectionView;

/**
 <#Description#>
 */
- (void)refreshModelCustomization;

/**
 <#Description#>

 @param prefix <#prefix description#>
 @return <#return value description#>
 */
- (BOOL)hasCategoryStartingWith:(NSString *)prefix;

@end

NS_ASSUME_NONNULL_END

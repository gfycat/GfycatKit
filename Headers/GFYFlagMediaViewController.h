//
//  GFYFlagMediaViewController.h
//  GfycatComponents
//
//  Created by Oleksii Chubenko on 3/31/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <UIKit/UIKit.h>

@class GfycatMedia;
@protocol GFYFlagMediaViewControllerSettings;
@class GFYFlagMediaViewController;

@protocol GFYFlagMediaViewControllerDelegate <NSObject>
@optional
- (void)gfycatFlagMediaViewControllerDidCancel:(GFYFlagMediaViewController *)flagController;
- (void)gfycatFlagMediaViewControllerDidFlag:(GFYFlagMediaViewController *)flagController;

@end

@interface GFYFlagMediaViewController : UIViewController

+ (instancetype)gfycatFlagMediaViewControllerSettings:(id<GFYFlagMediaViewControllerSettings>)settings;
- (instancetype)initWithSettings:(id<GFYFlagMediaViewControllerSettings>)settings;

@property (nonatomic, copy) id<GFYFlagMediaViewControllerSettings> settings;

@property (nonatomic, weak) id<GFYFlagMediaViewControllerDelegate> delegate;
@property (nonatomic, strong) GfycatMedia *media;

@end

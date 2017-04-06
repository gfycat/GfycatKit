//
//  GFYSimpleContainerViewController.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 1/17/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface GFYSimpleContainerViewController : UIViewController

@property (nonatomic, strong) IBOutlet UIView *containerView;
@property (nonatomic, strong) IBOutlet UIViewController *activeViewController;

- (void)setActiveViewController:(UIViewController *)newViewController animated:(BOOL)animated;

@end

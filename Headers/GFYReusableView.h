//
//  GFYReusableView.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 1/15/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Generic reusable view.
 */
@protocol GFYReusableView <NSObject>

/**
 Prepares view for reuse.
 */
- (void)prepareForReuse;

@end

NS_ASSUME_NONNULL_END

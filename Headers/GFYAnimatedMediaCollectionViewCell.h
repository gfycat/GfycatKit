//
//  GFYAnimatedMediaCollectionViewCell.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 2/23/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GfycatApiKit/GfycatApiKit.h>
#import "GFYCollectionViewCell.h"
#import "GFYMediaView.h"

@interface GFYAnimatedMediaCollectionViewCell : GFYCollectionViewCell<GfycatMedia *>

@property (nonatomic, copy) void (^videoPlaybackStartHandler)(GfycatMedia *media);

// actions
@property (nonatomic, copy) void (^mediaFlagActionHandler)(GfycatMedia *media);

@property (nonatomic, assign) GFYMediaViewFormal mediaFormat;

@end

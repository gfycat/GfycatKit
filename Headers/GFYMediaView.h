//
//  GFYMediaView.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 3/2/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GfycatApiKit/GfycatApiKit.h>

@class GFYMediaView;

typedef NS_ENUM(NSInteger, GFYMediaViewFormal)
{
    GFYMediaViewFormatThumbnail,
    GFYMediaViewFormatGIF_1MB,
    GFYMediaViewFormatGIF_2MB,
    GFYMediaViewFormatGIF_5MB,
    GFYMediaViewFormatWebP,
//    GFYMediaViewFormatMP4,
};

extern NSString * const GFYMediaViewPlaybackStartedNotification;
extern NSString * const GFYMediaUserInfoKey;

typedef void (^GFYMediaViewPlaybackStartedHandler)(GfycatMedia *media);

@protocol GFYMediaViewDelegate <NSObject>

- (void)gfyMediaView:(GFYMediaView *)mediaView didStartPlayback:(GfycatMedia *)media;

@end

@interface GFYMediaView : UIView

@property (nonatomic, weak) IBOutlet id<GFYMediaViewDelegate> delegate;
@property (nonatomic, copy) GFYMediaViewPlaybackStartedHandler playbackStartedHandler;

@property (nonatomic, strong) GfycatMedia *media;
@property (nonatomic, assign) GFYMediaViewFormal mediaFormat;

@end

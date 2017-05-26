//
//  GFYMediaView.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 3/2/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <UIKit/UIKit.h>
#import <GfycatApiKit/GfycatApiKit.h>

NS_ASSUME_NONNULL_BEGIN

@class GFYMediaView;

/**
 `GFYMediaViewFormat` enum defines a list of supported media playback formats.

 - GFYMediaViewFormatThumbnail: Thumbnail with no animation
 - GFYMediaViewFormatGIF_1MB: 1 MB sized GIF
 - GFYMediaViewFormatGIF_2MB: 2 MB sized GIF
 - GFYMediaViewFormatGIF_5MB: 5 MB sized GIF
 - GFYMediaViewFormatWebP: Animated WebP
 */
typedef NS_ENUM(NSInteger, GFYMediaViewFormat)
{
    GFYMediaViewFormatThumbnail,
    GFYMediaViewFormatGIF_1MB,
    GFYMediaViewFormatGIF_2MB,
    GFYMediaViewFormatGIF_5MB,
    GFYMediaViewFormatWebP,
};

/**
 <#Description#>
 */
extern NSString * const GFYMediaViewPlaybackStartedNotification;

/**
 <#Description#>
 */
extern NSString * const GFYMediaUserInfoKey;

/**
 <#Description#>

 @param media <#media description#>
 */
typedef void (^GFYMediaViewPlaybackStartedHandler)(GfycatMedia *media);

/**
 The delegate of a `GFYMediaView` object must adopt the `GFYMediaViewDelegate` protocol.
 */
@protocol GFYMediaViewDelegate <NSObject>

/**
 `GFYMediaView` notifies its `delegate` when media playback starts.

 @param mediaView media view that started playback
 @param media media object that started playing
 */
- (void)gfyMediaView:(GFYMediaView *)mediaView didStartPlayback:(GfycatMedia *)media;

@end

/**
 `GFYMediaView` class provides playback functionality for `GfycatMedia` objects.
 */
@interface GFYMediaView : UIView

/**
 <#Description#>
 */
@property (nonatomic, weak) IBOutlet id<GFYMediaViewDelegate> delegate;

/**
 <#Description#>
 */
@property (nonatomic, copy, nullable) GFYMediaViewPlaybackStartedHandler playbackStartedHandler;

/**
 <#Description#>
 */
@property (nonatomic, strong, nullable) GfycatMedia *media;

/**
 <#Description#>
 */
@property (nonatomic, assign) GFYMediaViewFormat mediaFormat;

@end

NS_ASSUME_NONNULL_END

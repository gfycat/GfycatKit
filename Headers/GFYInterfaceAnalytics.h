//
//  GFYInterfaceAnalytics.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 1/18/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <Foundation/Foundation.h>
#import "GFYAnalyticsHub.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Browsing context identifier
 */
typedef NSString *GFYAnalyticsContext NS_EXTENSIBLE_STRING_ENUM;

/**
 Tracks whether the user is viewing a gfycat in “full” or “half” screen.
 */
typedef NSString *GFYAnalyticsFlow NS_EXTENSIBLE_STRING_ENUM;

/**
 User is browsing through the category list
 */
extern const GFYAnalyticsContext GFYAnalyticsContextCategoryList;

/**
 User is browsing recent items
 */
extern const GFYAnalyticsContext GFYAnalyticsContextRecent;

/**
 User is browsing a category
 */
extern const GFYAnalyticsContext GFYAnalyticsContextCategory;

/**
 User is browsing search results
 */
extern const GFYAnalyticsContext GFYAnalyticsContextSearch;

/**
 Browsing context is unknown
 */
extern const GFYAnalyticsContext GFYAnalyticsContextNone;

/**
 User is browsing gfycat fullscreen
 */
extern const GFYAnalyticsFlow GFYAnalyticsFlowFull;

/**
 User is browsing gfycat half-screen
 */
extern const GFYAnalyticsFlow GFYAnalyticsFlowHalf;

/**
 Browsing flow is unknown
 */
extern const GFYAnalyticsFlow GFYAnalyticsFlowNone;

/**
 The `GFYInterfaceAnalytics` protocol defines analytics events collecte by the `GfycatKit`
 */
@protocol GFYInterfaceAnalytics
@optional

/**
 This event can be used to track when gfycats are shared

 @param gfyid Gfycat name of the target video.
 @param context Browsing context identifier
 @param keyword The name of the selected category or search term for which the viewed gfycat belongs to.
 */
- (void)trackSendVideoWithGfyId:(NSString *)gfyid context:(GFYAnalyticsContext)context keyword:(NSString * _Nullable)keyword;

/**
 This event can be used to track when a category has been selected.

 @param keyword The name of the selected category or search term for which the viewed gfycat belongs to.
 */
- (void)trackTapCategoryWithKeyword:(NSString *)keyword;

/**
 This event can be used to track what a user is searching for.

 @param keyword The name of the selected category or search term for which the viewed gfycat belongs to.
 */
- (void)trackSearchVideosWithKeyword:(NSString *)keyword;

/**
 This event can be used to track when a user has scrolled through categories.

 @param count Number of categories scrolled through.
 */
- (void)trackScrollInCategoriesWithCount:(NSNumber *)count;

/**
 This event can be used to track when a user has scrolled through videos.

 @param count Number of videos scrolled through.
 @param context Browsing context identifier
 @param keyword The name of the selected category or search term for which the viewed gfycat belongs to.
 */
- (void)trackScrollInVideosWithCount:(NSNumber *)count context:(GFYAnalyticsContext)context keyword:(NSString * _Nullable)keyword;

/**
 This event can be used to track when a user has reported a video.

 @param gfyName Gfycat name of the target video.
 */
- (void)trackReportContentWithGfyName:(NSString *)gfyName;

/**
 This event can be used to track view impressions.

 @param gfyid Gfycat name of the target video.
 @param context Browsing context identifier
 @param keyword The name of the selected category or search term for which the viewed gfycat belongs to.
 @param flow Tracks whether the user is viewing a gfycat in “full” or “half” screen.
 */
- (void)trackVideoPlayedWithGfyId:(NSString *)gfyid context:(GFYAnalyticsContext)context keyword:(NSString * _Nullable)keyword flow:(GFYAnalyticsFlow)flow;

/**
 This event can be used to track view impressions.

 @param gfyid Gfycat name of the target video.
 @param context Browsing context identifier
 @param keyword The name of the selected category or search term for which the viewed gfycat belongs to.
 @param flow Tracks whether the user is viewing a gfycat in “full” or “half” screen.
 @param ip <#ip description#>
 @param time <#time description#>
 */
- (void)trackVideoPlayedWithGfyId:(NSString *)gfyid context:(GFYAnalyticsContext)context keyword:(NSString * _Nullable)keyword flow:(GFYAnalyticsFlow)flow ip:(NSString *)ip time:(NSString *)time;

/**
 This event can be used to track when an asset is broken.
 
 @param gfyid Gfycat name of the target video.
 @param assetUrl Gfycat url of the target video.
 */
- (void)trackBrokenMediaWithGfyId:(NSString *)gfyid assetUrl:(NSURL *)assetUrl;

@end

@interface GFYAnalyticsHub (GFYInterfaceAnalytics) <GFYInterfaceAnalytics>

@end

NS_ASSUME_NONNULL_END

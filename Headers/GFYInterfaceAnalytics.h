//
//  GFYInterfaceAnalytics.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 1/18/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NSString *GFYAnalyticsContext NS_EXTENSIBLE_STRING_ENUM;
typedef NSString *GFYAnalyticsFlow NS_EXTENSIBLE_STRING_ENUM;

extern const GFYAnalyticsContext GFYAnalyticsContextCategoryList;
extern const GFYAnalyticsContext GFYAnalyticsContextRecent;
extern const GFYAnalyticsContext GFYAnalyticsContextCategory;
extern const GFYAnalyticsContext GFYAnalyticsContextSearch;
extern const GFYAnalyticsContext GFYAnalyticsContextNone;

extern const GFYAnalyticsFlow GFYAnalyticsFlowFull;
extern const GFYAnalyticsFlow GFYAnalyticsFlowHalf;
extern const GFYAnalyticsFlow GFYAnalyticsFlowNone;

@interface GFYInterfaceAnalytics: NSObject

+ (instancetype)sharedAnalytics;

- (void)reportSendVideoWithGfyId:(NSString *)gfyid context:(GFYAnalyticsContext)context keyword:(NSString *)keyword;
- (void)reportTapCategoryWithKeyword:(NSString *)keyword;
- (void)reportSearchVideosWithKeyword:(NSString *)keyword;
- (void)reportScrollInCategoriesWithCount:(NSNumber *)count;
- (void)reportScrollInVideosWithCount:(NSNumber *)count context:(GFYAnalyticsContext)context keyword:(NSString *)keyword;
- (void)reportVideoPlayedWithGfyId:(NSString *)gfyid context:(GFYAnalyticsContext)context keyword:(NSString *)keyword flow:(GFYAnalyticsFlow)flow;
- (void)reportVideoPlayedWithGfyId:(NSString *)gfyid context:(GFYAnalyticsContext)context keyword:(NSString *)keyword flow:(GFYAnalyticsFlow)flow ip:(NSString *)ip time:(NSString *)time;
- (void)trackReportContentWithGfyName:(NSString *)gfyName;
- (void)trackReportUser:(NSString *)userName gfyName:(NSString *)gfyName;

@end

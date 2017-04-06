//
//  GfycatInterfaceCache.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 3/16/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <GfycatApiKit/GfycatApiKit.h>

@protocol GfycatInterfaceCache <NSObject>

- (BOOL)serializeRecents:(NSArray<id<NSObject, NSCopying, NSSecureCoding>> *)recentGfycats;
- (NSArray<id<NSObject, NSCopying, NSSecureCoding>> *)deserializeRecents;
- (id<NSObject, NSCopying, NSSecureCoding>)firstRecentMedia;
- (BOOL)addRecentMedia:(id<NSObject, NSCopying, NSSecureCoding>)media;
- (BOOL)removeRecentMedia:(id<NSObject, NSCopying, NSSecureCoding>)media;

- (BOOL)serializeSearchHistory:(NSArray<NSString *> *)searchHistory;
- (NSArray<NSString *> *)deserializeSearchHistory;
- (BOOL)addSearchTerm:(NSString *)searchTerm;

@end

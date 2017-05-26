//
//  GfycatBlackListCache.h
//  GfycatKit
//
//  Created by Oleksii Chubenko on 3/24/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <GfycatApiKit/GfycatApiKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GfycatBlackListCache <NSObject>

- (NSSet<NSString *> *)mediaIdsBlackList;

- (BOOL)serializeMediaIdsBlackList:(NSSet<NSString *> *)mediaIdsBlackList;
- (NSSet<NSString *> *)deserializeMediaIdsBlackList;

- (BOOL)addMediaIdToBlackList:(NSString *)mediaId;
- (BOOL)removeMediaIdFromBlackList:(NSString *)media;

@end

NS_ASSUME_NONNULL_END

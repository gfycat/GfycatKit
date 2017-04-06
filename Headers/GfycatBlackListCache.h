//
//  GfycatBlackListCache.h
//  GfycatComponents
//
//  Created by Oleksii Chubenko on 3/24/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <GfycatApiKit/GfycatApiKit.h>

@protocol GfycatBlackListCache <NSObject>

- (NSSet<NSString *> *)mediaIdsBlackList;

- (BOOL)serializeMediaIdsBlackList:(NSSet<NSString *> *)mediaIdsBlackList;
- (NSSet<NSString *> *)deserializeMediaIdsBlackList;

- (BOOL)addMediaIdToBlackList:(NSString *)mediaId;
- (BOOL)removeMediaIdFromBlackList:(NSString *)media;

@end

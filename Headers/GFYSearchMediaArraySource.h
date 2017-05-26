//
//  GFYSearchMediaArraySource.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 3/16/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <Foundation/Foundation.h>
#import "GFYArraySource.h"

NS_ASSUME_NONNULL_BEGIN

@interface GFYSearchMediaArraySource : NSObject <GFYArraySource>

+ (instancetype)sourceWithSearchTerm:(NSString *)searchTerm;
- (instancetype)initWithSearchTerm:(NSString *)searchTerm;

@property (nonatomic, readonly) NSString *searchTerm;

@end

NS_ASSUME_NONNULL_END

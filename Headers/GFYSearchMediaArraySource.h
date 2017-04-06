//
//  GFYSearchMediaArraySource.h
//  GfycatComponents
//
//  Created by Victor Pavlychko on 3/16/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GFYArraySource.h"

@interface GFYSearchMediaArraySource : NSObject <GFYArraySource>

+ (instancetype)sourceWithSearchTerm:(NSString *)searchTerm;
- (instancetype)initWithSearchTerm:(NSString *)searchTerm;

@property (nonatomic, readonly) NSString *searchTerm;

@end

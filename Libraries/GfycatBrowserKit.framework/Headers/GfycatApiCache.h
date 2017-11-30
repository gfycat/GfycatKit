//
//  GfycatApiCache.h
//  GfycatBrowserKit
//
//  Created by Victor Pavlychko on 3/16/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  End-User License Agreement for Gfycat Software Product
//  
//  This End-User License Agreement (“EULA”) is a legal agreement between you
//  (either an individual or a single entity) (“the End User”) and Gfycat, Inc.
//  for the software product identified above, which includes computer software
//  and may include associated media, printed materials, and “online” or
//  electronic documentation (“Software Product”).
//  
//  By download, installing, copying or otherwise using the Software Product,
//  you agree to be bound by the terms of this EULA.
//  
//  Software Product License
//  
//  Gfycat is providing the Software Product solely for the purpose of allowing
//  the End User to avail of or enjoy the benefits of the services provided by
//  Gfycat. Except as expressly set forth herein, the End User is NOT allowed to
//  distribute this Software (either for profit or merely to recover your media and
//  distribution costs) whether as a stand-alone product, or as part of a
//  compilation or anthology, nor to use it for supporting your business or
//  customers. It may be distributed freely on any website or through any other
//  distribution mechanism, as long as no part of it is modified in any manner
//  whatsoever.
//  
//  1. Grant of License
//  
//  This EULA grants you the following rights: 
//  
//  a. Installation and Use. You may install and use an unlimited number of copies
//  of the Software Product.
//  
//  b. Reproduction and Distribution. You may reproduce and distribute an unlimited
//  number of copies of the Software Product; provided that each copy shall be a
//  true and complete copy, including all copyright and trademark notices, and
//  shall be accompanied by a copy of this EULA.
//  
//  c. Copies of the Software Product may be distributed as a standalone product or
//  included with your own product as long as the Software Product is not sold or
//  included in a product or package that intends to receive benefits through the
//  inclusion of the Software Product.
//  
//  2. Description Of Other Rights And Limitations
//  
//  a. Limitations. You may not reverse engineer, decompile, or disassemble the
//  Software Product.
//  
//  b. Update and Maintenance. Gfycat SDK upgrades shall be free of charge.
//  However, the End User shall be responsible to ensure that the Gfycat SDK is
//  updated as and when Gfycat releases new updates or upgrades.
//  
//  c. Separation of Components. The Software Product is licensed as a single
//  product. Its component parts may not be separated for use on more than one
//  computer.
//  
//  d. Assignment. You may assign all of your rights under this EULA, provided the
//  recipient agrees to the terms of this EULA and subject to the prior written
//  consent of Gfycat.
//  
//  e. Termination. Without prejudice to any other rights, Gfycat may terminate
//  this EULA if you fail to comply with the terms and conditions of this EULA. In
//  such event, you shall destroy all copies of the Software Product and all of its
//  component parts.
//  
//  3. Copyright
//  
//  Except as expressly provided herein, all title and copyrights in and to the
//  Software Product (including but not limited to any images, photographs,
//  clipart, libraries, and examples incorporated into the Software Product), the
//  accompanying printed materials, and any copies of the Software Product are
//  owned by Gfycat. The Software Product is protected by copyright laws and
//  international treaty provisions. 
//  
//  4. Limited Warranty
//  
//  a. No Warranties. Gfycat expressly disclaims any and all warranties for the
//  Software Product. The Software Product and any related documentation is
//  provided “as is” without warranty of any kind, either express or implied,
//  including, without limitation, the implied warranties or merchantability,
//  fitness for a particular purpose, or non-infringement. The entire risk arising
//  out of use or performance of the Software Product shall remain with the End
//  User.
//  
//  b. No Liability For Damages. In no event shall Gfycat be liable for any direct,
//  special, consequential, incidental or indirect damages whatsoever (including,
//  without limitation, damages for loss of business profits, business
//  interruption, loss of business information, or any other pecuniary loss)
//  arising out of the use of or inability to use this product, even if Gfycat is
//  aware of the possibility of such damages and known defects.
//  
//  5. Third Party License
//  
//  The Software Product may contain third party software which shall be separately
//  licensed as applicable. This license will be included within the Software
//  Product.
//  
//  6. Governing Law
//  
//  This EULA and all disputes arising thereof shall be subject to internal laws of
//  the State of California, USA, where the state and federal courts located in
//  Santa Clara County, California shall exclusive jurisdiction.
//

#import <GfycatApiKit/GfycatApiKit.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - GfycatApiCache -
NS_SWIFT_NAME(GfycatApiCacheProtocol)
@protocol GfycatApiCache <NSObject>

- (BOOL)serializeCategories:(GfycatCategories *)categories;
- (GfycatCategories *)deserializeCategories;

@end

#pragma mark - GfycatApiProtocol -
NS_SWIFT_NAME(GfycatApiProtocol)
@protocol GfycatApi <NSObject>

/**
 *  Client Id of your App, as registered with Gfycat.
 */
@property (nonatomic, copy, readonly) NSString *appClientID;

/**
 *  Client Secret of your App, as registered with Gfycat.
 */
@property (nonatomic, copy, readonly) NSString *appClientSecret;

/**
 *  The oauth token stored in the account store credential, if available.
 *  If not empty, this implies user has granted access.
 */
@property (nonatomic, copy, readonly, nullable) NSString *accessToken;

/**
 *  The username stored in the account store credential, if available.
 *  If not empty, this implies user is logged in.
 */
@property (nonatomic, copy, readonly, nullable) NSString *username;

#pragma mark - Authentication -

/**
 *  Creates a new user account
 *
 *  @param username Username for account
 *  @param password Password for account
 *  @param email    Email address for account - Optional
 *  @param success  Provides a dictionary authorization and refresh tokens.
 *  @param failure  Provides an error and a server status code.
 */
- (void)createAccountWithUsername:(NSString *)username
                         password:(NSString *)password
                            email:(nullable NSString *)email
                          success:(GfycatResponseBlock)success
                          failure:(nullable GfycatFailureBlock)failure;

/**
 *  Gets authorization token and validates this session.
 *
 *  @param success  Provides a dictionary authorization token.
 *  @param failure  Provides an error and a server status code.
 */
- (void)validateSession:(GfycatResponseBlock)success
                failure:(nullable GfycatFailureBlock)failure;

/**
 *  Refreshes authotization token if refresh token has not expired,
 *  otherwise fetches a new authorization token.
 *
 *  @param success  Provides a dictionary authorization token.
 *  @param failure  Provides an error and a server status code.
 */
- (void)refreshSession:(GfycatResponseBlock)success
               failure:(nullable GfycatFailureBlock)failure;

/**
 *  Validate if authorization is done.
 *
 *  @return YES if access token present, otherwise NO.
 */
- (BOOL)isSessionValid;

/**
 *  Validate if login is done.
 *
 *  @return YES if user is logged in, otherwise NO.
 */
- (BOOL)isLoggedIn;

/**
 *  Clears stored access token and browser cookies.
 */
- (void)logout;


#pragma mark - Media -

/**
 *  Get information about a Media object.
 *
 *  @param mediaId  Id of a Media object.
 *  @param success  Provides a fully populated Media object.
 *  @param failure  Provides an error and a server status code.
 */
- (void)getMedia:(NSString *)mediaId
     withSuccess:(GfycatMediaObjectBlock)success
         failure:(nullable GfycatFailureBlock)failure;

/**
 *  Get user-specific information about a Media object.
 *
 *  @param mediaId  Id of a Media object.
 *  @param success  Provides a fully populated Media object.
 *  @param failure  Provides an error and a server status code.
 */
- (void)getExtendedMedia:(NSString *)mediaId
             withSuccess:(GfycatExtendedMediaObjectBlock)success
                 failure:(nullable GfycatFailureBlock)failure;

/**
 *  Get list of all categories.
 *
 *  @param success  Provides a media list object.
 *  @param failure  Provides an error and a server status code.
 */
- (void)getCategoriesWithSuccess:(GfycatCategoryArrayBlock)success
                         failure:(nullable GfycatFailureBlock)failure;

/**
 *  Get a list of media objects from a category.
 *
 *  @param categoryTitle Title of category.
 *  @param count    Count of objects to fetch.
 *  @param success  Provides an array of Media objects and Pagination info.
 *  @param failure  Provides an error and a server status code.
 */
- (void)getCategoryMedia:(NSString *)categoryTitle
                   count:(NSInteger)count
             WithSuccess:(GfycatMediaBlock)success
                 failure:(nullable GfycatFailureBlock)failure;

/**
 *  Search published Media with string.
 *
 *  @param count    Count of objects to fetch.
 *  @param success  Provides a media list object.
 *  @param failure  Provides an error and a server status code.
 */
- (void)searchMediaWithString:(NSString *)searchString
                        count:(NSInteger)count
                  withSuccess:(GfycatMediaBlock)success
                      failure:(nullable GfycatFailureBlock)failure;

/**
 *  Like published Media.
 *
 *  @param mediaId  Id of a Media object.
 *  @param tag      Tag of a Media object.
 *  @param success  Provides a dictionary server response if any.
 *  @param failure  Provides an error and a server status code.
 */
- (void)likeMedia:(NSString *)mediaId
           forTag:(nullable NSString *)tag
      withSuccess:(GfycatResponseBlock)success
          failure:(nullable GfycatFailureBlock)failure;

/**
 *  Dislike published Media.
 *
 *  @param mediaId  Id of a Media object.
 *  @param tag      Tag of a Media object.
 *  @param success  Provides a dictionary server response if any.
 *  @param failure  Provides an error and a server status code.
 */
- (void)dislikeMedia:(NSString *)mediaId
              forTag:(nullable NSString *)tag
         withSuccess:(GfycatResponseBlock)success
             failure:(nullable GfycatFailureBlock)failure;

#pragma mark - Common Pagination Request -

/**
 *  Get paginated objects as specified by information contained in the PaginationInfo object.
 *
 *  @param paginationInfo The PaginationInfo Object obtained from the previous endpoint success block.
 *  @param success        Provides an array of paginated Objects.
 *  @param failure        Provides an error and a server status code.
 */
- (void)getPaginatedItemsForInfo:(GfycatPaginationInfo *)paginationInfo
                     withSuccess:(GfycatPaginatiedResponseBlock)success
                         failure:(nullable GfycatFailureBlock)failure;

#pragma mark - Gfycat Creation Request -

/**
 *  Creates a new Gfycat upload target
 *
 *  @param parameters     Dictionary of optional parameters for new Gfycat.
 *                          Valid keys are:
 *                              kNewGfycatTitle as an NSString,
 *                              kNewGfycatDescription as an NSString,
 *                              kNewGfycatTags as an NSArray of NSString,
 *                              kNewGfycatPrivate as an NSNumber 0 or 1;
 *                              // TODO - Should we include the MD5 flag incase people want to upload duplicates?
 *  @param success        Provides a response dictionary with keys kNewGfycatName and kNewGfycatSecret.
 *  @param failure        Provides an error and a server status code.
 */
- (void)createGfycatWithParameters:(nullable NSDictionary *)parameters
                           success:(GfycatUploadKeyBlock)success
                           failure:(nullable GfycatFailureBlock)failure;

/**
 *  Upload file to create new Gfycat
 *
 *  @param success        Called on success.
 *  @param progress       Provides an upload progress.
 *  @param failure        Provides an error and a server status code.
 */
- (void)uploadFileUrl:(NSURL *)fileUrl
         forUploadKey:(GfycatUploadKey *)uploadKey
              success:(GfycatSuccessBlock)success
             progress:(nullable GfycatProgressBlock)progress
              failure:(nullable GfycatFailureBlock)failure;

#pragma mark - Gfycat Delete Request - TODO - IMPEMENT ME
/**
 *  Deletes a Gfycat target
 *
 *  @param parameters     Dictionary of optional parameters for new Gfycat.
 *                          Valid keys are:
 *                              kNewGfycatTitle as an NSString,
 *                              kNewGfycatDescription as an NSString,
 *                              kNewGfycatTags as an NSArray of NSString,
 *                              kNewGfycatPrivate as an NSNumber 0 or 1;
 *                              // TODO - Should we include the MD5 flag incase people want to upload duplicates?
 *  @param success        Provides a response dictionary with keys kNewGfycatName and kNewGfycatSecret.
 *  @param failure        Provides an error and a server status code.
 */
- (void)deleteGfycatWithParameters:(nullable NSDictionary *)parameters
                           success:(GfycatUploadKeyBlock)success
                           failure:(nullable GfycatFailureBlock)failure;

#pragma mark - Report Gfycat Request -

/**
 *  Report Media object as offensive.
 *
 *  @param mediaId  Id of a Media object.
 *  @param success  Provides a dictionary server response if any.
 *  @param failure  Provides an error and a server status code.
 */
- (void)reportMedia:(NSString *)mediaId
        withSuccess:(GfycatResponseBlock)success
            failure:(nullable GfycatFailureBlock)failure;

@end

@interface GfycatApi (GfycatApiProtocol) <GfycatApi>

@end

NS_ASSUME_NONNULL_END

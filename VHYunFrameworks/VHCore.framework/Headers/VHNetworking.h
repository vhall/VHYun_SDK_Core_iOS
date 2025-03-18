//
//  VHNetService.h
//  VHNetworking
//
//  Created by vhall on 2018/8/17.
//  Copyright © 2018年 vhall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Availability.h>
#import <TargetConditionals.h>

#ifndef _VHNETWORKING_
#define _VHNETWORKING_

#import "VHURLRequestSerialization.h"
#import "VHURLResponseSerialization.h"
#import "VHSecurityPolicy.h"

#if !TARGET_OS_WATCH
#import "VHNetworkReachabilityManager.h"
#endif

#import "VHURLSessionManager.h"
#import "VHHTTPSessionManager.h"

#endif /* _VHNETWORKING_ */

typedef NS_ENUM(NSInteger, VHNetReachabilityStatus) {
    VHNetReachabilityStatusUnknown          = -1,
    VHNetReachabilityStatusNotReachable     = 0,
    VHNetReachabilityStatusReachableViaWWAN = 1,
    VHNetReachabilityStatusReachableViaWiFi = 2,
};

typedef void(^CompleteBlock)(id _Nullable responseObject, NSError* error);
typedef void(^CompleteTaskBlock)(id _Nullable responseObject,NSURLSessionDataTask * task, NSError* error);

@interface VHNetworking : NSObject
//设置header
+ (void) setValue:(NSString*)value forHTTPHeaderField:(NSString*)header;
//GET
+ (void) GET: (NSString *)URLString completeBlock:(CompleteBlock) completeBlock;
+ (void) GET: (NSString *)URLString parameters:(id)parameters completeBlock:(CompleteBlock) completeBlock;
+ (void) GET: (NSString *)URLString parameters:(id)parameters timeout:(NSTimeInterval) timeoutInterval completeBlock:(CompleteBlock) completeBlock;

//POST
+ (void) POST:(NSString *)URLString parameters:(id)parameters completeBlock:(CompleteBlock) completeBlock;
+ (void) POST:(NSString *)URLString parameters:(id)parameters timeout:(NSTimeInterval) timeoutInterval completeBlock:(CompleteBlock) completeBlock;
+ (NSURLSessionDataTask *) POSTRequestTask:(NSString *)URLString parameters:(id)parameters timeout:(NSTimeInterval) timeoutInterval completeBlock:(CompleteTaskBlock) completeBlock;

+ (NSURLSessionDataTask *)POSTTask:(NSString *)URLString parameters:(id)parameters timeout:(NSTimeInterval) timeoutInterval completeBlock:(CompleteBlock) completeBlock;


+ (void)POST:(NSString *)URLString parameters:(nullable id)parameters
constructingBodyWithBlock:(nullable void (^)(id<VHMultipartFormData> _Nonnull))block
    progress:(nullable void (^)(NSProgress * _Nonnull))uploadProgress
     success:(nullable void (^)(NSURLSessionDataTask * _Nonnull, id _Nullable))success
     failure:(nullable void (^)(NSURLSessionDataTask * _Nullable, NSError * _Nonnull))failure;

//默认15s超时 返回值不做json解析
+ (void) GETHttpResponse: (NSString *)URLString completeBlock:(CompleteBlock) completeBlock;

//Download
+ (void) Download: (NSString*)URLString
         progress: (void (^)(NSProgress *downloadProgress)) downloadProgressBlock
      destination: (NSURL * (^)(NSURL *targetPath, NSURLResponse *response)) destination
completionHandler: (void (^)(NSURLResponse *response, NSURL *filePath, NSError *error)) completionHandler;

//ReachabilityStatus
+ (void) ReachabilityStatusChangeBlock:(nullable void (^)(VHNetReachabilityStatus status))block;

@end



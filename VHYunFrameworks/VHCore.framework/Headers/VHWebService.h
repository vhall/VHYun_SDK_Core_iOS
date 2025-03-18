//
//  VHSDKHttpClient.h
//  VHallSDK
//
//  Created by vhall on 16/5/27.
//  Copyright © 2016年 vhall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VHNetworking.h"

typedef void (^FinishedTaskBlock)(id data, NSURLSessionDataTask *task);
typedef void (^FinishedBlock)(id data);
typedef void (^FailedBlock)(NSError *error);

@interface VHWebService : NSObject

/// SDK接口POST请求
+ (void)requestWithApi:(NSString *)apiName param:(NSDictionary *)param onRequestFinished:(FinishedBlock)onFinishedBlock onRequestFailed:(FailedBlock)onFailedBlock;

/// SDK接口POST请求
+ (NSURLSessionDataTask *)requestBlockTaskWithApi:(NSString *)apiName param:(NSDictionary *)param onRequestFinished:(FinishedTaskBlock)onFinishedBlock onRequestFailed:(FailedBlock)onFailedBlock;

/// SDK接口POST请求
+ (NSURLSessionDataTask *)requestTaskWithApi:(NSString *)apiName param:(NSDictionary *)param onRequestFinished:(FinishedBlock)onFinishedBlock onRequestFailed:(FailedBlock)onFailedBlock;

/// SDK接口GET请求,并设置超时时间
+ (void)getRequestWithUrl:(NSString *)url timeout:(NSTimeInterval)timeoutInterval onRequestFinished:(FinishedBlock)onFinishedBlock onRequestFailed:(FailedBlock)onFailedBlock;

/// SDK接口上传文件请求
+ (void)uploadWithApi:(NSString *)apiName param:(NSDictionary *)param constructingBodyWithBlock:(void (^)(id <VHMultipartFormData> formData))block progress:(nullable void (^)(NSProgress *progress))uploadProgress success:(void (^)(NSURLSessionDataTask *task, id responseObject))success failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;

#pragma mark - 大数据日志上报
+ (void)sendBigDataLog:(NSString *)logHost kVlaue:(long)k s:(NSString *)s bu:(NSString *)bu dataDic:(NSDictionary *)dataDic onRequestFinished:(FinishedBlock)onFinishedBlock onRequestFailed:(FailedBlock)onFailedBlock;

@end

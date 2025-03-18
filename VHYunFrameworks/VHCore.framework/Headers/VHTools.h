//
//  VHTools.h
//  VHBasePlatform
//
//  Created by vhall on 2017/11/22.
//  Copyright © 2017年 www.vhall.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@interface VHTools : NSObject
+ (NSString *) md5:(NSString*)str;
// SHA256
+ (NSString *)SHA256String:(NSString *)string;
+ (NSString *) urlEncoded:(NSString*)str;
// 字典转json字符串方法
+ (NSString *)jsonStringWithObject:(id)dict;
+ (id)objectWithJsonString:(NSString *)jsonString;
//参数转get请求串
+ (NSString *) paramToGetString:(NSDictionary *)param;

+ (NSString *) crc32Token:(NSString*)token;
+ (NSString *) base64:(NSString *)str;
+ (NSString *) base64Decode:(NSString *)str;

+ (NSString *) safeString:(NSString *)str;

+ (NSString *) deviceName;
//是否耳机插入
+ (BOOL) isHeadsetPluggedIn;
+ (BOOL) earlier5s;
#pragma mark - NSTimer
+ (NSTimer *)scheduledTimerWithTimeInterval:(NSTimeInterval)seconds target:(id)aTarget  block:(void (^)(NSTimer *timer))block repeats:(BOOL)repeats;
+ (NSTimer *)timerWithTimeInterval:(NSTimeInterval)seconds target:(id)aTarget  block:(void (^)(NSTimer *timer))block repeats:(BOOL)repeats;
#pragma mark - CMSampleBufferRef
+ (CVPixelBufferRef)createCVPixelBufferRefWithBGRAData:(unsigned int *)data width:(size_t)width height:(size_t)height;
+ (CMSampleBufferRef)convertCVPixelBufferRef:(CVPixelBufferRef)pixel_buffer;

+ (NSString *)atom;//原子封装用于数据统计

+ (NSDictionary *)dictionaryForJsonData:(NSData *)data;
/**
 * 判断字符串是否有值
 * 有值返回 YES
 * 空或者无效返回 NO
 */
+ (BOOL)isWhetherStringHasValue:(NSString *)aStr;
/**
 * 判断字典为空
 */
+ (BOOL)checkDictIsValided:(NSDictionary *)dict;
/**
 * 判断数组为空
 */
+ (BOOL)checkArrayIsValided:(NSArray *)arr;

// 字符串转json对象
+ (id)JSONObjectWithResult:(NSString *)result;

// 字符串进行解base64及gzip压缩
+ (NSString *)decodeBase64ThenGzip:(NSString *)inputString;

# pragma mark- UUID
/// 生成一个新的UUID（每次都不一样）
+ (NSString *)NewUUID;
/// 生成一个新的UUID（每次都不一样）
+ (NSString *)getUUID  __deprecated_msg("名字表达不清晰后续使用 [VHTools NewUUID]");

/// 获取UUID，一生只有一个
+ (NSString *)uuid;
+ (NSString *)getUUIDByKeyChain;
+ (void)save:(NSString*)service data:(id)data;
+ (id)load:(NSString*)service;
+ (void)deleteKeyData:(NSString*)service;

@end

//
//  VHLoger.h
//  VHLivePusherSDK
//
//  Created by vhall on 2017/11/14.
//  Copyright © 2017年 www.vhall.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#define VHALLNOTIFY_TOAST_MSG @"VHALLNOTIFY_TOAST_MSG"

#ifdef VHYUN_BASE
//日志等级
typedef NS_ENUM(NSInteger, VHLogLevel) {
    VHLogLevelNone    = 0,    //NONE
    VHLogLevelError   = 1,    //Error
    VHLogLevelWarning = 2,    //Warning
    VHLogLevelInfo    = 3,    //Info
    VHLogLevelDebug   = 4,    //Debug
};
#else
#import "VHLiveBase.h"
#endif

#define VHLogLevelVerbose 5

//VERBOSE
#define V(fmt, ...) [VHLoger logLevel:VHLogLevelVerbose LogInfo:(fmt), ## __VA_ARGS__]
#define VHLogV(fmt, ...) [VHLoger logLevel:VHLogLevelVerbose LogInfo:(@"%s[Line %d]" fmt),__func__,__LINE__ , ## __VA_ARGS__]
//Debug
#define D(fmt, ...) [VHLoger logLevel:VHLogLevelDebug LogInfo:(fmt), ## __VA_ARGS__]
#define VHLogD(fmt, ...) [VHLoger logLevel:VHLogLevelDebug LogInfo:(@"%s[Line %d]" fmt),__func__,__LINE__ , ## __VA_ARGS__]
//Info
#define I(fmt, ...) [VHLoger logLevel:VHLogLevelInfo LogInfo:(fmt), ## __VA_ARGS__]
#define VHLogI(fmt, ...) [VHLoger logLevel:VHLogLevelInfo LogInfo:(@"%s[Line %d]" fmt),__func__,__LINE__ , ## __VA_ARGS__]
//Warning
#define W(fmt, ...) [VHLoger logLevel:VHLogLevelWarning LogInfo:(fmt), ## __VA_ARGS__]
#define VHLogW(fmt, ...) [VHLoger logLevel:VHLogLevelWarning LogInfo:(@"%s[Line %d]" fmt),__func__,__LINE__ , ## __VA_ARGS__]
//Error
#define E(fmt, ...) [VHLoger logLevel:VHLogLevelError LogInfo:(@"%s[Line %d]" fmt),__func__,__LINE__ , ## __VA_ARGS__]
#define VHLogE(fmt, ...) [VHLoger logLevel:VHLogLevelError LogInfo:(@"%s[Line %d]" fmt),__func__,__LINE__ , ## __VA_ARGS__]

// 从SDK 发出 Toast 消息
#define T(fmt, ...) [VHLoger notify_toast_msg:fmt,## __VA_ARGS__]

@interface VHLoger : NSObject
+ (NSString *)platform;
+ (NSString *)uuidString;

/**
 *  log初始化函数，在系统启动时调用
 */
+ (void)logIntial;

/**
 *  设置要记录的log级别
 *
 *  @param level level 要设置的log级别
 */
+ (void)setLogLevel:(VHLogLevel)level;

/**
 *  当前log级别
 */
+ (VHLogLevel)logLevel;

/**
 *  设置要记录到日志文件的log级别
 *
 *  @param level level 要设置的log级别
 */
+ (void)setLogLevelWriteToFile:(VHLogLevel)level;
    
/**
 *  是否打印到控制台 //默认不打印到控制台
 *
 *  @param isShow isShow
 */
+ (void) printLogToConsole:(BOOL)isShow;

/**
 *  记录系统crash的Log函数
 *
 *  @param exception 系统异常
 */
+ (void)logCrash:(NSException*)exception;

/// 发送Toast消息给 VHALLNOTIFY_TOAST_MSG
/// @param format 消息体
+ (void)notify_toast_msg:(NSString *)format, ...;

/**
 *  log记录函数
 *
 *  @param level  log所属的等级
 *  @param format 具体记录log的格式以及内容
 */
+ (void)logLevel:(VHLogLevel)level
         LogInfo:(NSString*)format,... NS_FORMAT_FUNCTION(2,3);

/**
 *  LOGLEVELV级Log记录函数
 *
 *  @param format format 具体记录log的格式以及内容
 */
+ (void)logV:(NSString*)format,... NS_FORMAT_FUNCTION(1,2);

/**
 *  LOGLEVELD级Log记录函数
 *
 *  @param format 具体记录log的格式以及内容
 */
+ (void)logD:(NSString*)format,... NS_FORMAT_FUNCTION(1,2);

/**
 *  LOGLEVELI级Log记录函数
 *
 *  @param format 具体记录log的格式以及内容
 */
+ (void)logI:(NSString*)format,... NS_FORMAT_FUNCTION(1,2);

/**
 *  LOGLEVELW级Log记录函数
 *
 *  @param format 具体记录log的格式以及内容
 */
+ (void)logW:(NSString*)format,... NS_FORMAT_FUNCTION(1,2);

/**
 *  LOGLEVELE级Log记录函数
 *
 *  @param format 具体记录log的格式以及内容
 */
+ (void)logE:(NSString*)format,... NS_FORMAT_FUNCTION(1,2);
@end

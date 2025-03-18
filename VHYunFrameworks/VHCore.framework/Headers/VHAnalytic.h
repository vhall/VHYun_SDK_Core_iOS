//
//  VHAnalytic.h
//  VHallAnalytics
//
//  Created by vhall on 2018/4/18.
//  Copyright © 2018年 Morris. All rights reserved.
//

#import <Foundation/Foundation.h>

//VHAnalyticsConfig实例 通过宏VHConfigInstance可得到该实例
@class VHAnalyticsConfig;


///VHAnalytic类，内部实现了数据初始化、数据上报等Api
@interface VHAnalytic : NSObject

#pragma mark - 初始化模块

/**
 SDK初始化
 
 host 日志上报地址
 bu   业务单元，paas=1， saas=0或其它
 baseAttributes  基础数据
 
 return  YES：初始化成功 NO：初始化失败
 */
+ (BOOL)initWithHost:(NSString *)host businessUnit:(NSString *)bu baseAttributes:(NSDictionary *)baseAttributes;
+ (BOOL)initWithHost:(NSString *)host businessUnit:(NSString *)bu baseAttributes:(NSDictionary *)baseAttributes withUUID:(NSString *)uuid;


#pragma mark - 更新模块
/**
 更新基础数据baseAttributes
 
 */
+ (void)updateBaseAttributes:(NSDictionary *)baseAttributes;


#pragma mark - 上报模块
///主意：使用SDK上报模块前，需要去报SDK已初始化成功！

/**
 上报日志
 
 kValue k值
 */
+ (void)sendLog:(NSString *)kValue;
/**
 上报日志
 
 kValue k值
 attributes 其他数据
 */
+ (void)sendLog:(NSString *)kValue attributes:(NSDictionary *)attributes;

@end


///VHAnalyticsConfig实例 通过宏VHConfigInstance可得到该实例
@interface VHAnalyticsConfig : NSObject

+ (instancetype)sharedInstance;

//上报地址
@property (nonatomic, copy) NSString *host;
//基础数据
@property (nonatomic, strong) NSMutableDictionary *baseAttributes;
//业务单元，paas=1， saas=0或其它
@property (nonatomic, copy) NSString *businessUnit;

@end




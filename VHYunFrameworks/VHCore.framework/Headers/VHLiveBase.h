//
//  VHLiveBase.h
//  VHBasePlatform
//
//  Created by vhall on 2017/11/28.
//  Copyright © 2017年 www.vhall.com. All rights reserved.
//

#import <Foundation/Foundation.h>

//日志等级
typedef NS_ENUM(NSInteger, VHLogLevel) {
    VHLogLevelNone    = 0,    //NONE
    VHLogLevelError   = 1,    //Error
    VHLogLevelWarning = 2,    //Warning
    VHLogLevelInfo    = 3,    //Info
    VHLogLevelDebug   = 4,    //Debug
};

@interface VHLiveBase : NSObject

/**
 *  注册app
 *  @param appid  http://www.vhallyun.com/ 控制台中创建app 并设置包名 获得
 */
+ (BOOL) registerApp:(NSString *)appid;

/**
 *  注册app
 *  @param appid  http://www.vhallyun.com/ 控制台中创建app 并设置包名 获得
 *  @param completeBlock  SDK初始化成功回调， error 成功为 nil  如果不成功会5s重试一次
 */
+ (BOOL) registerApp:(NSString *)appid completeBlock:(void(^)(NSError *error)) completeBlock;

/**
 *  注册app
 *  @param appid  http://www.vhallyun.com/ 控制台中创建app 并设置包名 获得
 *  @param host   平台域名如api.vhallyun.com
 */
+ (BOOL) registerApp:(NSString *)appid host:(NSString*)host;

/**
 *  注册app
 *  @param appid  http://www.vhallyun.com/ 控制台中创建app 并设置包名 获得
 *  @param host   平台域名如api.vhallyun.com
 *  @param completeBlock  SDK初始化成功回调， error 成功为 nil  如果不成功会5s重试一次
 */
+ (BOOL) registerApp:(NSString *)appid host:(NSString*)host completeBlock:(void(^)(NSError *error)) completeBlock;

/**
 * 更新美颜证书[前置获取认证信息]
 * @param accessToken accessToken
 * @param handle 返回结果
 */
+ (void)updateBeatufiyLicenseWithAccessToken:(NSString *)accessToken completeBlock:(void(^)(NSError *error))handle;

/**
 *  设置第三方用户id  建议使用用户id保持唯一性
 *  @param third_party_user_id  第三方用户id 使用您的App登录后获得用户id即可 会使底层重新链接触发当前链接房间的上下线消息
 *  三方用户id [third_party_user_id] 不能为空, 字符类型:字母、数字、下划线, 长度:1-64个字符
 */
+ (BOOL) setThirdPartyUserId:(NSString *)third_party_user_id;

/**
 *  设置第三方用户id  建议使用用户id保持唯一性
 *  @param third_party_user_id  第三方用户id 使用您的App登录后获得用户id即可 会使底层重新链接触发当前链接房间的上下线消息
 *  三方用户id [third_party_user_id] 不能为空, 字符类型:字母、数字、下划线, 长度:1-64个字符
 *  @param context 对应third_party_user_id 自定义信息用于接IM收消息的context中，如：@{@"nick_name":@"xxxx",@"avatar":@"xxxx"};
     为 nil 时，聊天消息会读取通过API设置nick_name和avatar。
 */
+ (BOOL) setThirdPartyUserId:(NSString *)third_party_user_id context:(NSDictionary*)context;

/**
 *  设置第三方用户id  建议使用用户id保持唯一性
 *  @param third_party_user_id  第三方用户id 使用您的App登录后获得用户id即可 会使底层重新链接触发当前链接房间的上下线消息
 *  三方用户id [third_party_user_id] 不能为空, 字符类型:字母、数字、下划线, 长度:1-64个字符
 *  @param context 对应third_party_user_id 自定义信息用于接IM收消息的context中，如：@{@"nick_name":@"xxxx",@"avatar":@"xxxx"};
     为 nil 时，聊天消息会读取通过API设置nick_name和avatar。
 *  @param  completeBlock 设置重置完成操作
 */
+ (BOOL) setThirdPartyUserId:(NSString *)third_party_user_id context:(NSDictionary*)context completeBlock:(void(^)(NSError *error)) completeBlock;

/**
 *  @param context 对应third_party_user_id 自定义信息用于接IM收消息的context中，如：@{@"nick_name":@"xxxx",@"avatar":@"xxxx"};
     为 nil 时，聊天消息会读取通过API设置nick_name和avatar。
 */
+ (BOOL) setThirdPartyUserContext:(NSDictionary*)context;

/**
 *  设置日志等级
 *  @param level  日志等级
 */
+ (void) setLogLevel:(VHLogLevel)level;

/**
 * 追加日志内容
 * @param dict 日志内容
 * @discussion 自主增加日志的内容，有效区间：已开始推流～即将结束推流
 */
+ (void)reportExtra:(NSDictionary *)dict;

/**
 * 追加日志内容 立即上报
 * @param k  kvalue
 * @param dict 日志内容
 */
+ (void)reportNow:(NSInteger)k dict:(NSDictionary *)dict;

/**
 *  设置日志是否输出到控制台
 *  @param isPrint  否输出到控制台
 */
+ (void) printLogToConsole:(BOOL)isPrint;//默认不显示到控制台、

/**
 *  设置AppGroup 用于 录屏直播功能
 *  @param appGroup  AppGroup
 */
+ (BOOL) setAppGroup:(NSString *)appGroup;

/**
 *  当前SDK 是否已初始化
 */
+ (BOOL) isInited;

/**
*  获得当前third_party_user_id
*/
+ (NSString*) getThirdPartyUserId;
/**
*  获得当前Context
*/
+ (NSDictionary *) getContext;
/**
 *  获得当前SDK 基础模块版本号
 */
+ (NSString *) getSDKVersion;

@end

@interface VHLiveBase (DeprecatedMethod)
+ (void)prepareBeautifyWithAccessToken:(NSString *)accessToken completeBlock:(void(^)(NSError *error))handle __deprecated_msg("请使用 +[VHLiveBase updateBeatufiyLicenseWithAccessToken:completeBlock:]");
@end

//
//  VHAppInfo.h
//  VHBasePlatform
//
//  Created by vhall on 2017/11/29.
//  Copyright © 2017年 www.vhall.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VHLogInfo : NSObject
- (instancetype)initWithDic:(NSDictionary*)dic;
@property (nonatomic, copy)NSString *accountID;//开发者id
@property (nonatomic, copy)NSString *sessionID;//日志上报会话id
@property (nonatomic, copy)NSString *app_name;
@property (nonatomic, copy)NSString *ip;
@property (nonatomic, copy)NSString *uid;
@end

@interface VHAppInfo : NSObject
+(instancetype) shareInstance;

@property (nonatomic, assign)BOOL   isInited;//是否已初始化，调用init/start接口
@property (nonatomic,copy) NSString *socket_server;//socket_server
@property (nonatomic,copy) NSString *socket_token;//socket_server token
@property (nonatomic,copy) NSString *chat_server;//chat_server

@property (nonatomic, assign)BOOL   isTest;//是否测试环境默认 NO 正式环境
@property (nonatomic, assign)BOOL   isHide;//是否全局隐身进入消息通道
@property (nonatomic, assign)BOOL   isDisableSocket;//禁用SocketIO 和聊天链接

@property (nonatomic, copy)NSString *sdkHost;
@property (nonatomic, copy)NSString *logBuHost;//业务层日志上报地址
@property (nonatomic, copy)NSString *docGraffiti_Url;//文档涂鸦地址

@property (nonatomic, copy)NSString *appID;
@property (nonatomic, copy)NSString *third_party_user_id_old;//以前id
@property (nonatomic, copy)NSString *third_party_user_id;
@property (nonatomic, copy)NSString *context;//自定义消息
@property (nonatomic, copy)NSString *access_token;
@property (nonatomic, strong, readonly)NSString *checkStr;
@property (nonatomic, copy) NSString *document_server;
@property (nonatomic) NSInteger docMaxUpload;
@property (nonatomic, copy) NSArray *docUploadMIMEList;
@property (nonatomic, copy)NSString *appGroup;
@property (nonatomic) NSString *deviceInfo;

@property (nonatomic, copy)NSString *license_url;
@property (nonatomic, copy)NSString *license_key;

/*!
 * 业务层日志bu 默认0 其他 http://wiki.vhallops.com/pages/viewpage.action?pageId=2491279
 */
@property (nonatomic, strong) NSString *businessUnit;

//互动 推流参数
@property (nonatomic,assign) int     type;   // 0 未知 1 SD 2 HD 3 UHD 4CUSTOM
@property (nonatomic,copy)   NSDictionary  *options;    //分辨率 //帧率
//log 日志上报相关
@property (nonatomic, copy)NSString *logHost;
@property (nonatomic, strong)VHLogInfo *logInfo;

/// 美颜云鉴权标记 三态: nil未验证 NO不通过 YES通过
@property (nonatomic) NSNumber *allowYunBeautify;

@property (nonatomic, strong) NSString *ABCEF;//值为 [[NSBundle mainBundle] bundleIdentifier] 用于调试

///获取到UUID后，如果用NSUserDefaults存储，当程序被卸载后重装时，再获得的UUID和之前就不同了。使用keychain存储可以保证程序卸载重装时，UUID不变。但当刷机后，UUID还是会改变的，但这仍是目前为止最佳的解决办法了。
+ (NSString *)getUUIDByKeyChain;
+ (void)save:(NSString*)service data:(id)data;
+ (id)load:(NSString*)service;
+ (void)deleteKeyData:(NSString*)service;


@end

//
//  VHBaseCommunication.h
//  VHBasePlatform
//
//  Created by vhall on 2017/11/21.
//  Copyright © 2017年 www.vhall.com. All rights reserved.
//

#import <Foundation/Foundation.h>
@class VHMessage;

typedef void(^MessageCallback)(VHMessage *msg);
typedef void(^RegisterAppCompleteBlock)(NSError *error);
typedef void(^SetThirdPartyUserIdBlock)(NSError *error);

@interface VHBaseCommunication : NSObject
+ (instancetype) shareInstance;

/// private -> init some important class with param AccessToken
- (void)initStartSDKToAccessToken:(NSString *)accessToken;
- (void)initStartSDKToAccessToken:(NSString *)access_token handle:(void(^)(NSDictionary *data))handle;

//@property (nonatomic,strong)RegisterAppCompleteBlock completeBlock;
@property (nonatomic,strong)SetThirdPartyUserIdBlock setThirdPartyUserIdBlock;


/**
 * 添加事件监听
 * event 默认是  类名_channel_id(room_id)
 * accessToken 验证token
 */
- (BOOL)onChannel:(NSString*)channel_id access_token:(NSString*)access_token object:(id)object callback:(MessageCallback)callback;

/**
 * 移除事件监听
 */
- (void)removeChannel:(NSString*)channel_id object:(id)object;

/**
 * 移除一个模块下所有的监听事件
 */
- (void)removeObject:(id)object;

/**
 * 给服务器发送消息
 */
- (void)emitMessage:(NSString*)msg channel:(NSString*)channel_id type:(NSString*)type accessToken:(NSString*)accessToken completed:(void (^)(NSError *error))completed;

/**
 * 给服务器发送消息
 */
- (void)emitMessage:(NSString*)msg channel:(NSString*)channel_id roomID:(NSString*)roomID  type:(NSString*)type accessToken:(NSString*)accessToken completed:(void (^)(NSError *error))completed;

/**
 * 给别的模块发送消息
 */
- (void)postData:(id)data type:(NSString*)type channel:(NSString*)channel_id ;


/** 主动重连SocketIO*/
- (void)resetSocketIO;

/** 主动断开SocketIO*/
- (void)removeSocketIO;

/** 主动断开TX*/
- (void)removeTX;

@end

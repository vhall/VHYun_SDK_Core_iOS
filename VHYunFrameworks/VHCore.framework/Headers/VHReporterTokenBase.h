//
//  VHReporterTokenBase.h
//  VHBasePlatform
//
//  Created by liguoliang on 2022/12/12.
//  Copyright © 2022 vhall. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VHReporterTokenBase : NSObject
@property (nonatomic, readonly) NSString *s;// 会话id
@property (nonatomic) NSInteger bu;			// paas=1  saas=0
@property (nonatomic) NSString *app_id;		// app id
@property (nonatomic) NSString *user_id;	// 用户 id
@property (nonatomic) NSString *uuid;		// 设备 id
@property (nonatomic) NSString *room_id;	// 房间 id
@property (nonatomic) NSString *inav_id;	// 互动 id
@property (nonatomic) NSString *channel_id;	// 聊天室 id
@property (nonatomic) NSString *record_id;	// 回放 id
@property (nonatomic) NSString *pf;			// 平台 app=>0 sdk=>4
@property (nonatomic) NSDictionary *ex;		// base的扩展内容
- (NSDictionary *)dict;
@end

NS_ASSUME_NONNULL_END



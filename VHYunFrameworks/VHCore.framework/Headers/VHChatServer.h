//
//  VHChatServer.h
//  VhallIphone
//
//  Created by dev on 16/8/26.
//  Copyright © 2016年 www.vhall.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "IKeepAliveServer.h"

@interface VHChatServer : NSObject

@property (nonatomic, weak)   id <IKeepAliveServerDelegate> delegate;
@property (nonatomic, assign) VHKeepAliveServerStatus status;


/*
 * 连接url
 * 格式为  xxxx.com/ws/xxx/xxx/xxx   xxxx为域名，监听的xxx为房间或频道
 */
- (void)connectWithURL:(NSString *)urlStr;

- (void)disConnect;

@end



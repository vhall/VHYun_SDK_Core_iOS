//
//  VHMessageServer.h
//  VHallSDK
//
//  Created by Ming on 16/7/7.
//  Copyright © 2016年 vhall. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "IKeepAliveServer.h"


@interface VHMessageServer : NSObject
@property (weak,   nonatomic) id<IKeepAliveServerDelegate> delegate;
@property (assign, nonatomic) VHKeepAliveServerStatus status;
@property (nonatomic, readonly) BOOL isConnected, isConnecting;

- (VHMessageServer*)initWithUrl:(NSString*)url token:(NSString*)token;

- (void)connect;

- (void)disConnect;

- (void)emitWithEvent:(NSString *)event data:(NSDictionary*)data;
@end

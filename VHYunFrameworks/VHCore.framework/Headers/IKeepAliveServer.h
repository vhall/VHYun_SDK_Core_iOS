//
//  IKeepAliveServer.h
//  VHMessage
//
//  Created by vhall on 2018/8/13.
//  Copyright © 2018年 vhall. All rights reserved.
//

#ifndef IKeepAliveServer_h
#define IKeepAliveServer_h

typedef NS_ENUM(NSInteger, VHKeepAliveServerStatus) {
    VHKeepAliveServerStatusDisconnect,
    VHKeepAliveServerStatusConnecting,
    VHKeepAliveServerStatusConnected
};

@protocol IKeepAliveServerDelegate <NSObject>
- (void)server:(id)server stateChange:(VHKeepAliveServerStatus)status;
- (void)server:(id)server event:(NSString*)event message:(id)message;
- (void)server:(id)server error:(NSError *)error;
@end


#endif /* IKeepAliveServer_h */

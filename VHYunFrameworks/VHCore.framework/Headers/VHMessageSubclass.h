//
//  VHMessageSubclass.h
//  VHBasePlatform
//
//  Created by vhall on 2018/3/8.
//  Copyright © 2018年 www.vhall.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VHMessage.h"
@interface VHMessageSubclass : VHMessage
- (instancetype)initWithDic:(NSDictionary*)dic isSocketio:(BOOL)isSocketio;
@property (nonatomic,assign) BOOL   isSocketio;           //是否socketio上线消息
@end

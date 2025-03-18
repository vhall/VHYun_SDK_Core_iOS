//
//  VHConfig.h
//  VHOpenSDK
//
//  Created by vhall on 2017/11/29.
//  Copyright © 2017年 www.vhall.com. All rights reserved.
//

#ifndef VHConfig_h
#define VHConfig_h

#define SDK_Version             @"2.3.9"

#define TEST_ENABLED            0 //是否输出测试数据  如:切换线路的对外输出

#define API_HOST                @"https://api.vhallyun.com"
#define API_HOST_T              @"https://test01-api.vhallyun.com"

/**
 *  统计SDK配置
 */
//日志上报地址
//点播流的日志上报域名 日志上报备用地址 接口获取具体地址
#define VHStreamLog_HostUrl         @"https://dc.e.vhall.com/login"
//SDK层业务日志上报域名
#define VHAnalyticSDKHostUrl        @"https://pingback.e.vhall.com/msdk.gif"
//SDK层业务日志上报域名 测试环境
#define VHAnalyticSDKHostUrl_T      @"https://pingback.e.vhall.com/msdk.gif?test=1&"
//新 --- SDK层业务日志上报域名
#define VHNewAnalyticSDKHostUrl     @"https://dc.e.vhall.com/data_agent/up"
//新 --- SDK层业务日志上报域名 测试环境
#define VHNewAnalyticSDKHostUrl_T   @"https://test-dc.e.vhall.com/data_agent/up"

//SDK接口定义 http://doc.vhall.com/docs/show/378
#define API_bcs_init            @"/sdk/v2/init/start"
//#define API_bcs_sent_message    @"/sdk/v1/message/sent"
//新消息服务
#define API_v2_send_message     @"/sdk/v2/message/send"                 //发送消息接口

#endif /* VHConfig_h */

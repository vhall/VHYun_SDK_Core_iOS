//
//  VHConfig_globle.h
//  VHOpenSDK
//
//  Created by vhall on 2018/12/19.
//  Copyright © 2018年 www.vhall.com. All rights reserved.
//

#ifndef VHConfig_globle_h
#define VHConfig_globle_h



//平台类型（0 iOSAPP 1 AndroidAPP 2 flash 3 wap 4 IOSSDK 5 AndroidSDK 6 小助手 7pc端）
#define VHAnalyticSDKPlatform       @"4"
//业务单元（0：SasS  1：PasS ）
#define VHAnalyticSDKBusinessUnit   @"1"

//统计事件k值
#define VHAnalyticSDKInitKvalue         @"282001"//SDK初始化事件K值
#define VHAnalyticLoginKvalue           @"282008"//设置第三方ID
#define VHAnalyticStreamInitKvalue      @"282002"//推流模块初始化
#define VHAnalyticVideoInitKvalue       @"282003"//观看直播模块初始化
#define VHAnalyticVodInitKvalue         @"282004"//点播模块初始化
#define VHAnalyticDocInitKvalue         @"282005"//文档模块初始化
#define VHAnalyticIMInitKvalue          @"282006"//IM模块初始化
#define VHAnalyticInteractiveInitKvalue @"282007"//互动模块舒适化
#define VHAnalyticCreateDocKvalue       @"282009"//文档模块初始化

#define BCS_access_token        @"vhall"//现在基础模块是随便传

#define VHALLNOTIFY_RESETSOCKET @"vhall_notify_resetsocket" //third_party_user_id 改变重连socketio并join
#define VHALLNOTIFY_SetContext  @"vhall_notify_SetContext"  //改变context需要重新jion频道


#define DOC_jpg_Format          @"%@/%@/%@.jpg"         //文档ppt 图片拼接

//消息Event定义 http://wiki.vhall.com/index.php?id=rd:paas:sdk%E6%94%B6%E6%B6%88%E6%81%AF%E8%AF%B4%E6%98%8E
#define MSG_SDK_inside_live     @"SDK_inside_live"      //SDK 观看直播内部消息 主要发送播放器延迟时间
#define MSG_SDK_inside_vod_doc  @"SDK_inside_vod_doc"   //SDK 内部消息 主要发送 文档消息

#define MSG_StreamStart         @"StreamStart"          //开始推流消息体
#define MSG_StreamOver          @"StreamOver"           //结束推流消息体
#define MSG_StreamConverted     @"StreamConverted"      //流清晰度转换完成通知消息体
#define MSG_CustomBroadcast     @"CustomBroadcast"      //自定义消息广播消息体
#define MSG_Chat                @"Chat"                 //聊天消息内容
#define MSG_Document            @"Document"             //文档业务消息体
#define MSG_Join                @"Join"                 //用户进入频道消息
#define MSG_Leave               @"Leave"                //用户离开频道消息
#define MSG_Inav                @"Inav"                 //互动消息

//weak self定义
#ifndef weakify
#if DEBUG

#if __has_feature(objc_arc)
#define weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
#endif

#else

#if __has_feature(objc_arc)
#define weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
#endif

#endif
#endif


#ifndef strongify
#if DEBUG

#if __has_feature(objc_arc)
#define strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
#else
#define strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
#endif

#else

#if __has_feature(objc_arc)
#define strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
#else
#define strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
#endif

#endif
#endif
#endif /* VHConfig_globle_h */

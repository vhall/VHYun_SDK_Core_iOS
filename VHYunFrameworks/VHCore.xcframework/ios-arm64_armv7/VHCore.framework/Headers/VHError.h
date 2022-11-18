//
//  VHError.h
//  VHBasePlatform
//
//  Created by LiGuoliang on 2022/3/4.
//  Copyright © 2022 vhall. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark- VHError Global
FOUNDATION_EXPORT NSErrorDomain const VHErrorDomain;
typedef NS_ERROR_ENUM(VHErrorDomain, VHError) {
    VHErrorCode_Unknow = -1,
    VHErrorCode_InvalidAppId = 10001,
    VHErrorCode_InvalidAccessToken = 10002,
};

#pragma mark- VHError LSS
FOUNDATION_EXPORT NSErrorDomain const VHErrorDomain_LSS;
typedef NS_ERROR_ENUM(VHErrorDomain_LSS, VHErrorLSS) {
    VHErrorCode_LSS_Unknow = -1,
};

#pragma mark- VHError RTC
FOUNDATION_EXPORT NSErrorDomain const VHErrorDomain_RTC;
typedef NS_ERROR_ENUM(VHErrorDomain_RTC, VHErrorRTC) {
    VHErrorCode_RTC_Unknow = -1,
};

#pragma mark- VHError Beautify
FOUNDATION_EXPORT NSErrorDomain const VHErrorDomain_Beautify;
typedef NS_ERROR_ENUM(VHErrorDomain_Beautify, VHErrorBeautify) {
    VHErrorCode_Beautify_ModuleCheckFailed = -30001,
    VHErrorCode_Beautify_YunCheckFailed = -30002,
};

/// error - userinfo - @"detail"
FOUNDATION_EXPORT NSErrorUserInfoKey const kVHErrorDetailKey;

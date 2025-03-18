//
//  VHNewAnalytic.h
//  VHBasePlatform
//
//  Created by 郭超 on 2023/5/30.
//  Copyright © 2023 vhall. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VHNewAnalytic : NSObject

/// 单例
+ (instancetype)sharedInstance;

/// 发送日志上报
/// - Parameters:
///   - kValue: value
///   - bu: 业务单元，paas=1， saas=0或其它
///   - attributes: 自定义信息
+ (void)sendLog:(NSString *)kValue bu:(NSString *)bu attributes:(NSDictionary *)attributes;

@end

NS_ASSUME_NONNULL_END

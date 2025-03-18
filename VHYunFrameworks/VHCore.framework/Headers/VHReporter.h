//
//  VHReporter.h
//  VHBasePlatform
//
//  Created by liguoliang on 2022/11/21.
//  Copyright © 2022 vhall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VHReporterTokenBase.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSInteger VHReportKeyIndex;
FOUNDATION_EXTERN VHReportKeyIndex kVHReportIndex_AllPath;

@interface VHReporter : NSObject
@property (nonatomic) VHReporterTokenBase *tbase;

/// 单例初始化
+ (instancetype)shareInstance;

/// 创建一个可以循环的上报，以k为维度，可能存在不同的k使用不同的上报策略
/// @param repeat X秒做一次重复，0为不重复
/// @param k k值
- (void)reportStartRepeat:(NSInteger)repeat withK:(VHReportKeyIndex)k;

/// 增加一个上报内容(依据start中k的属性进行上报)
/// @param tokenDict 上报的token内容
/// @param k k值
- (void)reportMsg:(NSDictionary *)tokenDict WithK:(VHReportKeyIndex)k;

/// 结束一个循环的上报，并将还未到时的上报的内容进行加入队列，进行上报
/// @param k k值
- (void)reportEndRepeatWithK:(VHReportKeyIndex)k;

/// 快速上报,便捷方法
/// @param k k值
/// @param tokenDict 上报的token内容
- (void)vhReportNow:(NSInteger)k tokenDict:(NSDictionary *)tokenDict;

@end

NS_ASSUME_NONNULL_END

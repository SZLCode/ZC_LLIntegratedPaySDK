//
//  PaySdkColor.h
//  PaySdkColor
//
//  Created by xuyf on 14-4-23.
//  Copyright (c) 2014年 llyt. All rights reserved.
//

#import "LLPaySDKConst.h"

typedef NS_ENUM(NSUInteger, LLIntegratedPayMode) {
    LLIntegratedPayModeStandard,
    LLIntegratedPayModeSimple,
};

@interface LLIntegratedPaySDK : NSObject

/**
 *  单例sdk
 *
 *  @return 返回LLPaySdk的单例对象
 */
+ (instancetype)sharedSdk;

/**
 LianLianPay 聚合支付
 
 @param viewController 承载聚合支付的视图控制器
 @param paymentInfo 交易信息
 @param mode 聚合支付模式 注意：暂时只支持LLIntegratedPayModeStandard
 @param complete 支付结果回调
 */
- (void)presentLLIntegratedPayInViewController: (UIViewController *)viewController
                                andPaymentInfo: (NSDictionary *)paymentInfo
                                          mode: (LLIntegratedPayMode)mode
                                      complete: (CompletionHandler)complete;

/**
 切换正式、测试服务器（默认不调用是正式环境，请不要随意使用该函数切换至测试环境）
 
 @param isTestServer isTestServer YES测试环境，NO正式环境
 */
+ (void)switchToTestServer:(BOOL)isTestServer;

@end

#pragma mark - Apple Pay

@interface LLIntegratedPaySDK(ApplePay)

typedef enum : NSUInteger {
    kLLAPPayDeviceSupport,                  // 完全支持
    kLLAPPayDeviceNotSupport,               // 设备无法支持，无法绑卡，原因是机型不支持，或者系统版本太低
    kLLAPPayDeviceVersionTooLow,            // 设备无法支持银联卡支付，需要iOS9.2以上
    kLLAPPayDeviceNotBindChinaUnionPayCard, // 设备支持，用户未绑卡
} LLAPPaySupportStatus;

/**
 *  判断是否能使用 Apple Pay
 *
 *  @return 返回支持与否的枚举值LLAPPaySupportStatus
 */
+ (LLAPPaySupportStatus)canDeviceSupportApplePayPayments;

/** 跳转wallet系统app进行绑卡 */
+ (void)showWalletToBindCard;


+ (NSString *)valueWithShippingMessages:(NSArray *)shippingMessages
                        shippingMethods:(NSArray *)shippingMethods
                           summaryItems:(NSArray *)summaryItems
                            postalPrice:(NSString *)postalPrice;

@end

#pragma mark - WeChat

@interface LLIntegratedPaySDK(Wechat)

+(BOOL) wx_registerApp:(NSString *)appid;

+ (BOOL)handleOpenURL: (NSURL *)url;

@end

@interface LLIntegratedPaySDK (AliPay)

+ (void)llHandleAliPayResult;

@end


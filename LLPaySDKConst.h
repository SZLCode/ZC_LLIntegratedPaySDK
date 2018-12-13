//
//  LLPaySDKConst.h
//  LianLianPay
//
//  Created by EvenLam on 2017/8/16.
//  Copyright © 2017年 LianLianPay. All rights reserved.
//

#ifndef LLPaySDKConst_h
#define LLPaySDKConst_h


#endif /* LLPaySDKConst_h */

@import Foundation;
@import UIKit;


extern const NSString *const kLLPaySDKBuildVersion;
extern const NSString *const kLLPaySDKVersion;

typedef enum LLPayResult {
    kLLPayResultSuccess = 0,      // 支付成功
    kLLPayResultFail = 1,         // 支付失败
    kLLPayResultCancel = 2,       // 支付取消，用户行为
    kLLPayResultInitError,        // 支付初始化错误，订单信息有误，签名失败等
    kLLPayResultInitParamError,   // 支付订单参数有误，无法进行初始化，未传必要信息等
    kLLPayResultUnknow,           // 其他
    kLLPayResultRequestingCancel, // 授权支付后取消(支付请求已发送)
} LLPayResult;

typedef void(^CompletionHandler)(LLPayResult result, NSDictionary *dic);

//
//  KRMacrodefinition.h
//  KRMacrodefinition
//
//  Created by RK on 2018/1/28.
//  Copyright © 2018年 RK. All rights reserved.
//

#ifndef KRMacrodefinition_h
#define KRMacrodefinition_h

#if DEBUG
#define NSLog(format, ...) do {                                             \
fprintf(stderr, "<%s : %d> %s\n",                                           \
[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String],  \
__LINE__, __func__);                                                        \
(NSLog)((format), ##__VA_ARGS__);                                           \
fprintf(stderr, "-------\n");                                               \
} while (0)
#define NSLogRect(rect) NSLog(@"%s x:%.4f, y:%.4f, w:%.4f, h:%.4f", #rect, rect.origin.x, rect.origin.y, rect.size.width, rect.size.height)
#define NSLogSize(size) NSLog(@"%s w:%.4f, h:%.4f", #size, size.width, size.height)
#define NSLogPoint(point) NSLog(@"%s x:%.4f, y:%.4f", #point, point.x, point.y)
#else
#define NSLog(FORMAT, ...) nil
#define NSLogRect(rect) nil
#define NSLogSize(size) nil
#define NSLogPoint(point) nil
#endif

//单例
#define KR_IMPLEMENT_SINGLETON(CLASS_NAME)                  \
+(instancetype)sharedInstance {                            \
static CLASS_NAME *__##CLASS_NAME##_instance = nil;      \
\
static dispatch_once_t onceToken;                        \
dispatch_once(&onceToken, ^{                             \
__##CLASS_NAME##_instance = [[CLASS_NAME alloc] init]; \
});                                                      \
return __##CLASS_NAME##_instance;                        \
}

#define KR_DECLARE_SINGLETON(CLASS_NAME) +(instancetype)sharedInstance;

#define KRScreenWidth     [[UIScreen mainScreen] bounds].size.width
#define KRScreenHeight    [[UIScreen mainScreen] bounds].size.height


#define KRDevice_Is_iPhoneX ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)
#define KRPhoneXBar 34

#endif


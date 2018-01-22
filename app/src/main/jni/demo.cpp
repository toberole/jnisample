/*

jni.h是联系jvm与C/C++的纽带


*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 打印日志
#include <android/log.h>
#define LOG_TAG "clog"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

// 必须导入 与C有点不同
#include "com_zhouwei_jnisample1_business_JNIDemo.h"

JNIEXPORT jstring JNICALL Java_com_zhouwei_jnisample1_business_JNIDemo_getString
  (JNIEnv *env, jobject jobj){

  	/**
        返回一个java String
        jstring (JNICALL *NewStringUTF)(JNIEnv *env, const char *utf);

        (*env) 相当于是JNINativeInterface *JNIEnv
         (**env) 相当于是JNINativeInterface
  	*/

     // return (**env).NewStringUTF("hello from  native Code");
     // sleep(7);
     return (*env).NewStringUTF("hello from  native Code");
}


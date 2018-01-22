//
// Created by zhouwei11 on 2018/1/21.
// 注意需要加
#include <jni.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "com_zhouwei_jnisample1_business_C_Callback_Java_CallBack.h"
#include "com_zhouwei_jnisample1_business_C_Callback_Java.h"

// 访问java的方法
JNIEXPORT void JNICALL Java_com_zhouwei_jnisample1_business_C_1Callback_1Java_getInfo(JNIEnv *env, jobject jobj, jobject callback)
{
     jclass cls = (*env).GetObjectClass(callback);
     jmethodID jmid = (*env).GetMethodID(cls,"onCallback","(Ljava/lang/String;)V");
     jstring info = (*env).NewStringUTF("I am a Callback!");
     (*env).CallVoidMethod(callback,jmid,info);
     const char  *str =(*env).GetStringUTFChars(info,NULL);
     (*env).ReleaseStringUTFChars(info,str);
}





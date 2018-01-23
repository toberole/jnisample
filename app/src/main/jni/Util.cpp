//
// Created by zhouwei11 on 2018/1/22.
//

#include <jni.h>
#include <stdio.h>
#include <stdlib.h>


/*

// 由于jvm和c++对中文的编码不一样，因此需要转码。 utf8/16 转换成gb2312
char* jstringToChar(JNIEnv *env, jstring jstr) {
    int length = (env)->GetStringLength(jstr);
    const jchar* jcstr = (env)->GetStringChars(jstr, 0);
    char* rtn = (char*) malloc(length * 2 + 1);
    int size = 0;
    size = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR) jcstr, length, rtn,(length * 2 + 1), NULL, NULL);
    if (size <= 0)
        return NULL;
    (env)->ReleaseStringChars(jstr, jcstr);
    rtn[size] = 0;
    return rtn;
}

// 由于jvm和c++对中文的编码不一样，因此需要转码 gb2312转换成utf8/16
jstring charTojstring(JNIEnv* env, const char* str) {
    jstring rtn = 0;
    int slen = strlen(str);
    unsigned short * buffer = 0;
    if (slen == 0)
        rtn = (env)->NewStringUTF(str);
    else {
        int length = MultiByteToWideChar( CP_ACP, 0, (LPCSTR) str, slen, NULL, 0);
        buffer = (unsigned short *) malloc(length * 2 + 1);
        if (MultiByteToWideChar( CP_ACP, 0, (LPCSTR) str, slen, (LPWSTR) buffer, length) > 0)
            rtn = (env)->NewString((jchar*) buffer, length);
        // 释放内存
        free(buffer);
    }
    return rtn;
}

// string 和 jstring 互相转换
// string 转换成 jstring ：通常是将 string 转换成 char*， 然后在再将char*转换成jstring
/*

   std::string str = "abc";
   // string 转 char*
   char* chardata = str.c_str();
   // char* 转 string
   jstring jstr = charTojstring(env, chardata);

*/

// jstring 转换成 string ：通常是将 jstring 转换成 char*， 然后在再将char*转换成 string
/*

   // jstring 转 char*
   char* chardata = jstringToChar(env, jstr);
   // char* 转 string
   std::string str = charData;

*/


/*
char* 和 jstring 第二种互相转换写法


jstring charTojstring(JNIEnv* env, const char* pat) {
    //定义java String类 strClass
    jclass strClass = (env)->FindClass("Ljava/lang/String;");
    //获取String(byte[],String)的构造器,用于将本地byte[]数组转换为一个新String
    jmethodID ctorID = (env)->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
    //建立byte数组
    jbyteArray bytes = (env)->NewByteArray(strlen(pat));
    //将char* 转换为byte数组
    (env)->SetByteArrayRegion(bytes, 0, strlen(pat), (jbyte*) pat);
    // 设置String, 保存语言类型,用于byte数组转换至String时的参数
    jstring encoding = (env)->NewStringUTF("GB2312");
    //将byte数组转换为java String,并输出
    return (jstring) (env)->NewObject(strClass, ctorID, bytes, encoding);
}

char* jstringToChar(JNIEnv* env, jstring jstr) {
    char* rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("GB2312");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid, strencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char*) malloc(alen + 1);
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);
    return rtn;
}



*/





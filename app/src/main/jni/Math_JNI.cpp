//
// Created by zhouwei11 on 2018/1/19.
//

#include "com_zhouwei_jnisample1_business_JNIMath.h"

JNIEXPORT jint JNICALL Java_com_zhouwei_jnisample1_business_JNIMath_Add(JNIEnv * env, jobject jobj, jdouble a, jdouble b)
{
      return a+b;
}

JNIEXPORT jint JNICALL Java_com_zhouwei_jnisample1_business_JNIMath_Sub(JNIEnv * env, jobject jobj, jdouble a, jdouble b)
{
    return a-b;
}

JNIEXPORT jint JNICALL Java_com_zhouwei_jnisample1_business_JNIMath_Mul(JNIEnv * env, jobject jobj, jdouble a, jdouble b)
{
    return a*b;
}

JNIEXPORT jint JNICALL Java_com_zhouwei_jnisample1_business_JNIMath_Div(JNIEnv * env, jobject jobj, jdouble a, jdouble b)
{
    return a/b;
}
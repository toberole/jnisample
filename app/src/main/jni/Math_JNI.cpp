//
// Created by zhouwei11 on 2018/1/19.
//

#include "com_zhouwei_jnisample1_business_JNIMath.h"

/*

    JNIEnv* 是指向虚拟机的指针，jobject 是指向从 Java 端传递的隐式 this 对象的指针。

    以下代码行调用虚拟机 API (*env) 并向其传递返回值（即 Java 端函数请求的字符串）。

    return (*env)->NewStringUTF(env, "Hello from JNI !
    Compiled with ABI " ABI ".");

*/




/*
    在C语言中标准输出的方法是printf，但是打印出来的内容在logcat看不到，需要使用
    __android_log_print()方法打印log，才能在logcat看到，由于该方法名比较长，我们在
    这里需要定义宏，使得在C语言中能够向Android一样打印log。
    注意：该方法还需要在gradle中声明ldLibs "log"，详见build.gradle
*/

/*
必带的两个参数：
        - JNIEnv：是结构体JNINativeInterface的一级指针，即JNINativeInterface*，
                结构体JNINativeInterface：接口函数指针表，该表就是用来Java和C语言之间进行交互的，
                包含着Java变量和C变量之间的对应关系，可以用于变量之间的转换。
          JNIEnv* env：是JNIEnv的一级指针，
                是结构体JNINativeInterface的二级指针，即JNINativeInterface**
        - jobject this：谁调用了这个本地函数，那么这个this就是指的哪个对象

*/


/*
    通过在jni.h的结构体JNINativeInterface中查找jstring，可以找到将C语言的字符串转换成
    Java字符串的代码：
            const struct JNINativeInterface* functions;
            jstring NewStringUTF(const char* bytes){
                return functions->NewStringUTF(this, bytes);
            }
        即：JNINativeInterface*->NewStringUTF(*env, str)
        即：(env*)->NewStringUTF(*env, str)
        将str转换并保存在结构体中，然后使用间接引用运算符->来获得这个jstring成员。

    在这里，结构体是JNINativeInterface，他的一级指针是JNIEnv，即*env(因为env又是JNIEnv的一级指针)。
    所以(*env)->NewStringUTF(env, str)就相当于JNINativeInterface.jstring，表示该结构体内的
    jstring格式的变量。
*/


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
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := test # 生成so的名字

LOCAL_SRC_FILES =: Math_JNI.cpp \
                   demo.cpp \
                   C_Callback_Java.cpp

include $(BUILD_SHARED_LIBRARY)

# Android.mk android studio用来编译JNI工程的makefile文件 如果是不使用android studio 那么可以不需要这个文件
# 此mkfile用来编译c文件 生成so用的
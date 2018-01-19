LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := test # 生成so的名字

LOCAL_SRC_FILES =: Math_JNI.cpp

include $(BUILD_SHARED_LIBRARY)

# 此mkfile用来编译c文件 生成so用的
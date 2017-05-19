#Encode	: utf-8 NO BOM
#Editor	: hanloong ho 
#Data	: 2017.05.19
#Title	: Android killall 
#Url	: https://github.com/CatDroid/killall.git

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)    
LOCAL_MODULE := killall
LOCAL_SRC_FILES += killall.c
LOCAL_LDLIBS := -llog -lEGL -lGLESv2 -ljnigraphics -landroid
#include $(BUILD_SHARED_LIBRARY)
include $(BUILD_EXECUTABLE)
	
# openGL &EGL:	-lEGL -lGLESv2   
# __log_write:	-llog 
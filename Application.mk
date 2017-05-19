#Encode	: utf-8 NO BOM
#Editor	: hanloong ho 
#Data	: 2017.05.19
#Title	: Android killall 
#Url	: https://github.com/CatDroid/killall.git

APP_BUILD_SCRIPT := Android.mk  
APP_PLATFORM := android-19
APP_STL := stlport_static
APP_ABI := arm64-v8a

#APP_ABI := armeabi-v7a 

#必须指定 APP_BUILD_SCRIPT := Android.mk 因为默认在jni目录下找Android.mk jni/Android.mk
#否则错误：  
#Android NDK: There is no Android.mk under ./jni    
#Android NDK: If this is intentional  please define APP_BUILD_SCRIPT to point   
#Android NDK: to a valid NDK build script.

#APP_STL 可选   stlport_static  stlport_shared 
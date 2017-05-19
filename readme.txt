Encode	: utf-8 NO BOM
Editor	: hanloong ho 
Data	: 2017.05.19
Title	: Android killall 
Url		: https://github.com/CatDroid/killall.git


编译:
	ndk-build NDK_PROJECT_PATH=. NDK_APPLICATION_MK=Application.mk
推送
	push.bat 
	
	
ndk-build NDK_DEBUG=1     编译为可调试版的二进制文件 gdb 
ndk-build NDK_DEBUG=0     编译为release版 
ndk-build V=1             执行ndk-build且打印出它所执行的详细编译命令。
ndk-build -B              强制重新编译
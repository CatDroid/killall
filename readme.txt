Encode	: utf-8 NO BOM
Editor	: hanloong ho 
Data	: 2017.05.19
Title	: Android killall 
Url		: https://github.com/CatDroid/killall.git


����:
	ndk-build NDK_PROJECT_PATH=. NDK_APPLICATION_MK=Application.mk
����
	push.bat 
	
	
ndk-build NDK_DEBUG=1     ����Ϊ�ɵ��԰�Ķ������ļ� gdb 
ndk-build NDK_DEBUG=0     ����Ϊrelease�� 
ndk-build V=1             ִ��ndk-build�Ҵ�ӡ������ִ�е���ϸ�������
ndk-build -B              ǿ�����±���
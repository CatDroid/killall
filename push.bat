::Encode	: utf-8 NO BOM
::Editor	: hanloong ho 
::Data		: 2017.05.19
::Title		: Android killall 
::Url		: https://github.com/CatDroid/killall.git


adb root
adb remount
adb push libs\arm64-v8a\killall /system/bin/
adb shell chmod 777 /system/bin/killall

pause 
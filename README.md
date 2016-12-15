# Breakpad-for-android
这是库简单封装了Google Breakpad, 加上jni层，让你一键集成Breakpad到项目中

# 如何使用

## 下载NDK
访问[Android官网](https://developer.android.com/ndk/downloads/index.html)，从这个网页，你可以直接下载对应操作系统的NDK

## 配置NDK
解压NDK，配置环境变量，以Mac为例，配置如下：

 	export NDK_HOME=/Users/nieyinyin/android-ndk-r10e
 	export PATH=${PATH}:${NDK_HOME}

## 编译
进入工程的根目录，直接运行：
`./build.sh`

编译后的.so文件所在：`sample/breakpad/libs`

## 集成到App
1. 拷贝.so文件到你项目的app/libs/
2. 拷贝sample/breakpad/src/main/java/cn/onlinecache/breakpad/NativeBreakpad.java到你的工程目录下，**注意：包名不能改哦！！**
3. 在你的Application类初始化：` NativeBreakpad.init(Environment.getExternalStorageDirectory().getAbsolutePath());`  注意：**这个方法所传的参数你可以直接定义**

## 你也可以无需编译，直接使用sample的breakpad module













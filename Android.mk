ROOT_PATH := $(call my-dir)
include $(ROOT_PATH)/third_party/breakpad/android/google_breakpad/Android.mk

LOCAL_PATH := $(ROOT_PATH)
include $(CLEAR_VARS)

LOCAL_MODULE    := breakpad
LOCAL_SRC_FILES := native_breakpad.cpp
LOCAL_LDLIBS := -llog
LOCAL_STATIC_LIBRARIES += breakpad_client

include $(BUILD_SHARED_LIBRARY)

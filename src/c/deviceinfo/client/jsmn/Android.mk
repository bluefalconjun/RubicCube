LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES = jsmn.c
LOCAL_MODULE := libjsmn
LOCAL_MODULE_TAGS := eng optional

include $(BUILD_SHARED_LIBRARY)

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)


LOCAL_MODULE := deviceinfo_collect
LOCAL_MODULE_TAGS := eng optional

LOCAL_SRC_FILES := \
	$(call all-c-files-under, .)

LOCAL_C_INCLUDES += $(LOCAL_PATH)/inc
LOCAL_CFLAGS += -Werror

include $(BUILD_EXECUTABLE)

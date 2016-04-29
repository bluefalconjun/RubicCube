LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := deviceinfo_collect
LOCAL_MODULE_TAGS := eng optional

LOCAL_SRC_FILES := \
	config_parser.c \
	devinfo_wrapper.c \
	info_client.c \
	info_recorder.c \
	loginfo_filter.c \
	loginfo_wrapper.c \
	client_main.c

LOCAL_C_INCLUDES += $(LOCAL_PATH)/inc

ifdef USE_XML_CONFIG
LOCAL_STATIC_LIBRARY += libtinyxml
endif

ifdef USE_JSMN_CONFIG
#jsmn is a tiny json file parser in C with MIT license.
LOCAL_SHARED_LIBRARIES = libjsmn
endif

LOCAL_CFLAGS +=

include $(BUILD_EXECUTABLE)

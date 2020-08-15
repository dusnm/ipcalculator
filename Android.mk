LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := ipcalculator
LOCAL_SRC_FILES := main.c ip.c cidr.c
include $(BUILD_EXECUTABLE)

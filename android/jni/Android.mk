LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := crossgl
LOCAL_SRC_FILES := ../../common/gl_cube.c crossgl.c
LOCAL_LDLIBS := -lGLESv1_CM


include $(BUILD_SHARED_LIBRARY)

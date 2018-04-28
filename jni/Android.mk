LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
include $(call all-subdir-makefiles)

LOCAL_SRC_FILES := \
        src/org_alcoholic_leaf_MainJni.cpp \
        src/sudu_main.cpp \
        src/sudu/BaseBlock.cpp \
        src/sudu/Controller.cpp \
        src/sudu/HorizontalBlock.cpp \
        src/sudu/RectBlock.cpp \
        src/sudu/VerticalBlock.cpp

LOCAL_C_INCLUDES := \
        $(LOCAL_PATH)/inc \
        $(LOCAL_PATH)/inc/sudu


LOCAL_MODULE := libleaf
LOCAL_CPPFLAGS := \
        -std=c++11

LOCAL_C_INCLUDES += $(NDK_ROOT)/sources/cxx-stl/stlport/stlport
LOCAL_LDLIBS := -llog #$(NDK_ROOT)/sources/cxx-stl/stlport/libs/armeabi/libstlport_shared.so
LOCAL_SHARED_LIBRARIES := $(NDK_ROOT)/sources/cxx-stl/stlport/libs/armeabi/libstlport_shared.so
APP_ALLOW_MISSING_DEPS := true

include $(BUILD_SHARED_LIBRARY)

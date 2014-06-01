# Copyright (C) 2009 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

#
# This file sets variables that control the way modules are built
# thorughout the system. It should not be used to conditionally
# disable makefiles (the proper mechanism to control what gets
# included in a build is to use PRODUCT_PACKAGES in a product
# definition file).
#

# inherit from common msm8960
-include device/samsung/msm8960-common/BoardConfigCommon.mk

TARGET_SPECIFIC_HEADER_PATH := device/samsung/d2lte/include

# Kernel
TARGET_KERNEL_SOURCE        := kernel/samsung/d2
BOARD_KERNEL_CMDLINE        := androidboot.hardware=qcom user_debug=31 zcache
BOARD_KERNEL_BASE           := 0x80200000
BOARD_MKBOOTIMG_ARGS        := --ramdisk_offset 0x01300000
BOARD_KERNEL_PAGESIZE       := 2048
TARGET_KERNEL_CONFIG        := cyanogen_d2_defconfig

TARGET_BOOTLOADER_BOARD_NAME := MSM8960

# WiFi module
WIFI_DRIVER_MODULE_PATH := "/system/lib/modules/dhd.ko"
WIFI_DRIVER_MODULE_NAME := "dhd"

# Adreno configuration
TARGET_QCOM_DISPLAY_VARIANT :=
TARGET_QCOM_MEDIA_VARIANT :=

# Recovery
BOARD_USE_CUSTOM_RECOVERY_FONT := \"roboto_15x24.h\"
BOARD_USES_MMCUTILS := true
BOARD_HAS_LARGE_FILESYSTEM := true
BOARD_HAS_NO_MISC_PARTITION := true
BOARD_HAS_NO_SELECT_BUTTON := true
BOARD_RECOVERY_SWIPE := true
TARGET_RECOVERY_FSTAB := device/samsung/d2lte/rootdir/etc/fstab.qcom

TARGET_USERIMAGES_USE_EXT4 := true
BOARD_BOOTIMAGE_PARTITION_SIZE := 0x00A00000
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 0x00A00000
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 1572864000
BOARD_USERDATAIMAGE_PARTITION_SIZE := 28651290624
BOARD_FLASH_BLOCK_SIZE := 131072

# QCOM
BOARD_USES_QCOM_HARDWARE := true
TARGET_USES_QCOM_BSP := true
COMMON_GLOBAL_CFLAGS += -DQCOM_HARDWARE -DQCOM_BSP -DUSE_COPYBIT_COMPOSITION_FALLBACK

# Vendor Init
TARGET_UNIFIED_DEVICE := true
TARGET_INIT_VENDOR_LIB := libinit_d2lte
TARGET_LIBINIT_DEFINES_FILE := device/samsung/d2lte/init/init_d2lte.c

# bluetooth
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := device/samsung/d2lte/bluetooth
BOARD_BLUEDROID_VENDOR_CONF := device/samsung/d2lte/bluetooth/vnd_d2.txt

# Disable initlogo, Samsungs framebuffer is weird
TARGET_NO_INITLOGO := true

# Use Audience A2220 chip
BOARD_HAVE_AUDIENCE_A2220 := true

# Use USB Dock Audio
BOARD_HAVE_DOCK_USBAUDIO := true

# Time services
BOARD_USES_QC_TIME_SERVICES := true

# Samsung's nonstandard csd-client
BOARD_HAVE_NEW_QCOM_CSDCLIENT := true

# GPS
BOARD_VENDOR_QCOM_GPS_LOC_API_HARDWARE := $(TARGET_BOARD_PLATFORM)
TARGET_NO_RPC := true
TARGET_PROVIDES_GPS_LOC_API := true
BOARD_HAVE_NEW_QC_GPS :=

#camera abi compatiblily
TARGET_DISPLAY_INSECURE_MM_HEAP := true
COMMON_GLOBAL_CFLAGS += -DQCOM_BSP_CAMERA_ABI_HACK
#TARGET_NEED_DISABLE_AUTOFOCUS := true
ifeq ($(filter cm_apexqtmo cm_expressatt,$(TARGET_PRODUCT)),)
  TARGET_NEED_CAMERA_ZSL := true
  TARGET_ADD_ISO_MODE_1600 := true
else
  TARGET_NEED_PREVIEW_SIZE_FIXUP := true
endif
TARGET_NEED_DISABLE_FACE_DETECTION := true

# Needed for blobs
COMMON_GLOBAL_CFLAGS += -DNEEDS_VECTORIMPL_SYMBOLS

# Separate audio devices for VOIP
BOARD_USES_SEPERATED_VOIP := true

ifeq ($(filter cm_apexqtmo cm_expressatt cm_d2dcm,$(TARGET_PRODUCT)),)
# Assert
TARGET_OTA_ASSERT_DEVICE := d2att,d2spr,d2spi,d2tfnspr,d2tmo,d2cri,d2mtr,d2usc,d2vmu,d2vzw,d2lte
endif

# Releasetools
TARGET_RELEASETOOLS_EXTENSIONS := device/samsung/d2lte/releasetools

$(call inherit-product, device/samsung/d2lte/full_d2lte.mk)

#  Inherit All Mahdi APN's
$(call inherit-product, vendor/mahdi/config/cdma.mk)

# Inherit some common Mahdi stuff.
$(call inherit-product, vendor/mahdi/configs/common.mk)
$(call inherit-product, vendor/mahdi/config/common_full_phone.mk)

PRODUCT_NAME := mahdi_d2lte

# Copy device specific prebuilt files.
PRODUCT_COPY_FILES += \
    vendor/mahdi/prebuilt/bootanimations/BOOTANIMATION-1280x768.zip:system/media/bootanimation.zip

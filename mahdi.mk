$(call inherit-product, device/samsung/d2lte/full_d2lte.mk)

# Enhanced NFC
#$(call inherit-product, vendor/mahdi/config/nfc_enhanced.mk)

# Inherit some common mahdi stuff.
$(call inherit-product, vendor/mahdi/config/common_full_phone.mk)

# Copy device specific prebuilt files.
PRODUCT_COPY_FILES += \
    vendor/mahdi/prebuilt/common/bootanimations/BOOTANIMATION-1280x768.zip:system/media/bootanimation.zip

PRODUCT_NAME := mahdi_d2lte

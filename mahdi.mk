$(call inherit-product, device/samsung/d2lte/full_d2lte.mk)

# Enhanced NFC
#$(call inherit-product, vendor/mahdi/config/nfc_enhanced.mk)

# Inherit some common mahdi stuff.
$(call inherit-product, vendor/mahdi/config/common_full_phone.mk)

PRODUCT_NAME := mahdi_d2lte

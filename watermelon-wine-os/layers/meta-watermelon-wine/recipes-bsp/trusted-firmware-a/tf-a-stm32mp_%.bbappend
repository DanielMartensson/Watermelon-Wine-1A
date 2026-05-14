FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI += "file://0001-Change-USART2-to-USART6-for-early-boot-debug.patch"
SRC_URI += "file://0002-Avoid-LSE-temporary.patch"
SRC_URI += "file://0003-Add-INFO-messages-about-entering-functions.patch"

EXTRA_OEMAKE += "STM32MP_EARLY_CONSOLE=1" 
EXTRA_OEMAKE += "LOG_LEVEL=40"

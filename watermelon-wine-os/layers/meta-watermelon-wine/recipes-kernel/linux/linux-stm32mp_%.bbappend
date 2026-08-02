FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}/6.6:"

SRC_URI:append = " \
    file://tim-pwm.config \
    file://0001-Add-Soft-Reset-At-RLT8211F.patch \
    file://0002-Add-multiple-soft-reset-functions.patch \
"

KERNEL_CONFIG_FRAGMENTS:append = " ${WORKDIR}/tim-pwm.config"

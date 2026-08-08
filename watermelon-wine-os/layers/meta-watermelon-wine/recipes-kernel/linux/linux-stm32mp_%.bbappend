FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}/6.6:"

SRC_URI:append = " \
    file://tim-pwm.config \
"

KERNEL_CONFIG_FRAGMENTS:append = " ${WORKDIR}/tim-pwm.config"

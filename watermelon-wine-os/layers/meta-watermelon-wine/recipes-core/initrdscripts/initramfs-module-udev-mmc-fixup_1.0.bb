SUMMARY = "Fixup for detecting GPT partion on MMC SDCARDs"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"
RDEPENDS:${PN} = "initramfs-module-udev"

inherit allarch

FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI = "file://99-mmc-fixup.rules"

do_install:append() {
    install -d ${D}${sysconfdir}/udev/rules.d
    install -m 0644 ${WORKDIR}/99-mmc-fixup.rules ${D}${sysconfdir}/udev/rules.d/
}

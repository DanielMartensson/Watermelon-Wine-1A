SUMMARY = "ImWebBrowser"
DESCRIPTION = "A minimal, GPU-accelerated web browser."
SECTION = "www-client"
HOMEPAGE = "https://github.com/DanielMartensson/ImWebBrowser"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=19b5c44dd600b05d43b5bb78ad0bd491"

inherit cmake pkgconfig features_check

#REQUIRED_DISTRO_FEATURES = "x11"

DEPENDS = " \
	libsdl3 \
"

SRCREV = "40709e59e48d2bd409277b92495401a0713bc0f0"
BRANCH = "main"
SRC_URI = "git://github.com/DanielMartensson/ImWebBrowser.git;protocol=https;branch=${BRANCH}"

S = "${WORKDIR}/git"
PV = "1.0.0"

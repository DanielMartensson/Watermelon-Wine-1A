SUMMARY = "ImTube"
DESCRIPTION = "ImTube is a lightweight YouTube client for Linux."
SECTION = "multimedia"
HOMEPAGE = "https://github.com/DanielMartensson/ImTube"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=19b5c44dd600b05d43b5bb78ad0bd491"

inherit cmake pkgconfig features_check

#REQUIRED_DISTRO_FEATURES = "x11"

DEPENDS = " \
	virtual/egl \
	virtual/libgles2 \
	curl \
	gstreamer1.0 \
	gstreamer1.0-plugins-good \
"

SRCREV = "5f4b95b9280e130b3d29cc36600c825d0af8e543"
BRANCH = "main"
SRC_URI = "git://github.com/DanielMartensson/ImTube.git;protocol=https;branch=${BRANCH}"

S = "${WORKDIR}/git"
PV = "0.1.0"

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
	libsdl3 \
	nlohmann-json \
"

S = "${WORKDIR}/git"

PV = "0.1.0"
SRCREV = "5bec7e8b98e29882b94b4a47024c0ff66d5337d9"
BRANCH = "main"
SRC_URI = " \
	git://github.com/DanielMartensson/ImTube.git;protocol=https;branch=${BRANCH} \
"

EXTRA_OECMAKE = "-DIMTUBE_EMBEDDED:BOOL=ON -DIMTUBE_IMGUI_DIR:PATH=${S}/src/libraries/imgui"

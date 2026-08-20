SUMMARY = "ImTube"
DESCRIPTION = "ImTube is a lightweight YouTube client for Linux."
SECTION = "multimedia"
HOMEPAGE = "https://github.com/DanielMartensson/ImTube"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=19b5c44dd600b05d43b5bb78ad0bd491"

inherit cmake pkgconfig

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
SRCREV = "ca01fe09c038defb05f6c15116da42327c7eaf5b"
BRANCH = "main"
SRC_URI = " \
	git://github.com/DanielMartensson/ImTube.git;protocol=https;branch=${BRANCH} \
"

EXTRA_OECMAKE = "-DIMTUBE_EMBEDDED:BOOL=ON -DIMTUBE_IMGUI_DIR:PATH=${S}/src/libraries/imgui"

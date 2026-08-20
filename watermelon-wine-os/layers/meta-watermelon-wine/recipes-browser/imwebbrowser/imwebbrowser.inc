SUMMARY = "ImWebBrowser"
DESCRIPTION = "A minimal, GPU-accelerated web browser."
SECTION = "www-client"
HOMEPAGE = "https://github.com/DanielMartensson/ImWebBrowser"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=19b5c44dd600b05d43b5bb78ad0bd491"

inherit cmake pkgconfig

DEPENDS = " \
	libsdl3 \
	libwpe \
	wpebackend-fdo \
	wpewebkit \
	libepoxy \
	virtual/egl \
	vulkan-utility-libraries \
	glib-2.0 \
	wayland \
	libxkbcommon \
"

SRCREV = "b59ce89b4d0e28418df38d477f37c31b0bc21b97"
BRANCH = "main"
SRC_URI = "git://github.com/DanielMartensson/ImWebBrowser.git;protocol=https;branch=${BRANCH}"

EXTRA_OECMAKE = "-DIMWEBBROWSER_BACKEND_VULKAN=ON -DIMWEBBROWSER_BACKEND_OPENGL_ES=OFF"

S = "${WORKDIR}/git"
PV = "1.0.0"

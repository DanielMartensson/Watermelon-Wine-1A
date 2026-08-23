SUMMARY = "ImWebBrowser"
DESCRIPTION = "A minimal, GPU-accelerated kiosk web browser built on SDL3 + Dear ImGui + WPE WebKit."
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
	virtual/egl \
	virtual/libgles2 \
	glib-2.0 \
	wayland \
	libxkbcommon \
"

# Rendering backend: OpenGL ES 3 (default) or Vulkan. The Vulkan backend
# additionally needs the Vulkan loader/headers at build time.
VULKAN_BACKEND ??= "0"
EXTRA_OECMAKE += "${@bb.utils.contains('VULKAN_BACKEND', '1', \
	'-DIMWB_BACKEND_VULKAN=ON', '-DIMWB_BACKEND_VULKAN=OFF', d)}"

SRCREV = "a51cb2955d936b8912b2e51af71780c2e8617a79"
BRANCH = "main"
SRC_URI = "git://github.com/DanielMartensson/ImWebBrowser.git;protocol=https;branch=${BRANCH}"

S = "${WORKDIR}/git"
PV = "1.0.0"

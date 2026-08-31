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
	glib-2.0 \
	wayland \
	libxkbcommon \
"

# Rendering backend: OpenGL ES 3 (default) or Vulkan. The GLES backend needs
# the GLES headers; the Vulkan backend needs the Vulkan loader/headers instead
# (imgui_impl_vulkan carries precompiled SPIR-V, so no shader toolchain).
VULKAN_BACKEND ??= "0"
DEPENDS += "${@bb.utils.contains('VULKAN_BACKEND', '1', \
	'vulkan-headers vulkan-loader', 'virtual/libgles2', d)}"
EXTRA_OECMAKE += "${@bb.utils.contains('VULKAN_BACKEND', '1', \
	'-DIMWB_BACKEND_VULKAN=ON', '-DIMWB_BACKEND_VULKAN=OFF', d)}"
EXTRA_OECMAKE += "-DCMAKE_BUILD_TYPE=Release"

# WebRTC (GFN etc.): WebKit maps RTCPeerConnection onto GStreamer's webrtcbin.
# The runtime image needs the RTP/webrtc plugins + ICE (libnice) in the rootfs;
# decoding itself then rides on the SoC's GStreamer codecs (STM32 VPU for 1080p).
RDEPENDS:${PN} += " \
	gstreamer1.0 \
	gstreamer1.0-plugins-base \
	gstreamer1.0-plugins-good \
	gstreamer1.0-plugins-bad \
	libnice \
"

SRCREV = "1b474d170e44302c9fde5bff077c3dfea2aee4a3"
BRANCH = "main"
SRC_URI = "git://github.com/DanielMartensson/ImWebBrowser.git;protocol=https;branch=${BRANCH}"

S = "${WORKDIR}/git"
PV = "1.0.0"

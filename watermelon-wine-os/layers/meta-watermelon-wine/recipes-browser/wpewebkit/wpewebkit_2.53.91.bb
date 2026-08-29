SUMMARY = "WebKit web rendering engine for the WPE platform"
LICENSE = "BSD-2-Clause & LGPL-2.0-or-later"
LIC_FILES_CHKSUM = "file://Source/JavaScriptCore/COPYING.LIB;md5=d0c6d6397a5d84286dda758da57bd691 \
                    file://Source/WebCore/LICENSE-APPLE;md5=4646f90082c40bcf298c285f8bab0b12 \
                    file://Source/WebCore/LICENSE-LGPL-2;md5=36357ffde2b64ae177b2494445b79d21 \
                    file://Source/WebCore/LICENSE-LGPL-2.1;md5=a778a33ef338abbaf8b8a7c36b6eec80"

inherit cmake pkgconfig features_check

REQUIRED_DISTRO_FEATURES = "opengl"
WARN_QA:remove = "src-uri-bad"
CCACHE_DISABLE = "1"

DEPENDS += " \
    ruby-native gperf-native unifdef-native glib-2.0-native gettext-native \
    cairo harfbuzz freetype fontconfig pixman \
    libxml2 libxslt icu zlib \
    jpeg libpng libwebp sqlite3 \
    libgcrypt libgpg-error libtasn1 \
    libsoup libwpe wpebackend-fdo libepoxy virtual/egl \
    wayland wayland-protocols wayland-native libxkbcommon \
    systemd libdrm virtual/libgbm \
    gstreamer1.0 gstreamer1.0-plugins-base gstreamer1.0-plugins-bad \
    vulkan-headers vulkan-loader vulkan-volk \
    lcms libbacktrace libavif libjxl \
"

EXTRA_OECMAKE = " \
    -DPORT=WPE \
    -DENABLE_MINIBROWSER=OFF \
    -DENABLE_BUBBLEWRAP_SANDBOX=OFF \
    -DENABLE_THUNDER=OFF \
    -DENABLE_JOURNALD_LOG=OFF \
    -DUSE_SYSTEM_SYSPROF_CAPTURE=OFF \
    -DUSE_ATK=OFF \
    -DUSE_AVIF=ON \
    -DUSE_JPEGXL=ON \
    -DUSE_WOFF2=OFF \
    -DUSE_LCMS=ON \
    -DUSE_LIBHYPHEN=OFF \
    -DUSE_LIBBACKTRACE=ON \
    -DUSE_LIBDRM=ON \
    -DUSE_GBM=ON \
    -DUSE_VULKAN=ON \
    -DENABLE_DOCUMENTATION=OFF \
    -DENABLE_INTROSPECTION=OFF \
    -DENABLE_SPELLCHECK=OFF \
    -DENABLE_SPEECH_SYNTHESIS=OFF \
    -DENABLE_WPE_PLATFORM_DRM=OFF \
    -DENABLE_WPE_PLATFORM_WAYLAND=OFF \
    -DENABLE_WPE_QT_API=OFF \
    -DCMAKE_BUILD_TYPE=Release \
    -DENABLE_JIT=ON \
"

EXTRA_OECMAKE:remove:armv4 = "-DENABLE_JIT=ON"
EXTRA_OECMAKE:append:armv4 = "-DENABLE_JIT=OFF"
EXTRA_OECMAKE:remove:armv5 = "-DENABLE_JIT=ON"
EXTRA_OECMAKE:append:armv5 = "-DENABLE_JIT=OFF"
EXTRA_OECMAKE:remove:armv6 = "-DENABLE_JIT=ON"
EXTRA_OECMAKE:append:armv6 = "-DENABLE_JIT=OFF"

DEBUG_FLAGS:append = "${@oe.utils.vartrue('DEBUG_BUILD', '', ' -g1', d)}"
CXXFLAGS += "${@bb.utils.contains('DISTRO_FEATURES', 'x11', '', ' -DEGL_NO_X11=1', d)}"
SECURITY_CFLAGS:remove:aarch64 = "-fpie"
SECURITY_CFLAGS:append:aarch64 = " -fPIE"

FILES:${PN} += "${libdir}/wpe-*/ ${libexecdir}/wpe-* ${datadir}/wpe-webkit-*/*"
RRECOMMENDS:${PN} += "ca-certificates vulkan-loader"

SRC_URI = "https://wpewebkit.org/releases/${BPN}-${PV}.tar.xz"
SRC_URI[sha256sum] = "4053ae3386b7f9b1b3b6d4b6e05392a81ee29bbb716776a5a433d7a23bc8f8ec"

# Fix GCC 13.x: _Atomic keyword not available in C++ mode
do_configure:prepend() {
    sed -i 's|^#include <stdatomic.h>$|#if defined(__cplusplus)\n#include <atomic>\nusing std::atomic_bool;\nusing std::atomic_int;\nusing std::atomic_uint;\nusing std::atomic_long;\nusing std::atomic_ulong;\nusing std::atomic_ullong;\n#else\n#include <stdatomic.h>\n#endif|' \
        ${S}/Source/bmalloc/libpas/src/libpas/pas_utils.h
}

S = "${WORKDIR}/${BPN}-${PV}"

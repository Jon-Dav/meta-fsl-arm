# Provides the i.MX common settings

include conf/machine/include/fsl-default-settings.inc
include conf/machine/include/fsl-default-versions.inc
include conf/machine/include/fsl-default-providers.inc

include conf/machine/include/soc-family.inc

# Set specific make target and binary suffix
UBOOT_MAKE_TARGET = "u-boot.imx"
UBOOT_SUFFIX ?= "imx"

UBOOT_ENTRYPOINT_mx3 = "0x80008000"
UBOOT_ENTRYPOINT_mx51  = "0x90008000"
UBOOT_ENTRYPOINT_mx53  = "0x70008000"
UBOOT_ENTRYPOINT_mx6  = "0x10008000"
UBOOT_ENTRYPOINT_mx6sl = "0x80008000"
UBOOT_ENTRYPOINT_mx6sx = "0x80008000"
UBOOT_ENTRYPOINT_vf = "0x80008000"

XSERVER_DRIVER = "xf86-video-fbdev"
XSERVER_DRIVER_mx5 = "xf86-video-imxfb"
XSERVER_DRIVER_mx6 = "xf86-video-imxfb-vivante"
XSERVER = "xserver-xorg \
           xf86-input-evdev \
           ${XSERVER_DRIVER}"

PREFERRED_VERSION_directfb_mx6 = "1.7.4"

# Ship kernel modules
MACHINE_EXTRA_RRECOMMENDS = "kernel-modules"

# Float-Point setting
# handled by software
# DEFAULTTUNE_mx6 ?= "cortexa9-neon"
# handled by hardware
DEFAULTTUNE_mx6 ?= "cortexa9hf-neon"

# Sub-architecture support
MACHINE_SOCARCH ?= ""
MACHINE_SOCARCH_mx3 = "${TUNE_PKGARCH}-mx3"
MACHINE_SOCARCH_mx5 = "${TUNE_PKGARCH}-mx5"
MACHINE_SOCARCH_mx6q = "${TUNE_PKGARCH}-mx6qdl"
MACHINE_SOCARCH_mx6dl = "${TUNE_PKGARCH}-mx6qdl"
MACHINE_SOCARCH_mx6sx = "${TUNE_PKGARCH}-mx6sx"
MACHINE_SOCARCH_mx6sl = "${TUNE_PKGARCH}-mx6sl"
MACHINE_SOCARCH_vf60 = "${TUNE_PKGARCH}-vf60"
MACHINE_SOCARCH_vf50 = "${TUNE_PKGARCH}-vf50"
PACKAGE_EXTRA_ARCHS_append = " ${MACHINE_SOCARCH}"

MACHINE_ARCH_FILTER = "virtual/kernel"
MACHINE_SOCARCH_FILTER = "libfslcodec libfslvpuwrap libfslparser gst-fsl-plugins"
MACHINE_SOCARCH_FILTER_append_mx5 = " virtual/libgles1 virtual/libgles2 virtual/egl virtual/mesa virtual/libgl"
MACHINE_SOCARCH_FILTER_append_mx6 = " virtual/libopenvg virtual/libgles1 virtual/libgles2 virtual/egl virtual/mesa virtual/libgl virtual/libg2d"

INHERIT += "fsl-dynamic-packagearch"

# Firmware
MACHINE_FIRMWARE ?= ""
MACHINE_FIRMWARE_append_mx6q = " firmware-imx-vpu-imx6q"
MACHINE_FIRMWARE_append_mx6dl = " firmware-imx-vpu-imx6d"
MACHINE_FIRMWARE_append_mx53 = " firmware-imx-vpu-imx53 firmware-imx-sdma-imx53"
MACHINE_FIRMWARE_append_mx51 = " firmware-imx-vpu-imx51 firmware-imx-sdma-imx51"

# FIXME: Needs addition of firmware-imx of official BSPs
#MACHINE_FIRMWARE_append_mx35 = " firmware-imx-sdma-imx35"
#MACHINE_FIRMWARE_append_mx31 = " firmware-imx-sdma-imx31"
#MACHINE_FIRMWARE_append_mx27 = " firmware-imx-vpu-imx27"
#MACHINE_FIRMWARE_append_mx25 = " firmware-imx-sdma-imx25"

MACHINE_EXTRA_RRECOMMENDS += "${MACHINE_FIRMWARE}"

# Extra audio support
# FIXME: Add support for ALL SoC families
MACHINE_EXTRA_RRECOMMENDS_append_mx6 = " ${@base_contains('DISTRO_FEATURES', 'alsa', 'fsl-alsa-plugins', '', d)}"

# Extra udev rules
MACHINE_EXTRA_RRECOMMENDS += "udev-rules-imx"

# GStreamer 0.10 plugins
MACHINE_GSTREAMER_PLUGIN ?= "gst-fsl-plugin"
MACHINE_GSTREAMER_PLUGIN_mx3 ?= ""
MACHINE_GSTREAMER_PLUGIN_vf ?= ""

# GStreamer 1.0 plugins
MACHINE_GSTREAMER_1_0_PLUGIN ?= ""
MACHINE_GSTREAMER_1_0_PLUGIN_mx6q ?= "gstreamer1.0-plugins-imx-meta"
MACHINE_GSTREAMER_1_0_PLUGIN_mx6dl ?= "gstreamer1.0-plugins-imx-meta"

# mx5 GPU libraries
GPU_FLAVOUR = "${@base_contains('DISTRO_FEATURES', 'x11', 'x11-', '', d)}"
PREFERRED_PROVIDER_virtual/egl_mx5 ?= "amd-gpu-${GPU_FLAVOUR}bin-mx51"
PREFERRED_PROVIDER_virtual/libgles1_mx5 ?= "amd-gpu-${GPU_FLAVOUR}bin-mx51"
PREFERRED_PROVIDER_virtual/libgles2_mx5 ?= "amd-gpu-${GPU_FLAVOUR}bin-mx51"

# mx6 GPU libraries
PREFERRED_PROVIDER_virtual/egl_mx6 ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgles1_mx6q ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgles1_mx6dl ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgles1_mx6sx ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgles1_mx6sl ?= "mesa"
PREFERRED_PROVIDER_virtual/libgles2_mx6q ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgles2_mx6dl ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgles2_mx6sx ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgles2_mx6sl ?= "mesa"
PREFERRED_PROVIDER_virtual/libgl_mx6q ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgl_mx6dl ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgl_mx6sx ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgl_mx6sl ?= "mesa"
PREFERRED_PROVIDER_virtual/libg2d_mx6 ?= "imx-gpu-viv"

PREFERRED_PROVIDER_virtual/kernel_mx3 ?= "linux-fslc"

SDCARD_ROOTFS ?= "${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}.rootfs.ext3"
IMAGE_FSTYPES ?= "tar.bz2 ext3 sdcard"

SERIAL_CONSOLE = "115200 ttymxc0"

KERNEL_IMAGETYPE = "zImage"

MACHINE_FEATURES = "apm usbgadget usbhost vfat alsa touchscreen"

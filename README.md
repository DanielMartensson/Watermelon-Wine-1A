# Watermelon-Wine-1A

Clone this repository and go to

```c
cd watermelon-wine-os
```
Download the `STM32MPU Distribution Package OpenSTLinux distribution`. 
```C
repo init -u https://github.com/STMicroelectronics/oe-manifest.git -b refs/tags/openstlinux-6.6-yocto-scarthgap-mpu-v26.02.18
```
Sync the `STM32MPU Distribution Package OpenSTLinux distribution`. 
```C
repo sync
```
Create the `build` folder with the `stm32mp25-mx`machine for `openstlinux`.
```c
DISTRO=openstlinux-weston MACHINE=stm32mp25-mx source layers/meta-st/scripts/envsetup.sh
```
Once the `build-openstlinux-weston-stm32mp25-mx` has been created, then go into that folder
```c
cd build-openstlinuxweston-stm32mp25-mx
```
Then add `watermelone-wine`layer
```c
bitbake-layers add-layer ../layers/meta-watermelon-wine
```
Check that the `watermelon-wine` layer has been added to your `build-openstlinuxweston-stm32mp25-mx`.
```c
bitbake-layers show-layers
```
The output from `bitbake-layers show-layers` should look something like this:
```c
NOTE: Starting bitbake server...
NOTE: Started PRServer with DBfile: /home/mint/Documents/Github/Watermelon-Wine-1A/watermelon-wine-os/build-openstlinuxweston-stm32mp25-mx/cache/prserv.sqlite3, Address: 127.0.0.1:36445, PID: 19338
layer                 path                                                                    priority
========================================================================================================
stm-st-stm32mp-mx     /home/mint/Documents/Github/Watermelon-Wine-1A/watermelon-wine-os/layers/meta-st/meta-st-stm32mp-addons  7
meta-python           /home/mint/Documents/Github/Watermelon-Wine-1A/watermelon-wine-os/layers/meta-openembedded/meta-python  5
openembedded-layer    /home/mint/Documents/Github/Watermelon-Wine-1A/watermelon-wine-os/layers/meta-openembedded/meta-oe  5
gnome-layer           /home/mint/Documents/Github/Watermelon-Wine-1A/watermelon-wine-os/layers/meta-openembedded/meta-gnome  5
multimedia-layer      /home/mint/Documents/Github/Watermelon-Wine-1A/watermelon-wine-os/layers/meta-openembedded/meta-multimedia  5
networking-layer      /home/mint/Documents/Github/Watermelon-Wine-1A/watermelon-wine-os/layers/meta-openembedded/meta-networking  5
webserver             /home/mint/Documents/Github/Watermelon-Wine-1A/watermelon-wine-os/layers/meta-openembedded/meta-webserver  5
stm-st-stm32mp        /home/mint/Documents/Github/Watermelon-Wine-1A/watermelon-wine-os/layers/meta-st/meta-st-stm32mp  6
st-openstlinux        /home/mint/Documents/Github/Watermelon-Wine-1A/watermelon-wine-os/layers/meta-st/meta-st-openstlinux  5
core                  /home/mint/Documents/Github/Watermelon-Wine-1A/watermelon-wine-os/layers/openembedded-core/meta  5
watermelon-wine       /home/mint/Documents/Github/Watermelon-Wine-1A/watermelon-wine-os/layers/meta-watermelon-wine  8
```
If the layer `watermelon-wine` has been added. Then open the `local.conf` file inside the `build-openstlinuxweston-stm32mp25-mx` folder.
```c
nano conf/local.conf
```
Select the correct machine by renaming
```c
MACHINE=stm32mp25-mx
```
To 
```c
MACHINE=watermelon-wine-1a
BB_NUMBER_THREADS = "4"
PARALLEL_MAKE = "-j4"
```
You could use `4, 6, 8` depending how fast CPU you're using. Number `4` is recommended for `8GB` in RAM.
Then save the `local.conf`file. 
Then build the official `OpenSTLinux`.

```c
bitbake st-image-weston
```

Or buid other `OpenSTLinux`.

```c
bitbake st-image-core
```

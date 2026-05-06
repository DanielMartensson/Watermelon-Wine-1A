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
Set the machine `stm32mp25-mx`
```c
DISTRO=openstlinux-weston MACHINE=stm32mp25-mx source layers/meta-st/scripts/envsetup.sh
```
Once the `build-openstlinux-weston-stm32mp25-mx` has been created, then go into that folder
```c
cd build-openstlinuxweston-stm32mp25-mx
```
Then open the `local.conf` file
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
```
Then save the `local.conf`file.

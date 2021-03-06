# IP Calculator

## About

### A small program to calculate various parameters given the IPv4 address and subnet mask.

## Installation

Arch Linux users can get the softwafre from the AUR:

* Example with yay
```
yay -S ipcalculator
```


1. Using CMAKE

```
mkdir build && cd build
cmake ..
make 
sudo make install
```

2. Using Makefile

```
make
sudo make install
```

## Uninstallation
```
sudo make uninstall
```

## Building for Android (Android NDK)
```
ndk-build NDK_APPLICATION_MK=`pwd`/Application.mk
```
### The binary is in the obj directory.

## Example usage

```
ipcalculator 192.168.1.1/24
```

## Example output

```
IP address: 192.168.1.1
Subnet mask: 255.255.255.0
Wildcard subnet mask: 0.0.0.255
Network address: 192.168.1.0
Broadcast address: 192.168.1.255
First host address: 192.168.1.1
Last host address: 192.168.1.254
```

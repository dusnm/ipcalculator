# IP Calculator

## About

### A small program to calculate various parameters given the IPv4 address and subnet mask.

## Installation


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

## Example usage

```
ipcalc 192.168.1.1/24
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
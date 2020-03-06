#ifndef CIDR_H
#define CIDR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void cidr_to_ip_and_mask(const char* cidr, uint32_t* ip_address, uint32_t* subnet_mask);

#endif
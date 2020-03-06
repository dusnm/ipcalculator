#ifndef DOTDECIMAL_H
#define DOTDECIMAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void convert_to_dot_decimal(uint32_t ip_address_or_subnet_mask, char* result);

#endif
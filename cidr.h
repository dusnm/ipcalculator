#ifndef CIDR_H
#define CIDR_H

#include "ip.h"

typedef struct cidr
{
    ip_t ip_address;
    ip_t subnet_mask;
    ip_t wildcard_subnet_mask;
    ip_t network_address;
    ip_t broadcast_address;
    ip_t first_host_address;
    ip_t last_host_address;
} cidr_t;

void cidr_init(cidr_t* cidr);

int cidr_to_ip_and_mask(char* cidr_str, cidr_t* cidr);

void cird_print(cidr_t* cidr);

#endif

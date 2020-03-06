#include <stdio.h>
#include <string.h>
#include "cidr.h"

static char* FORMATS[] = {
    "IP address: %s\n",
    "Subnet mask: %s\n",
    "Wildcard subnet mask: %s\n",
    "Network address: %s\n",
    "Broadcast address: %s\n",
    "First host address: %s\n",
    "Last host address: %s\n",
};

void cidr_init(cidr_t* cidr)
{
    int size = sizeof(cidr_t) / sizeof(ip_t);

    for(int i = 0; i < size; i++) {
        ip_t* ip = (ip_t *) &cidr[i];

        *ip = ip_init();
    }
}

int cidr_to_ip_and_mask(char* cidr_str, cidr_t* cidr)
{
    int status;

    if((status = parse_ip(&cidr->ip_address, cidr_str)))
    {
        return status;
    }

    cidr->subnet_mask.address = (0xFFFFFFFFUL << (32 - cidr->ip_address.mask)) & 0xFFFFFFFFUL;
    cidr->subnet_mask.mask = cidr->ip_address.mask;
    cidr->network_address.address = (cidr->ip_address.address) & (cidr->subnet_mask.address);
    cidr->wildcard_subnet_mask.address = ~ (cidr->subnet_mask.address);
    cidr->broadcast_address.address = cidr->ip_address.address | cidr->wildcard_subnet_mask.address;
    cidr->first_host_address.address = cidr->network_address.address + 1;
    cidr->last_host_address.address = cidr->broadcast_address.address - 1;


    return IPV4_SUCCESS;
}


void cird_print(cidr_t* cidr)
{
    ip_t* ip_arr = (ip_t *) cidr;

    char buffer[IP_MAX_STRING_SIZE];

    int size = sizeof(cidr_t) / sizeof(ip_t);

    for(int i = 0; i < size; i++) {
        ip_t* ip = (ip_t *) &ip_arr[i];

        convert_to_dot_decimal( ip, buffer, IP_MAX_STRING_SIZE);
        printf(FORMATS[i], buffer);
        memset(buffer, 0, IP_MAX_STRING_SIZE);
    }
}

#include "cidr.h"

void cidr_to_ip_and_mask(const char* cidr, uint32_t* ip_address, uint32_t* subnet_mask)
{
    uint8_t part1, part2, part3, part4, subnet_mask_bits;

    if (sscanf(cidr, "%hhu.%hhu.%hhu.%hhu/%hhu", &part1, &part2, &part3, &part4, &subnet_mask_bits) < 5) {
        printf("Couldn't extract all parts of the CIDR address. Make sure you typed everything correctly.\n");
        exit(EXIT_FAILURE);
    }

    if (subnet_mask_bits > 32) {
        printf("Incorrect subnet mask. Range is 0-32\n");
        exit(EXIT_FAILURE);
    }

    *ip_address = (part1 << 24UL) | (part2 << 16UL) | (part3 << 8UL) | part4;
    *subnet_mask = (0xFFFFFFFFUL << (32 - subnet_mask_bits)) & 0xFFFFFFFFUL;
}
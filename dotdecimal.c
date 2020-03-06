#include "dotdecimal.h"

void convert_to_dot_decimal(uint32_t ip_address_or_subnet_mask, char* result) 
{
    uint8_t part1 = ip_address_or_subnet_mask >> 24UL;
    uint8_t part2 = (ip_address_or_subnet_mask >> 16UL) & 0xFFFFFFFFUL;
    uint8_t part3 = (ip_address_or_subnet_mask >> 8UL) & 0xFFFFFFFFUL;
    uint8_t part4 = ip_address_or_subnet_mask & 0xFFFFFFFFUL;
    
    char* part1_str = (char*) malloc(4 * sizeof(char));
    char* part2_str = (char*) malloc(4 * sizeof(char));
    char* part3_str = (char*) malloc(4 * sizeof(char));
    char* part4_str = (char*) malloc(4 * sizeof(char));

    sprintf(part1_str, "%u", part1);
    sprintf(part2_str, "%u", part2);
    sprintf(part3_str, "%u", part3);
    sprintf(part4_str, "%u", part4);

    strcat(result, part1_str);
    strcat(result, ".");
    strcat(result, part2_str);
    strcat(result, ".");
    strcat(result, part3_str);
    strcat(result, ".");
    strcat(result, part4_str);

    free(part1_str);
    free(part2_str);
    free(part3_str);
    free(part4_str);
}
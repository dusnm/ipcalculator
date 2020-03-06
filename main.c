#include "dotdecimal.h"
#include "cidr.h"

int main(int argc, char** argv)
{
     if (argc != 2) {
        printf("Incorrect CIDR format. Usage: %s <ip/mask>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    uint32_t ip_address;
    uint32_t subnet_mask;
    uint32_t wildcard_subnet_mask;
    uint32_t network_address;
    uint32_t broadcast_address;
    uint32_t first_host_address;
    uint32_t last_host_address;

    cidr_to_ip_and_mask(argv[1], &ip_address, &subnet_mask);

    char* ip_address_str = (char*) malloc(15 * sizeof(char));
    char* network_address_str = (char*) malloc(15 * sizeof(char));
    char* subnet_mask_str = (char*) malloc(15 * sizeof(char));
    char* wildcard_subnet_mask_str = (char*) malloc(15 * sizeof(char));
    char* broadcast_address_str = (char*) malloc(15 * sizeof(char));
    char* first_host_address_str = (char*) malloc(15 * sizeof(char));
    char* last_host_address_str = (char*) malloc(15 * sizeof(char));

    network_address = ip_address & subnet_mask;
    wildcard_subnet_mask = ~ subnet_mask;
    broadcast_address = ip_address | wildcard_subnet_mask;
    first_host_address = network_address + 1;
    last_host_address = broadcast_address - 1;

    convert_to_dot_decimal(ip_address, ip_address_str);
    convert_to_dot_decimal(subnet_mask, subnet_mask_str);
    convert_to_dot_decimal(wildcard_subnet_mask, wildcard_subnet_mask_str);
    convert_to_dot_decimal(network_address, network_address_str);
    convert_to_dot_decimal(broadcast_address, broadcast_address_str);
    convert_to_dot_decimal(first_host_address, first_host_address_str);
    convert_to_dot_decimal(last_host_address, last_host_address_str);

    printf("\n");
    printf("IP address: %s\n", ip_address_str);
    printf("Subnet mask: %s\n", subnet_mask_str);
    printf("Wildcard subnet mask: %s\n", wildcard_subnet_mask_str);
    printf("Network address: %s\n", network_address_str);
    printf("Broadcast address: %s\n", broadcast_address_str);
    printf("First host address: %s\n", first_host_address_str);
    printf("Last host address: %s\n", last_host_address_str);
   
    free(ip_address_str);
    free(network_address_str);
    free(subnet_mask_str);
    free(wildcard_subnet_mask_str);
    free(broadcast_address_str);
    free(first_host_address_str);
    free(last_host_address_str);

    exit(EXIT_SUCCESS);
}

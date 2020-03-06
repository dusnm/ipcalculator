#include <stdio.h>
#include <stdlib.h>
#include "cidr.h"

static void output_error(int status)
{
    switch (status)
    {
    case ERROR_IPV4_DATA_OVERFLOW:
        break;
    case ERROR_IPV4_INVALID_SYMBOL:
        break;
    case ERROR_IPV4_MASK_OVERFLOW:
        break;
    case ERROR_IPV4_NO_MASK:
        break;
    case ERROR_IPV4_NOT_ENAUGH_MEMORY:
        break;
    default:
        fprintf(stderr, "Unknown eror has occurred\n");
        break;
    }

}


int main(int argc, char** argv)
{

    cidr_t cidr;
    int status;

    if (argc != 2) {
        fprintf(stderr, "Incorrect CIDR format. Usage: %s <ip/mask>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    cidr_init(&cidr);

    status = cidr_to_ip_and_mask(argv[1], &cidr);

    if(status != IPV4_SUCCESS) {
        output_error(status);
        exit(EXIT_FAILURE);
    }

    cird_print(&cidr);

    exit(EXIT_SUCCESS);
}

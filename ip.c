#include <endian.h>
#include <stdio.h>
#include <stdlib.h>

#include "ip.h"


static unsigned long scan(register char *s, register unsigned long *u) {
    register unsigned int pos = 0;
    register unsigned long result = 0;
    register unsigned long c;

    while ((c = (unsigned long) (unsigned char) (s[pos] - '0')) < 10) {
        result = result * 10 + c;
        pos++;
    }
    *u = result;
    return pos;
}

ip_t ip_init() {
    ip_t ip;

    ip.address = 0;

    ip.mask = 0;

    return ip;
}


int parse_ip(ip_t *ip, char *ip_str) {
    uint32_t pos;
    char *s = ip_str;
    unsigned long u;


    // Parse IP
    for (int i = 0; i < 4; i++) {

        pos = scan(s, &u);


        if (!pos) {
            return ERROR_IPV4_INVALID_SYMBOL;
        }

        if (u > UINT8_MAX) {
            return ERROR_IPV4_DATA_OVERFLOW;
        }
        s += pos;

        if (*s != '.' && i != 3) {
            return ERROR_IPV4_INVALID_SYMBOL;
        }

        if (*s != '\0') {
            s++;
        }
# if __BYTE_ORDER == __LITTLE_ENDIAN
        ip->bytes[3 - i] = u;
#elif # if __BYTE_ORDER == __BIG_ENDIAN
        ip->bytes[i] = u;
#endif
    }

    // Parse Mask
    if (*s == '\0' || *(s - 1) != '/') {
        return ERROR_IPV4_NO_MASK;
    }


    if (!scan(s, &u)) {
        return ERROR_IPV4_INVALID_SYMBOL;
    }

    if (u > 32) {
        return ERROR_IPV4_MASK_OVERFLOW;
    }

    ip->mask = (uint8_t) u;


    return IPV4_SUCCESS;
}


char *convert_to_dot_decimal_heap(ip_t *ip) {
    char *buffer = calloc(IP_MAX_STRING_SIZE, sizeof(char));

    if (convert_to_dot_decimal(ip, buffer, IP_MAX_STRING_SIZE) != IPV4_SUCCESS) {
        return NULL;
    }

    return buffer;
}


int convert_to_dot_decimal(ip_t *ip, char *buffer, int size) {
    int result;

    if (size < IP_MAX_STRING_SIZE) {
        return ERROR_IPV4_NOT_ENAUGH_MEMORY;
    }

# if __BYTE_ORDER == __LITTLE_ENDIAN
    result = snprintf(buffer, size, "%u.%u.%u.%u", ip->bytes[3], ip->bytes[2], ip->bytes[1], ip->bytes[0]);
#elif # if __BYTE_ORDER == __BIG_ENDIAN
    result = snprintf(buffer, size, "%u.%u.%u.%u", ip->bytes[0], ip->bytes[1], ip->bytes[2], ip->bytes[3]);
#endif

    if (result < 0 || result >= size) {
        return ERROR_IPV4_NOT_ENAUGH_MEMORY;
    }

    return IPV4_SUCCESS;
}


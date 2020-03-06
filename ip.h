#include <stdint.h>

#ifndef IPCALC_IP
#define IPCALC_IP

#ifndef IP_MAX_STRING_SIZE
    #define IP_MAX_STRING_SIZE 20
#endif

#define IPV4_SUCCESS 0

#define ERROR_IPV4_DATA_OVERFLOW -1
#define ERROR_IPV4_INVALID_SYMBOL -2
#define ERROR_IPV4_NO_MASK -3
#define ERROR_IPV4_NOT_ENOUGH_MEMORY -4
#define ERROR_IPV4_MASK_OVERFLOW -5

typedef struct ip {
    union {
        uint8_t bytes[4];
        uint32_t address;
    };
    uint8_t mask;
} ip_t;

ip_t ip_init();

int parse_ip(ip_t* ip, char* ip_str);
char* convert_to_dot_decimal_heap(ip_t* ip);
int convert_to_dot_decimal(ip_t* ip, char* buffer, int size);
#endif

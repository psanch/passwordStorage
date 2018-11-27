#ifndef GET_SALTS
#define GET_SALTS

#include <stdint.h>

//Pre: num is the number of salts to be generated.
//      counters.txt holds salt_limit and salt_num.
//      
char* get_salt(const uint32_t num);

#endif

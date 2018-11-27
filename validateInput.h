
#ifndef VALIDATE_INPUT
#define VALIDATE_INPUT

#include <string.h>
#include <stdint.h>
#include <stdbool.h>

bool secure_copy(char* dest, const char* src, const uint32_t start, const uint32_t length);
bool validate_usr_name(const char* str);
bool validate_password(const char* str);

#endif

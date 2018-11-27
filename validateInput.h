
#ifndef VALIDATE_INPUT
#define VALIDATE_INPUT

#include <string.h>
#include <stdint.h>
#include <stdbool.h>

//Pre: src contains text to be copied.
//Post: if characters from src[start] to src[start+length], those characters
//      will be copied to dest[0..length-1] and the function will return true.
//      if other characters are encountered, the copy will stop and the
//      function will return false.
bool secure_copy(char* dest, const char* src, const uint32_t start, const uint32_t length);

//Returns true if str contains only alphanumeric characters and terminating '\0', false otherwise
bool validate_usr_name(const char* str);
//Returns true if str contains only alphanumeric characters, '_' and terminating '\0', false otherwise
bool validate_password(const char* str);

#endif

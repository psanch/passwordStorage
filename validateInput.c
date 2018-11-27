#include "validateInput"

bool secure_copy(char* dest, const char* src, const uint32_t start, const uint32_t length)
{
    if (start < length) return false;

    size_t n, i;
    if (sizeof(dest) < start + length)
        n = sizeof(dest) / sizeof(char);
    else
        n = start + length;

    for (i = start; i < n; ++i)
    {
        if (isalnum(src[i])) dest[i] = src[i];
        else if (src[i] == '\0')
        {
            dest[i] = '\0';
            return true;
        }
        else return false;
    }
    return true;
}

bool validate_usr_name(const char* str)
{
    size_t i = 0;
    while ((i < sizeof(str) / sizeof(char)) && str[i] != '\0')
    {
        if(!isalnum(str[i])) return false;
    }
    return true;
}

bool validate_password(const char* str)
{
    size_t i = 0;
    while ((i < sizeof(str) / sizeof(char)) && str[i] != '\0')
    {
        if(!(isalnum(str[i]) || str[i] == '_') return false;
    }
    return true;
}











//

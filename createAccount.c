//Current issues: where does username come from?
//How do I call argon2?

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "createAccount.h"
#include "validateInput.h"

int32_t createAccount()
{
    const int32_t command_length = 64;
    char command[command_length];

    strncpy(salt, "python3 ../getLatestSalt.py", command_length);
    system(command);

    FILE *salt_file = fopen("latestSalt.txt", "r");
    char *salt = malloc(4 * sizeof(char));
    fgets(salt, 4, salt_file);
    fclose(salt_file);
    //salt now contains the salt value as a c-string

    char *hash[22];
    //argon2 call???

    strcpy(command, "python3 ../createAccount.py ");

    secure_copy(, , 26, )

}








//

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "login.h"
#include "argon2.h"

//Pre: username and password hold the username and password.
//username and password are valid inputs to validate_usr_name and validate_password, respectively.
bool authenticate_login(const char* username, const char* password)
{
    const uint32_t
        command_length = 128,
        usr_length = 64,
        pwd_length = 64;
        t_cost = 10, m_cost = 16, parallelism = 4;
    const size_t
        salt_length = 32,
        hash_length = 22;

    if(!validate_usr_name(username))
    {
        fprintf(stderr, "Username %s contains invalid characters.\n", username);
        return false;
    }
    else if(!validate_password(password))
    {
        fprintf(stderr, "Password %s contains invalid characters.\n", password);
        return false;
    }
    else if(sizeof(username) / sizeof(char) > usr_length)
    {
        fprintf(stderr, "Username is too long.\n");
        return false;
    }
    else if(sizeof(password) / sizeof(char) > pwd_length)
    {
        fprintf(stderr, "Password is too long.\n");
        return false;
    }

    char command[command_length];

    strcpy(command, "python3 getRowFromUsername.py ");
    secure_copy(command, username, 23, command_length - 23);
    system(command);

    FILE* row_file = fopen("row.txt", "r");
    if (row_file == NULL)
    {
        fprintf(stderr, "Could not open row.txt\n");
        return false;
    }

    char usr_read[usr_length];

    fscanf(row_file, "%s", usr_read);
    if (usr_read == "-1")
    {
        fprintf(stderr, "Username %s not found.\n", username);
        return false;
    }

    char salt[salt_length];
    uint8_t hash[hash_length]; //Encoded hash will hold raw data
    fscanf(row_file, "%s", salt);
    fscanf(row_file, "%s", hash);

    fclose(row_file);

    if (argon2id_hash_encoded(t_cost, m_cost, parallelism,
                            password, pwd_len,
                            salt, salt_length,
                            hash, hash_length)
        == ARGON2_OK)
        return true;
    else
        return false;
}






//

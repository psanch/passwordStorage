#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "getSalts.h"

char* get_salt(const uint32_t num) {
    FILE *counter, *salts;

    counter = fopen("counters.txt", "r");
    salts = fopen("salts.txt", "r");

    if(counter == NULL)
    {
        fprintf(stderr, "Error opening counters.txt.\n");
        return NULL;
    }
    if(salts == NULL)
    {
        fprintf(stderr, "Error opening salts.txt.\n");
        return NULL;
    }

    uint32_t* salt_num = malloc(sizeof(uint32_t));
    uint32_t* salt_limit = malloc(sizeof(uint32_t));

    fscanf(counter, "%u", salt_limit); //Reads first number into salt_limit
    fscanf(counter, "%u", salt_num); //Copies hash number to be used into salt_num

    char* salt = malloc(32 * sizeof(char)); //32 byte salt
    for (uint32_t i = 0; i < num; ++i)
    {
        if(!(fscanf(f, "%32s", salt))) return NULL;
    }

    char* salt = get_salt(salts, salt_num);
    printf("%u", salt_num);

    fclose(counter);
    fclose(salts);

    salts = fopen("salts.txt", "w");
    fprintf(salts, "%u %u", *salt_limit, *salt_num);
    fclose(salts);

    free(salt_num);
    free(salt_limit);


    return salt;
}







//

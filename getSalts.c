#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

char* get_salt(const uint32_t num) {
    FILE *counter, *salts;

    counter = fopen("counters.txt", "r");
    salts = fopen("salts.txt", "r");

    uint32_t* salt_num = malloc(sizeof(uint32_t));
    uint32_t* salt_limit = malloc(sizeof(uint32_t));

    fscanf(counter, "%s", salt_limit); //Reads first number into salt_limit
    fscanf(counter, "%s", salt_num); //Copies hash number to be used into salt_num

    char* salt = malloc(32 * sizeof(char)); //32 byte salt
    for (uint32_t i = 0; i < num; ++i)
    {
        if(!(fscanf(f, "%32s", salt))) return NULL;
    }

    char* salt = get_salt(salts, salt_num);
    printf("%u", salt_num);
    //we need to update salt_num

    free(salt_num);
    free(salt_limit);
    fclose(counter);
    fclose(salts);

    return salt;
}

/*
char* get_salt(FILE f, uint32_t* num)
//Precondition: f is an open file containing one salt on each line
//num is the line number containing the salt to be accessed
//Postcondition: returns pointer to salt as a char[], or NULL on error
{

    return salt;
}*/




/*
getSalts.c:14:52: warning: incompatible pointer to integer conversion
      initializing 'uint32_t' (aka 'unsigned int') with an expression of type
      'void *' [-Wint-conversion]
  ...= malloc(sizeof(uint32_t)), salt_limit = malloc(sizeof(uint32_t));
                                 ^            ~~~~~~~~~~~~~~~~~~~~~~~~
getSalts.c:15:27: warning: format specifies type 'char *' but the argument has
      type 'uint32_t' (aka 'unsigned int') [-Wformat]
    fscanf(counter, "%s", salt_limit); //Reads first number into salt_limit
                     ~~   ^~~~~~~~~~
getSalts.c:16:27: warning: format specifies type 'char *' but the argument has
      type 'uint32_t *' (aka 'unsigned int *') [-Wformat]
    fscanf(counter, "%s", salt_num); //Copies hash number to be used int...
                     ~~   ^~~~~~~~
                     %u
getSalts.c:19:27: error: passing 'FILE *' (aka 'struct __sFILE *') to parameter
      of incompatible type 'FILE' (aka 'struct __sFILE'); dereference with *
    char* salt = get_salt(salts, salt_num);
                          ^~~~~
                          *
getSalts.c:6:21: note: passing argument to parameter 'f' here
char* get_salt(FILE f, uint32_t* num);
                    ^
getSalts.c:20:18: warning: format specifies type 'unsigned int' but the argument
*/





//

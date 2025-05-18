/* This is a simple library that encrypts and decrypts strings currently it has a max of one thousand characters message size.
This library is still in development and currently is very limited. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union secret
    {
        char chars[1001];
        int ints[251];
    };

void encode(const char * input, int key)
{

    union secret message;

    switch (key)
    {
        case 1:
            strcpy(message.chars, input);
            for (int i = 0; i < 251; ++i)
                message.chars[i] = ~message.chars[i];

        default:
            strcpy(message.chars, input);

    }

    for(int i = 0; i < 251; ++i)
        printf("%d.", message.ints[i]);
    printf("\n");
}

void decode(const char * input, int key)
{
    char * dup = strdup(input);

    union secret decrypt;

    char * token = strtok(dup, ".");

    while (token != NULL)
    {
        int value = atoi(token);

        token = strtok(NULL, ".");

        static int i = 0;

        decrypt.ints[i] = value;

        ++i;
    }

    switch (key)
    {
        case 1:
            break;
        
        default:
            for(int i = 0; i < 1001; ++i)
                decrypt.chars[i] = ~decrypt.chars[i];
    }

    printf("%s\n", decrypt.chars);
}
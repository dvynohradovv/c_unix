#include "string.h"
#include "stdio.h"
#include "stdlib.h"

char **split(char *string, char *delimiters)
{
    char *pch;
    char **result;
    pch = strtok(string, delimiters);
    long unsigned size = sizeof(char *);
    result = malloc(size);
    
    int n = 0;
    while (pch != NULL)
    {
        result[n] = pch;
        pch = strtok(NULL, delimiters);
        n++;
        size += sizeof(char *);
        result = realloc(result, size);
    }
    result[n] = NULL;
    return result;
}
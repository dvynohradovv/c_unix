#include <stdlib.h>
#include <string.h>

#include "secondaryfunctions.h"

char** Split(char* string, char* delimiters)
{
    char* pch;
    char** result;
    pch = strtok(string, delimiters);

    int n = 0, delim_len = strlen(delimiters);
    int str_len = strlen(string);
    char curr;
    for (int i = 0; i < str_len; ++i) 
    {
        curr = string[i];

        for (int j = 0; j < delim_len; ++j) 
        {
            if (curr == delimiters[j]) 
            {
                ++n;
            }
        }
    }

    long unsigned size = sizeof(char*);
    result = malloc(size * n);

    int i = 0;
    while (pch != NULL)
    {
        result[i] = pch;
        pch = strtok(NULL, delimiters);
        i++;

    }

    result[i] = NULL;
    return result;
}


char* GetNameFromPathLine(char* path_line) 
{
    //Получить имя из конструкции 'имя=зачение'.

    char* curr = path_line;

    while (*curr != '\n' && *curr != '\0' && *curr != '=') 
    {
        ++curr;
    }

    int name_length = curr - path_line;
    size_t name_mem_size = sizeof(char) * name_length;
    char* res = malloc(name_mem_size);
    memcpy(res, path_line, name_mem_size);
    res[name_length] = '\0';

    return res;
}
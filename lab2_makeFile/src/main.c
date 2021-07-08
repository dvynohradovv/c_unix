#include "../include/func.h"
#include "../include/print.h"
#include "../include/defs.h"
#include "../include/wordfunc.h"
#include <stdio.h>
int main()
{
    char str[MAX_STRING_SIZE];
    // чтение строки со словами(разделители – пробел,
    // знак табуляции, точка и запятая)
    fgets(str, MAX_STRING_SIZE, stdin);
    char **words;
    words = split(str, " \t,.");
    printwords(words);
    printf("asd\n");


    Func(words, "D");
    
    return 0;
}
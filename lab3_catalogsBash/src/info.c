#include <stdio.h>
#include "info.h"

void PrintHelp() 
{
    printf("\nProgram gives you information about PATH variables.\n\n");

    printf("Use -h for short descriptions and -0 for authors information.\n\n");

    printf("USAGE:\n\t");
    printf("program [PATH_VARS] [OPTIONS] [PATH_VARS]");

    printf("\n\nARGS:\n");
    printf("\t<PATH_VARS>\tPATH variables to find and show");

    printf("\n\nOPTIONS:\n");
    printf("\t-s\t\tOnly show the PATH names (without values).\n");
    printf("\t-v\t\tOnly show the PATH values (without names).\n");
    printf("\t-l\t\tShow lengths of PATH values.\n\n");
    printf("\t-b\t\tFind variables, which names start with 'string'\n");
    printf("\t-z\t\tFind variables, which names length are less than 'number'\n\n");
    printf("\t-u\t\tPrint total length of all found strings\n\n");
    printf("\t-h\t\tPrints help information\n");
    printf("\t-0\t\tPrints authors information\n");
}

void PrintAuthor() 
{
    printf("Made by Dima Vynohradov.\n");
}
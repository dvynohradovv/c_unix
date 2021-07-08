#include "printenv.h"
#include "filterfunctions.h"
#include "secondaryfunctions.h"
#include "printresult.h"
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int PrintVarsFromCommandString(char** argv, struct globalArgs_t *ga)
{
    int totalLength = 0;
    //printf("FIRSTARGIND: %d\n", ga->ga_firstargind);
    while(argv[ga->ga_firstargind] != NULL)
    {
        if(argv[ga->ga_firstargind][0] != '-')
        {
            //printf("HERE: %s\n", argv[ga->ga_firstargind]);
            //printf("FIRSTARGIND: %d\n", ga->ga_firstargind);
            totalLength += PrintResult(argv[ga->ga_firstargind], ga->ga_opts, ga->ga_optv, ga->ga_optl);
        }
        ga->ga_firstargind++;
    }
    if(ga->ga_optu)
    {
        printf("Total string length: %d\n", totalLength);
    }
    return 0;
}
#include "printargs.h"
#include "filterfunctions.h"
#include "secondaryfunctions.h"
#include "printresult.h"
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern char** environ;

/*char** GetEnvirLessThenNumberValue(struct globalArgs_t ga)
{
    bool numberbool = atoi(ga.ga_optzarg);
    char** result = malloc();
    for(char** i = environ; *i != NULL; i++)
    {
        bool counter = 0;
        for(char* j = *i; *j != '='; j++)
        {
            counter++;
        }
        if(numberbool > counter)
        {
            prboolf("%s\n", *i);
        }
    }
}*/

bool PrintSelectedVarsFromEnviron(struct globalArgs_t *ga)
{
    int totalLength = 0;

    char* end;
    char* currName;
    bool printCurrVar;
    int minLength;

    if (ga->ga_optz) 
    {
        minLength = strtod(ga->ga_optzarg, &end);
    }
    //printf("HELL%d\n", minLength);
    //printf("Bells:%s\n", ga->ga_optzarg);
    for(char** i = environ; *i != NULL; i++)
    {
        printCurrVar = true;
        currName = GetNameFromPathLine(*i);
        if (ga->ga_optb) 
        {
            if (FilterByOptionB(currName, ga->ga_optbarg)) 
            {
                printCurrVar = false;
            }
        }

        if (ga->ga_optz) 
        {
            if (FilterByOptionZ(currName, minLength)) 
            {
                printCurrVar = false;
            }
        }

        if (printCurrVar) 
        {
            totalLength += PrintResult(currName, ga->ga_opts, ga->ga_optv, ga->ga_optl);
        }

        //printf("Here: %s\n", currName);

        if(currName != NULL)
        {
            //printf("One\n");
            free(currName);
        }
        //printf("Two\n");
    }
    if(ga->ga_optu)
    {
        printf("Total string length: %d\n", totalLength);
    }
    return 0;
}
/*char** resOptZ = NULL;
    char** resOptB = NULL;
    char** mixedRes = NULL;
    if(ga->ga_optz)
    {
        resOptZ = GetEnvirLessThenNumberValue(*ga);
    }
    if(ga->ga_optb)
    {
        resOptB = GetEnvirSettedStringValue(*ga);
    }
    if(resOptB != NULL && resOptZ != NULL)
    {
        mixedRes = MixingResultsFromOptBAndOptZ(resOptZ, resOptB);
    }
    if(ga->ga_optv)
    {
        PrboolEnvirAllValue();
    }
    if(ga->ga_opts)
    {
        PrboolEnvirAllName();
    }
    if(ga->ga_optl)
    {
        PrboolEnvirAllValueLength();
    }*/
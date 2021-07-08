#include <unistd.h>
#include <stdio.h>
#include "scanoptions.h"

extern char* optarg;
extern int optind;

bool ScanOptions(int argc, char *const *argv, struct globalArgs_t* ga)
{
	const char* KEYS = "h0psvlb:z:u";
    char c;
    while ((c = getopt(argc, argv, KEYS)) != -1) 
	{
        switch (c) 
		{
            case 'h':
                ga->ga_help = 1;
                return 0;

            case '0':
                ga->ga_author = 1;
                break;

            case 's':
                ga->ga_opts = 1;
                ga->ga_optv = 0;

                ++ga->total_keys_and_args;
                break;

            case 'v':
                ga->ga_optv = 1;
                ga->ga_opts = 0;

                ++ga->total_keys_and_args;
                break;

            case 'l':
				ga->ga_optl = 1;

                ++ga->total_keys_and_args;
                break;

            case 'b':
				ga->ga_optb = 1;
				ga->ga_optbarg = optarg;
                ga->ga_optp = 0;

                ga->total_keys_and_args += 2;
                break;

            case 'z':
				ga->ga_optz = 1;
				ga->ga_optzarg = optarg;
                ga->ga_optp = 0;

                ga->total_keys_and_args += 2;
                break;

            case 'u':
				ga->ga_optu = 1;

                ++ga->total_keys_and_args;
                break;

            case 'p':
				ga->ga_optp = 1;
				ga->ga_optb = 0;
                ga->ga_optz = 0;

               ++ga->total_keys_and_args;
                break;

            case ':':
                return 1;

            case '?':
                return 1;
        }
    }
    if(!ga->ga_optl && !ga->ga_optv && !ga->ga_opts && !ga->ga_optu && !ga->ga_author)
    {
        return 1;
    }
    ga->ga_firstargind = optind;
    //printf("FIRSTARGIND%d\n", ga->ga_firstargind);
	return 0;
}
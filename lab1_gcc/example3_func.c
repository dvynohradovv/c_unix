#include <time.h>
#include <stdio.h>

const int TIME_STR_LEN = 30;

int print_with_timestamp(char *msg)
{
    char buf[TIME_STR_LEN];
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    if (strftime(buf, TIME_STR_LEN, "%c", timeinfo) == 0)
    {
        return -1;
    }
    printf("%s: \"%s\"\n", buf, msg);
    return 0;
}
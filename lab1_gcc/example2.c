#include <stdio.h>
#define A 2
#define B 4
#define calculate(a, b) a*a + b*b

void plain_dummy()
{
    printf("Just a dummy\n");
}
static inline justtest()
{
    printf("Hi !\n");
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
int main(int argc, char *argv[])
{
#ifdef TEST
    justtest();
#endif
    printf("%d\n", calculate(A, B));
    return 0;
}
/*
gcc -E -D TEST -o example2D_preProcC .\example2.c
gcc -E -o example2_preProcC .\example2.c
*/
#include <stdio.h>

int print_with_timestamp(char *msg);
int main(int argc, char **argv)
{
    print_with_timestamp("Hello, world!");
    return 0;
}
/*
Код на Сі
Компіляція програми з двух модулів: gcc -c ./example3_main.c ./example3_func.c
Компоновка у виконавчий example3_result.exe файл: gcc -o ./example3_main.o ./example3_func.o

Створення статичної бібліотеки: ar src libmylib.a .\example3_func.o
Створення динамічної бібліотеки: gcc -shared -o libmylib.so .\example3_func.o
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "globalargs.h"
#include "scanoptions.h"
#include "info.h"
#include "printargs.h"
#include "printenv.h"

//6. –p, –u, –0, –h, –s, –v, –l, –b, –z, 

int main(int argc, char** argv)
{
    struct globalArgs_t  ga;
    memset(&ga, 0, sizeof(ga)); // По умолчанию ни одна опция не задана, заполняем нулями.

    // Разбор опций командной строки; Результат разбора помещается в специальную структуру.
    // Если при разборе выявлены ошибки , то вывести справку и установить код завершения EXIT_FAILURE, з
    // закончить работу программы.
    if (ScanOptions(argc, argv, &ga))
    {
    	PrintHelp();
    	return EXIT_FAILURE;
    } 	

    //Если задана опция –h – вывести справку, завершить работу.
    if (ga.ga_help)
    {
    	PrintHelp();
    	return EXIT_SUCCESS;
    }	
    // Если задана опция -0 – вывести информацию об авторе (ФИО студента).
    if(ga.ga_author)
    {
        PrintAuthor();
        return EXIT_SUCCESS;
    }
    // Если не задана ни одна из опций управления выводом и агрегатных опций, то вывод справки и завершение работы.
    // Если встретилась последней среди опций отбора опция «-р», то выводится информация о переменных имена которых заданы аргументами командной строки, 
    // иначе вывод информации о переменных окружения соответствующих всем заданным критериям отбора.
    if (ga.ga_optp)
    {
    	if (PrintVarsFromCommandString(argv, &ga)) // Отобранные переменные из командной строки.
    	    return  EXIT_FAILURE;
    } 	
    else
    {
        PrintSelectedVarsFromEnviron(&ga); // Общие переменные окружения.
    }
    
    return EXIT_SUCCESS;

}

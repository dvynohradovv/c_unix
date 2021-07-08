#ifndef GLOBALARGS_H
#define GLOBALARGS_H

#include <stdbool.h>
// Структура для сохранения опций:
struct globalArgs_t
{
   bool ga_help; // Справка о варианте программы, опция -h.
   bool ga_author; // Информация об авторе, опция -0.

   bool ga_optp; // опция -p.

   bool ga_optv; // Информация только о значениях переменных окружения процесса (без имен), опция -v.
   bool ga_optl; // Информация только о длинах значениях переменных окружения процесса, опция -l.
   bool ga_opts; // Информация только об именах переменных окружения процесса (без значений), опция -s.

   bool ga_optb; // –b string - выводить информацию о тех переменных окружения, имена которых начинаются со  строки string.
   char* ga_optbarg; // Аргумент опции -b.

   bool ga_optz; // –z number - выводить информацию о тех переменных окружения, длина имен которых меньше числа number.
   char* ga_optzarg; // Аргумент опции -z.

   bool ga_optu; // Информация про общую длину всех строк отобранных переменных окружения в байтах -u.

   bool total_keys_and_args; // Общее количество ключей и аргументов.
   int ga_firstargind; // Индекс первого аргумента. ?
   //bool errflag; // Флаг ошибок.
}; 
/*bool getopt_b(struct globalArgs_t* ga)
{
   return ga->ga_optb;
}*/
#endif
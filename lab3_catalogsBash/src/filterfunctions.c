#include <string.h>
#include <stdbool.h>

#include "filterfunctions.h"


bool FilterByOptionB(const char* path_var_name, const char* suffix) 
{
    //Выводить информацию о тех переменных окружения,
    //имена которых начинаются со строки 'string'.

    int suf_size = strlen(suffix);

    if (strlen(path_var_name) < suf_size) 
    {
        return 1;
    }

    for (int i = 0; i < suf_size; ++i) 
    {
        if (path_var_name[i] != suffix[i]) 
        {
            return 1;
        }
    }

    return 0;
}


bool FilterByOptionZ(const char* path_var_name, int min_len) 
{
    //Выводить информацию о тех переменных окружения, 
    //длина имен которых меньше числа 'number'.
    
    if (strlen(path_var_name) < min_len) 
    {
        return 0;
    }
    return 1;
}
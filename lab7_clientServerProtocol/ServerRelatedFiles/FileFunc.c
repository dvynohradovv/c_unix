#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

int Exists(char pathAndName[])
{
    
  //  int sz = strlen(pathAndName); //fgets также добавляет Enter после ввода строки в консоли и перевода на новую строку, поэтому удаляем его
//    pathAndName[sz-1] = '\0'; // путём установки значения последнего символа ('\n') на символ конца строки '\0'.

    if(access(pathAndName, F_OK) == 0) //если файл существует
    {
        return 0;
    }
    else //иначе
    {
        return 1;
    }
}
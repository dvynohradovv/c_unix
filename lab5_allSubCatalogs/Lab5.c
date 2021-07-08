#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#define _POSIX_PATH_MAX 4096

// 6. Написать программу, которая выводит содержимое заданного
// каталога и всех его подкаталогов. Имя каталога задавать в виде аргумента
// командной строки.


int print_dirs(const char *path)
{
    //оъявление необходимых переменных и указателей
    struct dirent *direntp = NULL;
    DIR *dirp = NULL;
    size_t path_len;

    //проверка исходных данных
    if (!path)
        return -1;
    path_len = strlen(path);  

    if (!path || !path_len || (path_len > _POSIX_PATH_MAX))
        return -1;

    //открытие директории и проверка на ошибку
    dirp = opendir(path);
    if (dirp == NULL)
        return -1;

    while ((direntp = readdir(dirp)) != NULL)
    {
        //для каждого входа в директорию
        struct stat fstat;
        char full_name[_POSIX_PATH_MAX + 1];

        //проверка, не длинее ли полное имя максимально допустимого значения 
        if ((path_len + strlen(direntp->d_name) + 1) > _POSIX_PATH_MAX)
            continue;

        strcpy(full_name, path);
        if (full_name[path_len - 1] != '/')
            strcat(full_name, "/");
        strcat(full_name, direntp->d_name);

        //игнорирование спец. директорий
        if ((strcmp(direntp->d_name, ".") == 0) ||
            (strcmp(direntp->d_name, "..") == 0))
            continue;

        
        if (stat(full_name, &fstat) < 0)
            continue;
        
        //вывод
        printf("%s\n", full_name);
        print_dirs(full_name);
        
    }

    
    (void)closedir(dirp);
    return 0;
}


int main(int argc, const char* argv[])
{
    if (argc < 2)
        return -1;

    print_dirs(argv[1]);
    return 0;
}
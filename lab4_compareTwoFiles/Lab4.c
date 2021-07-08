#include<stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <unistd.h>
#include "lab4_defs.h"

// 6. Написать программу сравнения двух файлов, которая будет печатать
// первую из различающихся строк и позицию символа, в котором они
// различаются. Имена файлов задавать в виде аргументов командной строки.
// Проверить, не возникают ли ошибки при системных вызовах.

int main(int argc, char *argv[])
{
    char buffer_1[BUFSIZ];
    char buffer_2[BUFSIZ];
    int file_descr_1, file_descr_2;
    ssize_t ret1, ret2;

    if(argc != 3)
    {
        fprintf(stderr, "Expected 2 args: path to first and second file.\n");
        exit(EXIT_FAILURE);
    }

    file_descr_1 = open(argv[1], O_RDONLY);
    IsOpen(file_descr_1, argv[1]);

    file_descr_2 = open(argv[2], O_RDONLY);
    IsOpen(file_descr_2, argv[2]);



    while( (ret1 = read(file_descr_1, buffer_1, BUFSIZ)) != 0 )
    {
        if(ret1 == -1 && errno != EINTR)
        {
            fprintf(stderr, "error reading from first file: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }


    while( (ret2 = read(file_descr_2, buffer_2, BUFSIZ)) != 0)
    {

        if(ret2 == -1 && errno != EINTR)
        {
            fprintf(stderr, "error reading from second file: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }



    IsFound(buffer_1, buffer_2);
    close(file_descr_1);
    close(file_descr_2);

 
}

void IsOpen(int fd, char filepath[])
{
    if(fd < 0)
    {
        fprintf(stderr, "Error reading file %s: %s\n", filepath, strerror(errno));
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("File opened.\n");
    }
}





void IsFound(char buffer1[], char buffer2[])
{

    char ** strings;
    int NumberOfString = 1, index = 0;

    while(buffer1[index] == buffer2[index])
    {
        if(buffer2[index] == '\n')
            NumberOfString++;
        index++;
    }

    strings = split(buffer2, "\n");
    
    printf("Индекс первого отличного символа: %d\n", index);
    printf("Номер строки с этим символом: %d\n", NumberOfString);
    printf("Сама строка: %s\n", strings[NumberOfString-1]);

}


char **split(char * string, char *delimiters)
{
	char * pch;
	char** result;
	
	pch = strtok(string, delimiters);
	long unsigned size = sizeof(char *);
	result = malloc(size);

	int n = 0;
	while(pch != NULL)
	{
		result[n] = pch;
		pch = strtok(NULL, delimiters);
		n++; 
		size+=sizeof(char *);
		result = realloc(result, size);

	}
	result[n] = NULL;
	//free(result);
	return result;
} 

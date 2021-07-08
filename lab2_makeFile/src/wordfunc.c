#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/defs.h"

// TODO: 6 Вариант: Подсчитать суммарную длину слов 
// TODO: у которых имя начинается с
// TODO: заданной подстроки

int problem_func(char **array_words, char *substr)
{
  if (substr == NULL) return 0;
  int sum = 0;
  char *needed_substr = substr;

  // Итерация по словам в массиве
  while (array_words != NULL)
  {
    char *word = *array_words;
    int current_counter = 0;
    bool is_substr = true;
    // Итерация по буквам в слове
    while(word != NULL)
    {
      if(needed_substr == NULL)
        break;
      if(*word != *needed_substr)
      {
        is_substr = false;
        break;
      } 
      current_counter++;
      word++;
      needed_substr++;
    }
    if (is_substr) 
      sum +=current_counter;
    needed_substr = substr;
    array_words++;
  }
  return sum;
}

void Func(char **array_words, char *substr)
{
  printf("Начали");
  // char *substr;
  // printf("Enter a letter: ");
  // scanf("%s", substr);
  int sum = problem_func(array_words, substr);
  printf("%d\n", sum);
}


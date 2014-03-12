/*
** alloc.c for colle in /home/fontai_t/colle2
** 
** Made by thomas fontaine
** Login   <fontai_t@epitech.net>
** 
** Started on  Thu Apr 26 22:32:31 2012 thomas fontaine
** Last update Thu Apr 26 22:50:22 2012 thomas fontaine
*/

#include <unistd.h>
#include <stdlib.h>
#include "put.h"

void	alloc_str(char **str, int size)
{
  *str = malloc(sizeof(*str) * size);
  if (*str == NULL)
    {
      my_puterr("Alloc failed in alloc_str");
      exit(1);
    }
}

void	alloc_tab(char ***_tab, int size)
{
  *_tab = malloc(sizeof(*_tab) * size);
  if (*_tab == NULL)
    {
      my_puterr("Alloc failed in alloc_str");
      exit(1);
    }
}

/*
** declar.c for declar in /home/platel_k/projet/rush/Marvin
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sat Nov 26 19:16:09 2011 kevin platel
** Last update Sun Nov 27 11:27:16 2011 kevin platel
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "marvin.h"

void	declar(char *argv)
{
  char	*str2;
  char	*str;
  char	*return_value;
  char	*name;

  my_printf("Declaration d'");
  if ((str = strchr(my_strdup(argv), '(')) == NULL)
    {
      my_printf("une variable ");
      str = argv;
    }
  return_value = strtok(my_strdup(argv), " ");
  name = strtok(NULL, " *()");
  str2 = my_strdup(str);
  if (str2[0] == '(' && str2[1] != '*')
    {
      my_printf("une fonction nommé %s qui retourne ", name);
      type(return_value);
      my_printf("qui prend en parametre ");
    }
}

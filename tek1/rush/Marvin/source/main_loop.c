/*
** main_loop.c for main_loop in /home/platel_k/projet/rush/Marvin/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sun Nov 27 08:41:18 2011 kevin platel
** Last update Sun Nov 27 12:06:16 2011 kevin platel
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "marvin.h"

void	put_point_function(char *str, char *str2, char *str3)
{
  if (str2[0] == '*')
    {
      my_printf("un pointeur sur fonction nommé %s retournant ", &str2[1]);
      type(str);
      my_printf("prenant en parametre ");
    }
  else
    {
      if (str3 == NULL)
	type(str2);
      else if (str3 != NULL && str3[0] != '*')
	type(str2);
    }
}

void	main_loop(char *str, char *str2, char *str3, char *delimiter)
{
  int	i;

  while (str2)
    {
      i = -1;
      put_point_function(str, str2, str3);
      while (str2[++i] != '\0' && str2[i] != ')');
      if ((str2[0] != '*') && str3 != NULL && str3[0] != '*')
	{
	  if (str2[i] == ')')
	    {
	      my_printf("cette fonction est elle même un paramètre");
	      my_printf("de la fonction qui prend également en parametre ");
	    }
	  else
	    my_printf("et ");
	}
      str = str2;
      str2 = str3;
      str3 = strtok(NULL, delimiter);
    }
}

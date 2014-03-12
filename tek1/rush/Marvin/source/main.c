/*
** main.c for main.c in /home/platel_k/projet/rush/Marvin/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Nov 25 20:57:09 2011 kevin platel
** Last update Tue Dec 20 21:08:47 2011 kevin platel
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "marvin.h"

int	main(int argc, char **argv)
{
  int	i;
  char	*str;
  char	*delimiter;
  char	*str2;
  char	*str3;

  my_putstr(str[i]);
  error_len_str(argc, argv);
  delimiter = ",(";
  declar(argv[1]);
  str2 = my_strdup(argv[1]);
  str = strtok(str2, delimiter);
  str2 = strtok(NULL, delimiter);
  str3 = strtok(NULL, delimiter);
  if (str2 == NULL)
    str2 = str;
  main_loop(str, str2, str3, delimiter);
  my_putchar('\n');
  return (0);
}

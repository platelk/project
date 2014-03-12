/*
** main.c for main.c in /home/platel_k//projet/piscine/Jour_11/do-op
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 24 11:21:59 2011 kevin platel
** Last update Mon Oct 24 14:50:27 2011 kevin platel
*/

#include <stdlib.h>
#include "function.h"
#include "my.h"

int	main(int argc, char **argv)
{
  int	(*(*tab))(int, int);

  if (argc > 4 || (my_getnbr(argv[3]) == 0 && (argv[2][0] == '/' || argv[2][0] == '%')))
    {
      if (argv[2][0] == '/')
	my_putstr("Stop : division by Zero");
      if (argv[2][0] == '%')
	my_putstr("Stop : modulo by Zero");
      my_putstr("\n");
      return(0);
    }
  if (argv[2][0] != '*' && argv[2][0] != '/' && argv[2][0] != '+')
    if (argv[2][0] != '%' && argv[2][0] != '-')
    {
      my_putstr("0\n");
      return (0);
    }
  tab = malloc(6 * sizeof(tab));
  tab[0] = &mul;
  tab[1] = &add;
  tab[2] = &mod;
  tab[3] = &sub;
  tab[5] = &divis;
  my_put_nbr(tab[(argv[2][0] % 7)](my_getnbr(argv[1]), my_getnbr(argv[3])));
  my_putstr("\n");
}

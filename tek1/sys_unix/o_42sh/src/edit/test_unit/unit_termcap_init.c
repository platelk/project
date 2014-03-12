/*
** unit_termcap_init.c for 42sh in /home/leprov_a//depot/42sh/src/termcap/test_unit
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 23 11:06:33 2012 alexis leprovost
** Last update Mon Apr 23 11:09:16 2012 alexis leprovost
*/

#include	"edit.h"
#include	"env.h"

int	main(int ac, char **av)
{
  t_env	*env;

  env = creat_env();
  if (termcap_init(env))
    {
      printf("Initialization FAIL.\n");
      return (1);
    }
  printf("Initialization OK.\n");
  return (0);
}

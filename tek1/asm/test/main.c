/*
** main.c for main in /home/vink/projet/asm/test
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sat Apr  7 13:03:23 2012 kevin platel
** Last update Sat Apr  7 16:45:32 2012 kevin platel
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	check_authentication(char *password)
{
  char	password_buffer[16];
  int	auth_flag = 0;

  strcpy(password_buffer, password);

  if (strcmp(password_buffer, "brilling") == 0)
    auth_flag = 1;
  if (strcmp(password_buffer, "outgrabe") == 0)
    auth_flag = 1;

  return auth_flag;
}


int	main(int ac, char **av)
{
  if (ac < 2)
    {
      printf("Usage : %s <password>\n", av[0]);
      exit(0);
    }
  if (check_authentication(av[1])) {
    printf("\n_=_=_=_=_=_=_=_=_=_\n");
    printf("\tAccess Granted.");
    printf("\n_=_=_=_=_=_=_=_=_=_\n");
  }
  else
    printf("\tAccess Denied.\n");
  return (0);
}

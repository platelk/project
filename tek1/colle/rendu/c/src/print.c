/*
** print.c for colle in /home/vink/projet/colle/src
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Apr 26 22:57:02 2012 kevin platel
** Last update Thu Apr 26 22:59:01 2012 kevin platel
*/

#include	<unistd.h>

void	print_head_and_tail(char *str)
{
  write(1, "+", 1);
  while (*str)
    {
      write(1, "-", 1);
      str++;
    }
  write(1, "+\n", 2);
}

void	print_sand(char **tab)
{
  int	i;
  int	j;

  i = 0;
  print_head_and_tail(tab[0]);
  while (tab && tab[i])
    {
      j = 0;
      write(1, "|", 1);
      while (tab[i][j])
	{
	  write(1, &tab[i][j], 1);
	  j++;
	}
      write(1, "|\n", 2);
      i++;
    }
  print_head_and_tail(tab[0]);
}

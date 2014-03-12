/*
** my_rand_code.c for my_rand_code in /home/letexi_a//Documents/Tek1/Projets/Colle1
** 
** Made by alexis letexier
** Login   <letexi_a@epitech.net>
** 
** Started on  Thu Apr 19 14:11:27 2012 alexis letexier
** Last update Thu Apr 19 15:28:40 2012 kevin platel
*/

#include	<stdlib.h>
#include	<time.h>

int	my_rand(int n)
{
  int	ret;

  ret = rand() % n;
  return (ret);
}

char	*my_rand_code(int nb, char *piont)
{
  int   a;
  int	r_nb;
  char *ret;

  a = 0;
  ret = malloc(sizeof(*ret) * nb + 1);
  if (ret == NULL)
    return (NULL);
  srand(time(NULL));
  while (nb > 0)
    {
      r_nb = my_rand(8);
      ret[a] = piont[r_nb];
      nb--;
      a++;
    }
  ret[a] = '\0';
  return (ret);
}

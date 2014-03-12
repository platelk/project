/*
** my_getnbr.c for my_getnbr in /home/platel_k//projet/piscine/Jo\
ur_4
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Thu Oct  6 12:08:46 2011 kevin platel
** Last update Fri Oct  7 18:05:51 2011 kevin platel
*/

int     my_nbr(char *str,int c)
{
  int	size;
  int	nbr;

  while (*str >= '0' && *str <= '9')
    {
      str = str + 1;
    }
  str = str - 1;
  while (*str >= '0' && *str <= '9')
    {
      nbr = nbr + ((*str - 48) * c);
      str = str - 1;
      c = c * 10;
      size = size + 1;
      if ((size >= 9) && *str >= '2' && nbr > 147483648)
        return (0);
    }
  return (nbr);
}

int     my_getnbr(char *str)
{
  int   nbr;
  int   c;

  nbr = 0;
  c = 1;
  while (*str < '0' || *str > '9')
    {
      if (*str == '-')
        c = c * (-1);
      str = str + 1;
    }
  nbr = my_nbr(str, c);
  return (nbr);
}

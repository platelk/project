/*
** my_getnbr.c for my in /home/leprov_a//afs/current/getnbr
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 16 11:03:04 2012 alexis leprovost
** Last update Mon Apr 30 13:12:49 2012 alexis leprovost
*/

int	my_getnbr(char *str)
{
  int	nb;
  int	sign;
  int	i;

  nb = 0;
  sign = 0;
  i = 0;
  if (!str)
    return (0);
  while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
    if (str[i++] == '-')
      ++sign;
  while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
    nb = (nb * 10) + (str[i++] - 48);
  return (((sign % 2) == 1) ? ((nb) * (-1)) : (nb));
}

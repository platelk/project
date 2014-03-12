/*
** my_power_rec.c for my_power_rec in /home/platel_k//projet/piscine/Jour_05
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Oct  7 11:27:42 2011 kevin platel
** Last update Fri Oct  7 11:42:09 2011 kevin platel
*/

int	my_power_rec(int nb, int power)
{
  if (power < 0)
    return (0);
  if (power == 0)
    return (1);
  return (nb * my_power_rec(nb, power - 1));
}

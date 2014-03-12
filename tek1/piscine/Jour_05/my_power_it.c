/*
** my_power_it.c for my_power_it in /home/platel_k//projet/piscine/Jour_05
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Oct  7 11:20:59 2011 kevin platel
** Last update Fri Oct  7 11:32:13 2011 kevin platel
*/

int	my_power_it(int nb, int power)
{
  int nbr_return;

  nbr_return = 1;
  if (power == 0)
    return (1);
  if (power < 0)
    return (0);
  while (power != 0)
    {
      nbr_return = nbr_return * nb;
      power = power - 1;
    }
  return (nbr_return);
}

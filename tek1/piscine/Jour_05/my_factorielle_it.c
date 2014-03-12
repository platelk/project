/*
** my_factorielle_it.c for my_factorielle_it in /home/platel_k//projet/piscine/Jour_05
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Oct  7 10:13:17 2011 kevin platel
** Last update Fri Oct  7 10:55:21 2011 kevin platel
*/

int	my_factorielle_it(int nb)
{
  int nbr_return;

  nbr_return = 1;
  if (nb < 0 || nb > 12)
    return (0);
  if (nb == 0)
    return (1);
  while (nb != 0)
    {
      nbr_return = nbr_return*nb;
      nb = nb - 1;
    }
}

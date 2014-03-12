/*
** my_factorielle_rec.c for my_factorille_rec in /home/platel_k//projet/piscine/Jour_05
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Oct  7 10:42:56 2011 kevin platel
** Last update Fri Oct  7 11:17:26 2011 kevin platel
*/

int	my_factorielle_rec(int nb)
{
  if (nb < 0 || nb > 12)
    return (0);
  if (nb == 0)
    return (1);
  return (nb * my_factorielle_rec(nb - 1));
}

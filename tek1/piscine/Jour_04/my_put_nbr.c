/*
** mu_put_nbr.c for my_put_nbr in /home/platel_k//projet/piscine/Jour_03
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Wed Oct  5 16:52:07 2011 kevin platel
** Last update Fri Oct  7 10:38:30 2011 kevin platel
*/

void	my_put_nbr(int nb)
{
  long int   modulo;
  long int   nbr1;

  nbr1 = nb;
  modulo = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nbr1 = nb * (-1);
      if (nb == -2147483648)
	nbr1 = 2147483648;
    }
  while ((nb > 0 || nb < 0) || nb != 0)
    {
      nb = nb / 10;
      modulo = modulo * 10;
    }
  if (nbr1 == 0)
    modulo = 10;
  while (modulo >= 10)
    {
      my_putchar('0' + ((nbr1 % modulo) / (modulo / 10)));
      modulo = modulo / 10;
    }
}

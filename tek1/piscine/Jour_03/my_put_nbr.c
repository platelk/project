/*
** mu_put_nbr.c for my_put_nbr in /home/platel_k//projet/piscine/Jour_03
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Oct  5 16:52:07 2011 kevin platel
Last update Wed Jun 27 13:04:09 2012 kevin platel
*/

void	my_put_nbr(int nb)
{
  long int   modulo;
  long int   c;
  long int   nbr1;

  modulo = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nbr1 = nb * (-1);
      if (nb == -2147483648)
	nbr1 = 2147483648;
    }
  while (nb >= 1 || nb <= -1)
    {
      nb = nb / 10;
      modulo = modulo * 10;
    }

  while (modulo >= 10)
    {
      c = nbr1 % modulo;
      c = c / (modulo / 10);
      c = '0' + c;
      my_putchar(c);
      modulo = modulo / 10;
    }
}

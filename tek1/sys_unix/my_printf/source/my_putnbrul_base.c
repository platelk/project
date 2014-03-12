/*
** my_putnbr_base.c for my_putnbr_base in /home/platel_k//projet/piscine/Jour_6
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 10 16:43:15 2011 kevin platel
** Last update Tue Nov 15 16:51:31 2011 kevin platel
*/

#define ABS(x)	(x < 0)? x = (x * (-1)): x

int	my_putnbrul_base(unsigned long int nbr, char *base)
{
  int	i;

  i = 0;
  while (base[i])
      i = i + 1;
  if (nbr == 0)
    return (0);
  if (nbr < 0)
    my_putchar('-');
  my_putnbrul_base(ABS(nbr) / i, base);
  my_putchar(base[ABS(nbr) % i]);
}

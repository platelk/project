/*
** my_putnbr_base.c for my_putnbr_base in /home/platel_k//projet/piscine/Jour_6
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 10 16:43:15 2011 kevin platel
** Last update Mon Oct 10 19:27:30 2011 kevin platel
*/

int	my_putnbr_base(int nbr, char *base)
{
  int	i;

  i = 0;
  while (base[i])
      i = i + 1;
  if (nbr == 0)
    return (0);
  if (nbr < 0)
    {
      nbr = nbr * (- 1);
      my_putchar('-');
    }
  my_putnbr_base(nbr / i, base);
  my_putchar(base[nbr % i]);
}

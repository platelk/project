/*
** main.c for main in /home/platel_k//projet/piscine/Jour_04
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Oct  6 09:52:09 2011 kevin platel
** Last update Fri Oct  7 18:07:11 2011 kevin platel
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	main()
{
  char	tab[10];
  int	size;

  tab[0] = '-';
  tab[1] = '2';
  tab[2] = '1';
  tab[3] = '4';
  tab[4] = '7';
  tab[5] = '4';
  tab[6] = '8';
  tab[7] = '3';
  tab[8] = '6';
  tab[9] = '4';
  tab[10] = '8';
  my_put_nbr(my_getnbr(&tab[0]));
}

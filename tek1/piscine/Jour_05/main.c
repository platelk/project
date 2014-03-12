/*
** main.c for main in /home/platel_k//projet/piscine/Jour_05
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Oct  7 10:25:33 2011 kevin platel
** Last update Fri Oct  7 19:22:13 2011 kevin platel
*/
int	my_putchar(int c)
{
  write(1, &c, 1);
}

int	main()
{
  my_put_nbr(my_factorielle_it(15));
  my_putchar('\n');
  my_put_nbr(my_factorielle_rec(5));
  my_putchar('\n');
  my_put_nbr(my_power_it(3, -3));
  my_putchar('\n');
  my_put_nbr(my_power_rec(6, 3));
  my_putchar('\n');
  my_8r1();
}

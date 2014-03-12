/*
** my_rev_params.c for my_rev_params in /home/platel_k//projet/piscine/Jour_07/ex_03
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Oct 11 14:13:59 2011 kevin platel
** Last update Tue Oct 11 14:25:22 2011 kevin platel
*/

int	main(int argc, char **argv)
{
  int	i;

  i = 0;
  while ((argc - i) != 0)
    {
      my_putstr(argv[argc - i - 1]);
      my_putchar('\n');
      i = i + 1;
    }
  return (0);
}

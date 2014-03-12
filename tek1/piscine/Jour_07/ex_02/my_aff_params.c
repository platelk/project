/*
** my_aff_params.c for my_aff_params in /home/platel_k//projet/piscine/Jour_07/ex_02
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Oct 11 12:02:46 2011 kevin platel
** Last update Tue Oct 11 12:13:02 2011 kevin platel
*/

int	main(int argv, char **argc)
{
  int	i;

  i = 0;
  while (argv > i)
    {
      my_putstr(argc[i]);
      i = i + 1;
      my_putchar('\n');
    }
  return (0);
}

/*
** sum_params.c for sum_params in /home/platel_k//projet/piscine/Jour_08/ex_03
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Oct 12 13:09:48 2011 kevin platel
** Last update Wed Oct 12 14:58:01 2011 kevin platel
*/

char	*sum_params(int argc, char **argv)
{
  int	i;
  int	length;
  char	*new;

  length = 0;
  i = 0;
  while (argc != i)
    {
      length = length + my_strlen(argv[i]);
      i = i + 1;
    }
  i = 0;
  new = malloc(length + argc);
  while (argc  - 1 >= i )
    {
      my_strcat(new, argv[i]);
      if (argc - 1 == i)
	return (new);
      my_strcat(new, "\n");
      i = i + 1;
    }
  return (new);
}

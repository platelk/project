/*
** find_intab.c for find_intab in /home/platel_k/projet/my_printf
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Nov 11 12:35:18 2011 kevin platel
** Last update Sat Dec 31 01:14:39 2011 kevin platel
*/

int	find_intab(char c)
{
  char	*tab;
  int	i;

  i = 0;
  tab = "dscxXoubSp%";
  if (c == 'i')
    return (0);
  while (tab[i])
    {
      if (c == tab[i])
	return (i);
      i++;
    }
  return (-1);
}

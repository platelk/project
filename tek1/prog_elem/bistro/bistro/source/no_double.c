/*
** no_double.c for no_double in /home/platel_k/projet/bistro/bistro/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Nov 10 08:51:28 2011 kevin platel
** Last update Thu Nov 10 09:29:25 2011 matthieu przybylski
*/

int	no_double(char *str)
{
  int	count;
  int	i;
  int	j;

  j = 0;
  while (str[j])
    {
      count = 0;
      i = 0;
      while (str[i])
	{
	  if (str[i] == str[j])
	    count = count + 1;
	  if (count == 2)
	    return (1);
	  i = i + 1;
	}
      j = j + 1;
    }
  return (0);
}

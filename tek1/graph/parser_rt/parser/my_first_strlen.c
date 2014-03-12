/*
** my_first_strlen.c for my_first_strlen in /home/vink/projet/graph/parser_rt/parser
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue May  1 10:48:16 2012 kevin platel
** Last update Tue May  1 10:51:56 2012 kevin platel
*/

int	my_first_strlen(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str && str[i])
    {
      if (str[i] && str[i] != ' ' && str[i] != '\t')
	{
	  while (str[i] && str[i] != ' ' && str[i] != '\t')
	    {
	      j++;
	      i++;
	    }
	  return (j);
	}
      i++;
    }
  return (0);
}

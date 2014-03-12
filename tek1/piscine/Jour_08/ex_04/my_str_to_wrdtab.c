/*
** my_str_to_wrdtab.c for my_str_to_wordtab in /home/platel_k//projet/piscine/Jour_08/ex_04
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Oct 12 14:59:24 2011 kevin platel
** Last update Thu Oct 13 10:32:44 2011 kevin platel
*/
int	alnum(char c)
{
  if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
    if(c < '0' || c > '9')
      return (1);
  return (0);
}

int	inval_c(char *str)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (str[i])
    {
      if (alnum(str[i]))
	j = j + 1;
      i = i + 1;
    }
  return (j);
}

int	n(int len, char c)
{
  int	end;

  end = 0;
  if (c == '\0')
    end  = 1;
  return (len + end);
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  char **wordtab;
  int	j;
  int	len;

  i = 0;
  len  = 0;
  wordtab = malloc(inval_c(str) + 2);
  j = 1;
  wordtab[0] = malloc(1);
  while (str[i])
    {
      if (alnum(str[i]) || str[i + 1] == '\0')
	{
	  wordtab[j] = malloc(len);
	  my_strncpy(wordtab[j], &str[i - len], n(len, str[i + 1]));
	  len = -1;
	  j = j + 1;
	}
      len = len + 1;
      i = i + 1;
    }
  wordtab[j] = malloc(1);
  wordtab[j] = 0;
  return (wordtab);
}

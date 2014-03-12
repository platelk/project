/*
** my_evil_str.c for my_evil_str in /home/platel_k//projet/piscine/Jour_04
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Oct  6 10:53:48 2011 kevin platel
** Last update Mon Oct 10 12:44:17 2011 kevin platel
*/

/*
** reverse two content of pointer
*/
int     my_swap(char *a, char *b)
{
  int   c;

  c = *a;
  *a = *b;
  *b =  c;
}

/*
**calculate a length of a string
*/
int	my_strleng(char *str)
{
  int   length;

  length = 0;
  while (str[length])
    {
      length = length + 1;
    }
  return (length);
}

/*
** reverse a string
*/
char	*my_revstr(char *str)
{
  int   length;
  char	c;

  c = 0;
  length = my_strleng(str);
  while (length >= c)
    {
	length = length - 1;
	my_swap(&str[c], &str[length]);
	c = c + 1;
    }
  return (str);
}

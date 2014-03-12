/*
** my_revstr.c for my_revstr in /home/guiho_r//workhome/piscine/Jour_06
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Oct 10 09:47:52 2011 ronan guiho
** Last update Sun Dec 11 16:26:29 2011 ronan guiho
*/
int	my_strleng1(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
int	my_swap1(char *a, char *b)
{
  char	c;
  char	d;

  c = *a;
  d = *b;
  *b = c;
  *a = d;
  return (0);
}
char	*my_revstr(char *str)
{
  int	leng;
  int	i;

  leng = my_strleng1(str);
  i = 0;
  while ((leng / 2) > i)
    {
      my_swap1(str + i, str + ((leng - 1) - i));
      i = i + 1;
    }
  return (str);
}

/*
** my_strcmp.c for my_strcmp in /home/guiho_r//workhome/piscine/Jour_06
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Oct 10 14:57:17 2011 ronan guiho
** Last update Sun Dec  4 19:12:40 2011 ronan guiho
*/
int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0')
    i = i + 1;
  if (s1[i] != s2[i])
    return (s1[i] - s2[i]);
  else
    return (0);
}

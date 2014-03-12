/*
** my_sort_wordtab.c for my_sort_wordtab in /home/platel_k//projet/piscine/Jour_11/my_sort_wordtab
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Oct 24 17:03:59 2011 kevin platel
** Last update Tue Mar  5 13:38:30 2013 vink
*/

int	my_sort_wordtab(char **tab)
{
  int   i;
  char *p;

  i = 1;
  while (tab[i] != '\0')
    {
      if (tab[i] == '\0')
	  i = 1;
      if (my_strcmp(tab[i], tab[i - 1]) < 0)
	{
	  p = tab[i - 1];
	  tab[i - 1] = tab[i];
	  tab[i] = p;
	  i = 0;
	}
      i = i + 1;
    }
  return (0);
}

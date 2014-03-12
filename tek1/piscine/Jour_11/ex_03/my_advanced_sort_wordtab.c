/*
** my_advanced_sort_wordtab.c for my_advanced_sort_wordtab in /home/platel_k//projet/piscine/Jour_11
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 24 17:02:09 2011 kevin platel
** Last update Mon Oct 24 17:03:22 2011 kevin platel
*/

int	my_advanced_sort_wordtab(char **tab, int(*cmp)(char *, char*))
{
  int   i;
  char *p;

  i = 1;
  while (tab[i] != '\0')
    {
      if (tab[i] == '\0')
	  i = 1;
      if (cmp(tab[i], tab[i - 1]) < 0)
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

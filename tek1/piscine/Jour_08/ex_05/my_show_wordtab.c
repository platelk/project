/*
** my_show_wordtab.c for my_show_wordtab in /home/platel_k//projet/piscine/Jour_08/ex_05
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Oct 12 20:10:13 2011 kevin platel
** Last update Fri Oct 14 10:21:12 2011 kevin platel
*/

int	my_show_wordtab(char **wordtab)
{
  int	i;

  i = 0;
  wordtab = my_str_to_wordtab(str);
  while (wordtab[i] != 0)
    {
      my_putstr(wordtab[i]);
      my_putchar('\n');
      i = i + 1;
    }
}

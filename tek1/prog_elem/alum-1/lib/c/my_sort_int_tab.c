/*
** my_sort_int_tab.c for my_sort_int_tab in /home/platel_k//projet/piscine/Jour_04
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Oct  6 13:52:58 2011 kevin platel
** Last update Wed Nov 23 11:35:05 2011 kevin platel
*/

int     my_swap(int *a, int *b)
{
  int   c;

  c = *a;
  *a = *b;
  *b =  c;
  return (0);
}

void	my_sort_int_tab(int *tab, int size)
{
  int	chang;
  int	compt;

  chang = 1;
  while (chang != 0)
    {
      compt = 0;
      chang = 0;
      while (compt != (size))
	{
	  if (*(tab + compt) < *((tab + compt) + 1))
	    {
	      my_swap((tab + compt), ((tab + compt) + 1));
	      chang = chang + 1;
	    }
	  compt = compt + 1;
	}
    }
}

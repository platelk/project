/*
** my_sort_int_tab.c for my_sort_int_tab in /home/platel_k//projet/piscine/Jour_04
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Oct  6 13:52:58 2011 kevin platel
** Last update Thu Oct  6 14:40:53 2011 kevin platel
*/

int     my_swap(int *a, int *b)
{
  int   c;

  c = *a;
  *a = *b;
  *b =  c;
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
          my_put_nbr(*(tab + compt));
          my_put_nbr(*(tab + compt + 1));
	  my_putchar('\n');
	}
    }
}

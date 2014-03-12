/*
** my_swap.c for my_swap in /home/platel_k//projet/piscine/Jour_04
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Oct  6 09:47:04 2011 kevin platel
** Last update Thu Oct  6 10:10:49 2011 kevin platel
*/

int	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b =  c;
}

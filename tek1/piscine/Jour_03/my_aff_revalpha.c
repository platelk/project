/*
** my_aff_revalpha.c for my_aff_revalpha in /home/platel_k//projet/piscine/Jour_03
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Oct  5 09:37:03 2011 kevin platel
** Last update Wed Oct  5 10:04:58 2011 kevin platel
*/

int	my_aff_revalpha()
{
  char	c;
  
  c = 'z';
  while ( c != ('a' - 1) )
    {
      my_putchar(c);
      c = c - 1;
    }
}

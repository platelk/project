/*
** my_aff_alpha.c for my_aff_alpha in /home/platel_k//projet/piscine/Jour_03
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Oct  5 09:34:14 2011 kevin platel
** Last update Wed Jan  4 11:49:00 2012 kevin platel
*/

int	my_aff_alpha()
{
  char	c;

  c = 'a';
  while ( c != '{' )
    {
      my_putchar(c);
      c = c + 1;
    }
}

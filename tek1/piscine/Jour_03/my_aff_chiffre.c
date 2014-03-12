/*
** my_aff_chiffre.c for my_aff_chiffre in /home/platel_k//projet/piscine/Jour_03
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Oct  5 09:45:46 2011 kevin platel
** Last update Wed Oct  5 10:36:42 2011 kevin platel
*/

int	my_aff_chiffre()
{
  char	c;

  c = '0';
  while ( c != ('9' + 1))
    {
      my_putchar(c);
      c = c + 1;
    }
}

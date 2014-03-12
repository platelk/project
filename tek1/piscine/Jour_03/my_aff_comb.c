/*
** my_aff_comb.c for my_aff_comb in /home/platel_k//projet/piscine/Jour_03
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Oct  5 10:23:04 2011 kevin platel
** Last update Wed Oct  5 13:18:32 2011 kevin platel
*/

int	my_aff_comb()
{
  char	nbr1;
  char	nbr2;
  char	nbr3;
  
  nbr1 = '0';
  nbr2 = '1';
  nbr3 = '2';
  while (nbr1 <= '7')
    {
      my_putchar(nbr1);
      my_putchar(nbr2);
      my_putchar(nbr3);
      my_putchar(',');
      my_putchar(' ');    
	if (nbr3 >= '9')
	  nbr2 = nbr2 + 1;
	if (nbr2 >= '8')
	    nbr1 = nbr1 + 1;
	if (nbr2 >= '8')
	    nbr2 = nbr1 + 1;
	nbr3 = nbr3 + 1;
	if (nbr3 > '9')
	  nbr3 = nbr2 + 1;
    }
  my_putchar(8);
  my_putchar(8);
}

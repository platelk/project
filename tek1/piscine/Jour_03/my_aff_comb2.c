/*
** my_aff_comb2.c for my_aff_comb2 in /home/platel_k//projet/piscine/Jour_03
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Oct  5 13:27:47 2011 kevin platel
** Last update Wed Oct  5 16:35:14 2011 kevin platel
*/

char	aff_string(char nbr1, char nbr2)
{
  char	nb1;
  
  nb1 = '0' + nbr1/10;
  my_putchar(nb1);
  nb1 = '0' + nbr1%10;
  my_putchar(nb1);
  my_putchar(' ');
  nb1 = '0' + nbr2/10;
  my_putchar(nb1);
  nb1 = '0' + nbr2%10;
  my_putchar(nb1);
  my_putchar(',');

  if (nbr1 == 98 & nbr2 == 99)
    my_putchar (8);
}

int	my_aff_comb2()
{ 
  char	nbr1;
  char	nbr2;

  nbr1 = 1;
  nbr2 = 0;
  while ( nbr1 <= 98 & nbr2 <= 99)
    {
      aff_string(nbr1, nbr2);
      nbr1 = nbr1 + 1;
      if (nbr1 == 99)
	{
	  nbr2 = nbr2 + 1;
	  nbr1 = 0;
	}
    }
}


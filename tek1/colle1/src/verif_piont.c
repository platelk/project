/*
** verif_piont.c for verif_piont in /home/letexi_a//Documents/Tek1/Projets/Colle1
** 
** Made by alexis letexier
** Login   <letexi_a@epitech.net>
** 
** Started on  Thu Apr 19 14:58:56 2012 alexis letexier
** Last update Thu Apr 19 15:56:50 2012 kevin platel
*/

int	verif_double(char *piont, int n)
{
  char	c;

  c = piont[n];
  n++;
  while (piont[n])
    {
      if (piont[n] == c)
	return (-1);
      n++;
    }
  return (0);
}

int	verif_piont(char *piont)
{
  int	n;

  n = 0;
  if (my_strlen(piont) > 8)
    {
      my_putstr("ERREUR: liste de pions trop longue\n");
      return (-1);
    }
  else if (my_strlen(piont) < 8)
    {
      my_putstr("ERREUR: liste de pions trop courte\n");
      return (-1);
    }
  while (piont[n])
    {
      if (verif_double(piont, n) == -1)
	{
	  my_putstr("ERREUR: le caractere '");
	  my_putchar(piont[n]);
	  my_putstr("' est présent plusieurs fois\n");
	  return (-1);
	}
      n++;
    }
  return (0);
}

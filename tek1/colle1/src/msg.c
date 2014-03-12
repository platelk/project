/*
** msg.c for msg in /home/vink/projet/colle
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Apr 19 15:37:01 2012 kevin platel
** Last update Thu Apr 19 16:46:20 2012 kevin platel
*/

void	win_msg(int round, int win, char *code)
{
  if (win > 0)
    {
      my_putstr("Bravo vous avez gagnie en ");
      my_putnbr(round);
      my_putstr(" Tours \n");
    }
  else
    {
      my_putstr("Looser ! tu ne peux meme pas gagnier en ");
      my_putnbr(round);
      my_putstr(" Tours !\n");
      my_putstr("Le code etait : ");
      my_putstr(code);
      my_putstr("\n");
    }
}

void	print_len_err(int slot)
{
  my_putstr("Erreur : le nombre de slot donne n'est pas correcte\n");
  my_putstr("Le nombre de slot doit etre de longeur ");
  my_putnbr(slot);
  my_putchar('\n');
}

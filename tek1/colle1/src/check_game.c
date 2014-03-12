/*
** check_game.c for game in /home/vink/projet/colle
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Apr 19 15:40:51 2012 kevin platel
** Last update Thu Apr 19 17:06:37 2012 kevin platel
*/

#include	<stdlib.h>
#include	"master.h"

int	check_game(char *code, char *pion, int slot, int tentative)
{
  if (verif_piont(pion) == -1)
    return (1);
  else if (my_strlen(code) != slot)
    {
      my_putstr(
		"Erreur : la longueur du code et le slot doivent etre les memes\n");
      return (1);
    }
  else if (tentative <= 0)
    {
      my_putstr("Erreur :  le nombre de tentative doit etre superieur a 0\n");
      return (1);
    }
  else if (is_inpion(pion, code) == EXIT_FAILURE)
    {
      my_putstr(
		"Erreur : le code doit avoir des characteres present dans pion\n");
      return (1);
    }
  return (0);
}

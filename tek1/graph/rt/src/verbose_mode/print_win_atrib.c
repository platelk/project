/*
** print_win_atrib.c for print_win_atrib in /home/jordan/Projets/Epitech/rt/verbose_mode
** 
** Made by jordan vanwalleghem
** Login   <vanwal_j@epitech.net>
** 
** Started on  Sat Jun  2 03:40:05 2012 jordan vanwalleghem
** Last update Sun Jun  3 06:38:24 2012 jordan vanwalleghem
*/

#include "my.h"
#include "window.h"

void	print_win_atrib(t_window *window)
{
  my_putstr("\n\t!MODE VERBOSE!\n\n");
  my_putstr("\t[Info fenetre]\n");
  my_putstr("La fenetre fait ");
  my_putnbr(window->x_win);
  my_putstr(" pixels de largeur par ");
  my_putnbr(window->y_win);
  my_putstr(" pixels de hauteur.\n\n");
  if (window->name_win != NULL)
    {
      my_putstr("Elle se nomme");
      my_putstr(window->name_win);
      my_putstr(".\n");
    }
  my_putstr("\t[Info scenes]\n");
  my_putstr("Il y'a ");
}

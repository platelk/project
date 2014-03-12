/*
** main_test.c for main in /home/phalip_z//exos/projets/42sh
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Tue Apr 10 18:02:13 2012 zoe phalippou
** Last update Wed Apr 18 21:10:14 2012 zoe phalippou
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	<string.h>

#include	"t_history.h"
#include	"history_putlist.h"

int	main()
{
  t_history	*list;

  list = NULL;
  if ((history_putlist("TOTO", &list) || history_putlist("titi", &list) ||
       history_putlist("prout", &list) || history_putlist("plopzozonull", &list)))
    {
      printf("ajout de maillon fail\n");
      return (1);
    }
  if (strcmp("plopzozonull", list->command) || strcmp("prout", list->prev->command) ||
      strcmp("titi", list->prev->prev->command) || strcmp("TOTO", list->prev->prev->prev->command))
    {
      printf("ordre de maillon fail\n");
      return (1);
    }
  printf("ZOZO ELLE ROKS !\n");
  return (0);
}

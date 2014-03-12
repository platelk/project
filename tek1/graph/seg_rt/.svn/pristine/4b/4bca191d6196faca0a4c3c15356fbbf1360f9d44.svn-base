/*
** free_info.c for free in /home/ozouf_h//rt_parse
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sat May  5 22:45:52 2012 harold ozouf
** Last update Sat May  5 22:54:16 2012 harold ozouf
*/

#include	<stdlib.h>
#include	"free_info.h"

void	free_info(t_info *inf)
{
  if (inf)
    {
      free(inf->xml);
      if (inf->type == TYPE_CLIENT)
	free(CLIENT->ip_server);
      if (inf->type == TYPE_NORMAL)
	if (NORMAL && NORMAL->exp != NULL)
	  free(NORMAL->exp);
      if (inf->type != TYPE_SERVER)
	free(inf->arg);
    }
}

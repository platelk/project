/*
** server_client_receive_plage.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun May  6 23:47:40 2012 ronan guiho
** Last update Sun Jun  3 19:53:38 2012 alexis leprovost
*/

#include <stdlib.h>

#include "mlx.h"
#include "parse.h"
#include "determ_export.h"
#include "export.h"
#include "global.h"
#include "server.h"

t_global	*global_thread;
pthread_mutex_t  mutex_server;

int		server_client_receive_display(t_normal_info *normal_info)

{
  if (normal_info->mute == 0)
    {
      pthread_mutex_lock(&mutex_server);
      global_thread->count_trame++;
      mlx_put_image_to_window(global_thread->window->mlx_ptr, \
			      global_thread->window->win_ptr, \
			      global_thread->thread[0].thread_image->ptr, \
			      0, 0);
      pthread_mutex_unlock(&mutex_server);
    }
  return (EXIT_SUCCESS);
}

int		server_client_receive_plage_x(char *buffer,
					      int x, int y)
{
  char		**tab;
  t_color	color;

  if ((tab = my_strtok(buffer, "/", 0)) == NULL)
    return (EXIT_FAILURE);
  color.red = my_getnbr(tab[0]);
  color.green = my_getnbr(tab[1]);
  color.blue = my_getnbr(tab[2]);
  mlx_ppti(global_thread->thread[0].thread_image, &color, x, y);
  return (EXIT_SUCCESS);
}

int		server_client_receive_global(t_normal_info *normal_info)
{
  server_client_receive_display(normal_info);
  if (global_thread->info.type == TYPE_SERVER && \
      global_thread->count_trame == global_thread->window->x_win)
    if (normal_info && normal_info->exp != NULL)
      determ_export(global_thread, normal_info->exp, 0);
  return (EXIT_SUCCESS);
}
void		*server_client_receive_plage(void *arg)
{
  int		i;
  int		x;
  char		**tab;
  char		*buffer;
  t_normal_info	*normal_info;

  i = 3;
  buffer = (char *)arg;
  normal_info = (t_normal_info *)global_thread->info.arg;
  if ((tab = my_strtok(buffer, "-", 0)) == NULL)
    return (NULL);
  x = my_getnbr(tab[0]);
  if (x > global_thread->window->x_win || x < 0)
    return (NULL);
  while (tab[i])
    {
      if ((server_client_receive_plage_x(tab[i], x, i - 3)) == EXIT_FAILURE)
	return (NULL);
      i++;
    }
  server_client_receive_global(normal_info);
  return (NULL);
}

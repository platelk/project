/*
** client_calculation.c for client in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat May  5 22:11:42 2012 ronan guiho
** Last update Sun Jun  3 00:07:06 2012 ronan guiho
*/

#include <stdlib.h>
#include <unistd.h>

#include "my.h"
#include "global.h"
#include "color.h"
#include "parse.h"
#include "server.h"
#include "thread.h"
#include "display.h"

SOCKET		csock;
t_global	*global_thread;

char		*client_calculation_y(int x, int y, double flag)
{
  t_color	*color;
  char		*buffer;
  t_thread	thread;

  thread.mode = TYPE_CLIENT;
  thread.antialiasing = global_thread->scene->antialiasing;
  thread.size[WIDTH] = global_thread->window->x_win;
  thread.size[HEIGHT] = global_thread->window->y_win;
  if ((color = display_image_pixel(&thread, x, y, flag)) == NULL)
    return (NULL);
  buffer = client_calculation_buffer(color);
  return (buffer);
}

int		client_calculation_x(int x, double flag)
{
  int		y;
  char		*tmp;
  char		*buffer;
  char		*tmp_color;

  y = 0;
  buffer = my_strdup("");
  while (y < global_thread->window->y_win)
    {
      tmp = buffer;
      if ((tmp_color = client_calculation_y(x, y, flag)) == NULL)
	return (EXIT_FAILURE);
      buffer = my_strconcat(buffer, tmp_color);
      free(tmp);
      y += flag;
    }

  if ((client_calculation_send(buffer, x, y)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  free(buffer);
  return (EXIT_SUCCESS);
}

void		*client_calculation_plage(void *arg)
{
  int		x;
  double	flag;
  t_plage	*plage;

  flag = global_thread->scene->antialiasing;
  flag = ((flag < 0.000) ? (flag * (-1.000)) : (1.000));
  plage = (t_plage *)arg;
  x = plage->X_start;
  while (x < plage->X_end)
    {
      if ((client_calculation_x(x, flag)) == EXIT_FAILURE)
	return (NULL);
      x += flag;
    }
  return (NULL);
}

int		client_calculation_thread(int *subdivision, t_plage *plage_arg, \
					  t_plage *plage_list, pthread_t *thread_p)
{
  int		value[2];

  value[0] = 0;
  value[1] = 0;

  while (value[1] < global_thread->info.nbr_thread)
    {
      plage_list[value[1]].X_start = plage_arg->X_start + value[0];
      plage_list[value[1]].X_end = plage_arg->X_start + value[0] + \
	subdivision[0];
      value[0] = value[0] + subdivision[0];
      value[1]++;
    }
  plage_list[value[1] - 1].X_end = plage_list[value[1] - 1].X_end + \
    subdivision[1];
  value[1] = -1;
  while (++value[1] < (global_thread->info.nbr_thread - 1))
    pthread_create(&thread_p[value[1]], NULL, \
		   client_calculation_plage, &plage_list[value[1]]);
  client_calculation_plage(&plage_list[value[1]]);
  return (EXIT_SUCCESS);
}
void		*client_calculation(void *arg)
{
  int		subdivision[2];
  t_plage	*plage_arg;
  t_plage	*plage_list;
  pthread_t	thread_p[1024];

  plage_arg = (t_plage *)arg;
  if ((plage_list = malloc(sizeof(*plage_list) * \
			   (global_thread->info.nbr_thread))) == NULL)
    return (NULL);
  subdivision[0] = (plage_arg->X_end - plage_arg->X_start) / \
    global_thread->info.nbr_thread;
  subdivision[1] = (plage_arg->X_end - plage_arg->X_start) % \
    global_thread->info.nbr_thread;
  client_calculation_thread(subdivision, plage_arg, \
			    plage_list, thread_p);
  return (NULL);
}


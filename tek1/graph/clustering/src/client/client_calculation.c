/*
** client_calculation.c for client in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat May  5 22:11:42 2012 ronan guiho
** Last update Mon May  7 12:58:54 2012 ronan guiho
*/

#include <stdlib.h>
#include <unistd.h>

#include "my.h"
#include "server.h"

/* TEST LIBX */
int TEST_RED;
int TEST_GREEN;
int TEST_BLUE;
/*==========*/

SOCKET		csock;

char		*test_composante(int y);
char		*test_composante(int y)
{
  char		*buffer;
  char		**tab;
  char		*tmp;

  (void)y;
  buffer = my_strdup("-");
  if ((tab = malloc(sizeof(char *) * 3)) == NULL)
    return (NULL);
  tab[0] = server_int_to_str(TEST_RED);
  tab[1] = server_int_to_str(TEST_GREEN);
  tab[2] = server_int_to_str(TEST_BLUE);
  tmp = buffer;
  buffer = my_strconcat(buffer, tab[0]);
  free(tmp);
  tmp = buffer;
  buffer = my_strconcat(buffer, "/");
  free(tmp);
  tmp = buffer;
  buffer = my_strconcat(buffer, tab[1]);
  free(tmp);
  tmp = buffer;
  buffer = my_strconcat(buffer, "/");
  free(tmp);
  tmp = buffer;
  buffer = my_strconcat(buffer, tab[2]);
  free(tmp);
  free(tab[0]);
  free(tab[1]);
  free(tab[2]);
  return (buffer);
}

int		client_calculation_x(int x)
{
  int		y;
  char		*buffer;
  char		*tmp_color;
  char		*tmp;

  y = 0;
  buffer = my_strdup("");
  while (y < HEIGHT)
    {
      tmp = buffer;
      if ((tmp_color = test_composante(y)) == NULL)
	return (EXIT_FAILURE);
      buffer = my_strconcat(buffer, tmp_color);
      free(tmp);
      y++;
    }
  if ((client_calculation_send(buffer, x, y)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  free(buffer);
  return (EXIT_SUCCESS);
}

void		*client_calculation_plage(void *arg)
{
  int		x;
  t_plage	*plage;

  plage = (t_plage *)arg;
  x = plage->X_start;
  while (x < plage->X_end)
    {
      if ((client_calculation_x(x)) == EXIT_FAILURE)
	return (NULL);
      x++;
    }
  return (NULL);
}

void		*client_calculation(void *arg)
{
  int		value[2];
  int		subdivision[2];
  t_plage	*plage_arg;
  t_plage	*plage_list;
  pthread_t	thread_p[CLIENT_THREAD];

  value[0] = 0;
  value[1] = 0;
  plage_arg = (t_plage *)arg;
  if ((plage_list = malloc(sizeof(*plage_list) * (CLIENT_THREAD))) == NULL)
    return (NULL);
  subdivision[0] = (plage_arg->X_end - plage_arg->X_start) / CLIENT_THREAD;
  subdivision[1] = (plage_arg->X_end - plage_arg->X_start) % CLIENT_THREAD;
  while (value[1] < CLIENT_THREAD)
    {
      plage_list[value[1]].X_start = plage_arg->X_start + value[0];
      plage_list[value[1]].X_end = plage_arg->X_start + value[0] + subdivision[0];
      value[0] = value[0] + subdivision[0];
      value[1]++;
    }
  plage_list[value[1] - 1].X_end = plage_list[value[1] - 1].X_end + subdivision[1];
  value[1] = -1;
  while (++value[1] < (CLIENT_THREAD - 1))
    pthread_create(&thread_p[value[1]], NULL, \
		   client_calculation_plage, &plage_list[value[1]]);
  pthread_create(&thread_p[value[1]], NULL, client_calculation_plage, &plage_list[value[1]]);
  return (NULL);
}

/*  x = plage->X_start;
    while (x < plage->X_end)
    {
    if ((client_calculation_x(x)) == EXIT_FAILURE)
    return (NULL);
    x++;
    }*/

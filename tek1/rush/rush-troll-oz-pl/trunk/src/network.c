/*
 ** network.c for teuquain in /home/vink/projet/rush/rush-troll-oz-pl/trunk
 **
 ** Made by kevin platel
 ** Login   <platel_k@epitech.net>
 **
 ** Started on  Thu Jun  7 11:03:00 2012 kevin platel
Last update Tue Jun 19 05:14:08 2012 kevin platel
 */

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>

#include	"my.h"
#include	"utils.h"
#include	"get_next_line.h"
#include	"teuquain.h"

  int *
create_door(int nb_door)
{
  int	*door;
  int	i;

  door = malloc(sizeof(*door) * nb_door);
  if (door == NULL)
    return (NULL);
  i = 0;
  while (i < nb_door)
  {
    door[i] = 0;
    i++;
  }
  return (door);
}

t_param	*
net_get_param(t_param *param)
{
  char	**tab;
  int	len;
  char	*buffer;

  buffer = get_next_line(0);
  if (buffer == NULL)
    return (NULL);
  tab = my_strtok(buffer, ":\n");
  my_show_wordtab(tab);
  fprintf(stderr, "Package = '%s' [%d]\n", buffer, my_tab_len(tab));
  if (tab == NULL || my_tab_len(tab) != 5)
    return (NULL);
  fprintf(stderr, "Package2 = '%s'\n", buffer);
  if (my_strcmp(tab[0], MAGIK) != 0)
    return (NULL);
  fprintf(stderr, "Package3 = '%s'\n", buffer);
  param->delai_attak = my_getnbr(tab[1]);
  param->nb_door = my_getnbr(tab[2]);
  param->door = create_door(param->nb_door);
  param->delai_door = my_getnbr(tab[3]);
  if (my_strcmp(tab[4], MAGIK) != 0)
    return (NULL);
  return (param);
}

t_attak	*
net_get_attak(char *buffer, t_attak *attak, int nb_door)
{
  char	**tab;

  tab = my_strtok(buffer, ":\n");
  if (tab == NULL || my_tab_len(tab) != 5)
    return (NULL);
  if (my_strcmp(tab[0], MAGIK) != 0)
    return (NULL);
  fprintf(stderr, "\tBegin...\n");
  attak->city = my_strdup(tab[1]);
  if (match(attak->city, "REN") == 0)
    return (NULL);
  fprintf(stderr, "\tCity = %s\n", attak->city);
  attak->login = my_strdup(tab[2]);
  if (match(attak->login, "platel_k") == 0 && match(attak->login, "ozouf_h") == 0)
    return (NULL);
  fprintf(stderr, "\tLogin = %s\n", attak->login);
  attak->num_door = my_getnbr(tab[3]);
  if (attak->num_door > nb_door || attak->num_door < 1)
    return (NULL);
  if (my_strcmp(tab[4], MAGIK) != 0)
    return (NULL);
  return (attak);
}

  int
add_attack(t_file_attak **file, char *buffer, int nb_door)
{
  t_file_attak	*new;
  t_file_attak	*tmp;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (1);
  tmp = *file;
  while (tmp && tmp->next)
    tmp = tmp->next;
  if (net_get_attak(buffer, &(new->attak), nb_door) == NULL)
    return (1);
  new->next = NULL;
  if (*file == NULL)
    *file = new;
  else
    tmp->next = new;
  return (0);
}

int	gest_event(char *buffer, t_param *param, t_attak *attak)
{
  if (attak)
  {
    if (my_strcmp("NYAN:AE:NYAN", buffer) == 0)
	  {
	    fprintf(stderr, "Attack on door nb %d is a fail !\n", attak->num_door);
	    return (1);
	  }
    if (my_strcmp("NYAN:AR:NYAN", buffer) == 0)
	  {
	    param->door[attak->num_door] = 1;
	    fprintf(stderr, "Attack on door nb %d is a SUCCESS !\n", attak->num_door);
	    return (1);
	  }
  }
  return (0);
}
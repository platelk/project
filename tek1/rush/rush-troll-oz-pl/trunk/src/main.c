/*
** main.c for teuquain in /home/vink/projet/rush/rush-troll-oz-pl/trunk/inc
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Thu Jun  7 10:54:28 2012 kevin platel
Last update Wed Jun 27 13:28:32 2012 kevin platel
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include	"my.h"
#include	"teuquain.h"
#include	"network.h"
#include	"get_next_line.h"
#define LOL (5)

int
main(int ac, char **av)
{
  t_param	param;
  char		*buffer;
  t_file_attak	*file;
  time_t	ref;
  int	i;

  fprintf(stderr, "teuquain: Start\n");
  fprintf(stderr, "send tram : <NYAN:HELO:platel_k:2016:REN:NYAN>\n");
  fprintf(stderr, "teuquain: get param...");
  while (net_get_param(&param) == NULL);
  fprintf(stderr, "\tOk!\n");
  fprintf(stderr, "teuquain: get packet ...\n");
  file = NULL;
  ref = time(NULL);
  while ((buffer = get_next_line(0)) || 1)
    {
      fprintf(stderr, "Buffer = [%s]\n", buffer);
      if (file && gest_event(buffer, &param, &(file->attak)))
	{
	  ref = time(NULL);
	  file = file->next;
	}
      else if (file && difftime(ref, time(NULL)) > ((double) param.delai_attak))
	{
	  fprintf(stderr, "Attack out of time!\n");
	  file = file->next;
	  ref = time(NULL);
	}
      else
	{
	  fprintf(stderr, "New Attack !\n");
	  add_attack(&file, buffer, param.nb_door);
	}
      if (file != NULL && difftime(ref, time(NULL)) > param.delai_attak)
	{
	  printf("NYAN:%d:NYAN\n", file->attak.num_door);
	  file = file->next;
	}
      usleep(1);
    }
  fprintf(stderr, "teuquain: End\n");
  return (0);
}

/*
** thread.h for rt in /home/guiho_r/tek1/rt/src/display
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat May 19 09:30:00 2012 ronan guiho
** Last update Sun Jun  3 10:46:12 2012 ronan guiho
*/

#ifndef __THREAD_H__
#define __THREAD_H__

#include  <pthread.h>

#include "global.h"

#define MAX_THREAD	 1024
#define MAX_THREAD_VALUE 6
#define THREAD_ID	 thread->thread_atribution[ID]
#define THREAD_COUNT	 global->info.nbr_thread

typedef enum
{
  ON,
  OFF,
  BAR
} e_thread_disp;

typedef enum
{
  ID,
  DISPLAY,
  X_MIN,
  Y_MIN,
  X_MAX,
  Y_MAX
} e_thread_value;

typedef enum
{
  AVAILABLE,
  BUSY
} e_state_thread;

struct s_thread
{
  int	       mode;
  int	       state;
  pthread_t    thread_p;
  t_image      *thread_image;
  t_color      color;
  int	       size[2];
  double	       antialiasing;
  int	       thread_atribution[MAX_THREAD_VALUE];
};

#endif

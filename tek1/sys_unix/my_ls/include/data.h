/*
** data.h for data in /home/platel_k/projet/my_ls/include
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Nov 21 17:45:54 2011 kevin platel
** Last update Thu Dec  1 12:08:02 2011 kevin platel
*/

#ifndef __DATA_H__
#define __DATA_H__

#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "my.h"

typedef struct s_data
{
  char *name;
  struct s_data *next;
  struct s_data *prev;
} t_data;

#endif

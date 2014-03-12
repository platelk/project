/*
** my_strtok.h for my_strtok in /home/leprov_a//afs/current/my_strtok
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Mon Apr 16 10:13:19 2012 alexis leprovost
** Last update Tue May 29 20:17:15 2012 zoe phalippou
*/

#ifndef __MY_STRTOK_H__
#define __MY_STRTOK_H__

#include	"my.h"

typedef enum e_type
{
  TOK_DELIM,
  TOK_BASE
} t_type;

char	**my_strtok(char *, char *, t_type);

#endif

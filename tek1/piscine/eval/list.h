/*
** list.h for list in /home/platel_k//projet/piscine/eval
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Oct 27 17:08:28 2011 kevin platel
** Last update Thu Oct 27 17:58:58 2011 kevin platel
*/

#ifndef __LIST_H__
#define __LIST_H__

typedef struct s_list
{
  char cha;
  struct s_list *next;
  struct s_list *befo;

} t_list;

#endif

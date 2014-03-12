/*
** attribute.h for attribute in /home/vink/projet/graph/rtv1/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Feb  8 10:30:11 2012 kevin platel
** Last update Wed Feb  8 10:38:29 2012 kevin platel
*/

#ifndef	__ATTRIBUTE_H__
#define __ATTRIBUTE_H__

typedef struct s_attr
{
  char	*name;
  char	*value;
  void	*father;
  struct s_attr	*next;
  struct s_attr	*prev;
} t_attr;

#endif

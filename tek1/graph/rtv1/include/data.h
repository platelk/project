/*
** data.h for data in /home/platel_k/projet/graph/rtv1/include
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Feb  1 10:03:50 2012 kevin platel
** Last update Wed Feb  1 13:33:48 2012 kevin platel
*/

#include __DATA_H__
#define  __DATA_H__

#include "dep.h"

typedef struct s_data
{
  int	type;
  char	*name;
  char	**attr;
  void	*value;
  t_dependence *dep;
  struct s_data *parent;
  struct s_data *next;
  struct s_data *prev;
} t_data;

#endif

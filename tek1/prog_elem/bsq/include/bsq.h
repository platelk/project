/*
** bsq.h for bsq in /home/platel_k/projet/bsq/include
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Dec  8 15:42:29 2011 kevin platel
** Last update Fri Dec  9 16:15:15 2011 kevin platel
*/

#ifndef __BSQ_H__
#define __BSQ_H__

typedef struct s_square
{
  int	x;
  int	y;
  int	size;
} t_square;

void	put_res(char **data, t_square *big);
int	project(char **data, int x, int y, char direc);
char	**get_data(char *link);
int	find_square(char **data, int x, int y, int size);
int	big_square(char **data, int x, int y, t_square *big);
int	project_on_x(char **data, int x, int y);
int	project_on_y(char **data, int x, int y, int max);
void	freewordtab(char **tab);
t_square	*new_square(int x, int y, int size, t_square *big);

#endif

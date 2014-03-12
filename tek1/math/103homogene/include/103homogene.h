/*
** 103homogene.h for 103homogene
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Thu Dec 15 13:51:45 2011 matthieu przybylski
** Last update Thu Dec 15 16:47:38 2011 matthieu przybylski
*/

#ifndef __103HOMOGENE_H__
#define __103HOMOGENE_H__

#define	COLUMN	3
#define	LINE	3

int	**parsing(int ac, char **av);
float	*create_matrix(int **pars);
float   *mult_matrix(float *m1, float *m2);
float   *init_result();
void    show_result(float *result);
float   *translation(int *arg);
float   *homotetie(int *arg);
float   *rotation(int *arg);
float   *symetrie(int *arg);

#endif /* __103HOMOGENE_H__ */

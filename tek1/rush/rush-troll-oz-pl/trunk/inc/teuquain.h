/*
** teuquain.h for teuquain in /home/vink/projet/rush/rush-troll-oz-pl/trunk/inc
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Thu Jun  7 10:43:25 2012 kevin platel
** Last update Fri Jun  8 17:30:35 2012 kevin platel
*/

#ifndef __TEUQUAIN_H__
#define __TEUQUAIN_H__

#define	MAGIK	"NYAN"

typedef struct s_param
{
  int	delai_attak;
  int	nb_door;
  int	delai_door;
  int	*door;
} t_param;

typedef struct s_attak
{
  char	*city;
  char	*login;
  int	num_door;
} t_attak;

typedef struct s_file_attak
{
  t_attak	attak;
  struct s_file_attak	*next;
} t_file_attak;

#endif

/*
** champ.h for Corewar in /home/guiho_r//tek1/corewar/include
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Jan 27 13:24:19 2012 ronan guiho
** Last update Tue Mar 20 13:39:11 2012 alexis leprovost
*/

#ifndef	__CHAMP_H__
#define __CHAMP_H__

typedef enum rgb
{
  RED,
  GREEN,
  BLUE
}e_rgb;

typedef struct s_champ
{
  int	*reg;
  char	*bin;
  char	*prog_name;
  int	*data;
  int	prog_size;
  int	*color;
  int	instruct;
  int	cycle_instruct;
  char	**detail;
  struct s_champ	*next;
  struct s_champ	*before;
} t_champ;

typedef enum
{
  ID,
  PC,
  CARRY,
  ADDR,
  LIVE
} e_data;

#endif

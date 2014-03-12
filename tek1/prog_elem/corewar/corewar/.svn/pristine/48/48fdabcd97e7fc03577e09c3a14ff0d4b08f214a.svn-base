/*
** vm.h for Corewar in /home/guiho_r//tek1/corewar/include
** 
** Made by ronan guiho
p** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Jan 27 13:21:20 2012 ronan guiho
** Last update Sun Mar 25 19:20:51 2012 ronan guiho
*/

#ifndef	__VM_H__
#define	__VM_H__

#include <pthread.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

#include "mem.h"
#include "image.h"
#include "param.h"
#include "champ.h"
#include "sound.h"

#define MAX_BIN_SIZE    18

#define	WAIT	-1
#define READY	0

#define SIZE_DATA	5
#define MAX_CHAMPS_NUMBER	4

#define X_MEM		509
#define Y_MEM		245
#define WIDTH_MEM	671
#define HEIGHT_MEM	463

#define	X_BUTTON_START  75
#define Y_BUTTON_START  80

#define	X_BUTTON_EXIT   75
#define Y_BUTTON_EXIT   310

#define	X_WIN	1680
#define	Y_WIN	1050
#define	NAME_WIN	"--Corewar--"

typedef struct s_vm
{
  t_mem	*mem;
  t_param	*param;
  t_champ	*champ;
  t_champ	*winner;
  int	nb_champ;
  t_sound	**sound;
  t_image	**image;
  SDL_Surface	*sc;
  SDL_Surface	*sc_mem;
  int		cycle_to_die;
  pthread_t	thread;
  int		no_graph;
} t_vm;

#endif

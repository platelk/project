/*
** image.h for corewar in /home/guiho_r/tek1/corewar/include
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Mar  7 18:08:31 2012 ronan guiho
** Last update Sun Mar 25 22:51:18 2012 ronan guiho
*/

#ifndef	__IMAGE_H__
#define	__IMAGE_H__

#define	EPSILON	1250
#define	WAWE	0
#define	MIST	1
#define	SPIRAL	2
#define	EDGE	3
#define	NB_ANIM_MAX	4
#define	NB_IMAGE_TYPE_MAX	3
#define NB_IMAGE_GAME_MAX	18
#define NB_IMAGE_MENU_MAX	5
#define NB_IMAGE_CHARACT_MAX	13
#define FORMAT_IMAGE		".png"
#define PATH_IMAGE_GAME		"./clips/template/game/"
#define PATH_IMAGE_MENU		"./clips/template/menu/"
#define PATH_IMAGE_CHARACT	"./clips/template/character/"
#define	PATH_FONT_DECOMPT	"./clips/font/"
#define	BLOC_ANIM	100

typedef enum
{
  MENU_IMG,
  GAME,
  CHARACT
} e_img_type;

typedef enum
{
  BACK,
  BUTTON_ON,
  BUTTON_HOLD,
  BUTTON_EX_ON,
  BUTTON_EX_HOLD
} e_img_menu;

typedef enum
{
  BACK_IG,
  DESK_LEFT,
  DESK_RIGHT,
  PROJECTOR,
  CHAIR,
  BACK_RIGHT,
  BACK_LEFT,
  TEXT,
  TIME,
  KENNY_CARD,
  KYLE_CARD,
  CARTMAN_CARD,
  STAN_CARD,
  MSG_KENNY,
  KENNY_ANGEL,
  BLOOD,
  GENERIQUE,
  CARTMAN_FRONT
} e_img_game;

typedef enum
{
  STAN_BACK,
  KYLE_BACK,
  KENNY_BACK,
  CARTMAN_BACK,
  STAN_LEFT,
  KENNY_LEFT,
  CARTMAN_LEFT,
  KYLE_LEFT,
  SCROLL_LIVE_KYLE,
  STAN_DIE,
  KENNY_DIE,
  KYLE_DIE,
  CARTMAN_DIE
} e_img_char;

typedef struct s_image
{
  SDL_Surface  *img;
  SDL_Rect     pos;
} t_image;

#endif

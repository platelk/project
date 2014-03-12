/*
** event_key.c for raytracer in /home/leprov_a//depot/rt
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue May  1 21:26:40 2012 alexis leprovost
** Last update Sat Jun  2 09:35:13 2012 jordan vanwalleghem
*/

#include	<stdlib.h>

#include	"keycode.h"
#include	"raytracer.h"
#include	"global.h"
#include	"object.h"
#include	"scene.h"
#include	"display.h"
#include	"object.h"
#include	"free.h"

static int	move_object(t_object *object, int status, int param)
{
  int	flag;
  int	axe;

  if (object == NULL)
    return (EXIT_FAILURE);
  flag = (status == UP || status == ADD || status == LEFT) ? 1 : -1;
  if (status == UP || status == DOWN)
    axe = X;
  if (status == RIGHT || status == LEFT)
    axe = Y;
  if (status == ADD || status == SUB)
    axe = Z;
  if (param)
    object->rotation[axe] += (flag * 10);
  else
    object->position[axe] += (flag * 1);
  return (EXIT_SUCCESS);
}

static int	move_color(t_object *object, int status, int param)
{
  int	flag;

  if (object == NULL || object->color == NULL)
    return (EXIT_FAILURE);
  flag = status == ADD ? 1 : -1;
  if (param == RED)
    object->color->red = CAST(object->color->red + (flag * 20));
  if (param == GREEN)
    object->color->green = CAST(object->color->green + (flag * 20));
  if (param == BLUE)
    object->color->blue = CAST(object->color->blue + (flag * 20));
  return (EXIT_SUCCESS);
}

static int	move_effect(t_object *object, int status, int param)
{
  double	flag;
  int	effect;

  if (object == NULL)
    return (EXIT_FAILURE);
  effect = param == TP ? TRANSPARENCY :
    param == RP ? REFLECTION :
    param == PP ? PHONG : BRIGHTNESS;
  if (effect == PHONG)
    flag = status == ADD ? 1.0F : -1.0F;
  else
    flag = status == ADD ? 0.1F : -0.1F;
  if (param == TP || param == RP || param == BP)
    {
      object->effect[effect] += flag;
      object->effect[effect] = object->effect[effect] < 0.0F ? 0.0F :
	object->effect[effect] > 1.0F ? 1.0F : object->effect[effect];
    }
  else
    {
      object->effect[effect] += (flag * 100);
      object->effect[effect] = object->effect[effect] < 1.0F ? 1.0F :
	object->effect[effect];
    }
  return (EXIT_SUCCESS);
}

void	event_key_n(int keycode, t_global *global)
{
  if (global->param == POSITION || global->param == ROTATION)
    move_object(global->object, keycode, global->param);
  if ((global->param == RED ||
       global->param == GREEN || global->param == BLUE) &&
      (keycode == ADD || keycode == SUB))
    move_color(global->object, keycode, global->param);
  if ((global->param == TP || global->param == PP ||
       global->param == RP || global->param == BP) &&
      (keycode == ADD || keycode == SUB))
    move_effect(global->object, keycode, global->param);
  if (global->param == AA && (keycode == ADD || keycode == SUB))
    keycode == ADD ? (global->scene->antialiasing += 1.0F) :
      (global->scene->antialiasing -= 1.0F);
  display_image(global);
}

int	event_key(int keycode, t_global *global)
{
  if (global == NULL)
    return (EXIT_FAILURE);
  if (keycode == ESC)
    {
      free_global(global);
      exit(EXIT_FAILURE);
    }
  if (keycode == ENTER || keycode == SPACE)
    global->param = keycode == ENTER ? POSITION : ROTATION;
  if (keycode == 'a')
    global->param = AA;
  if (keycode == 't' || keycode == 'p'
      || keycode == 'i' || keycode == 's')
    global->param = keycode == 't'
      ? TP : keycode == 'i' ? RP : keycode == 'p' ? PP : BP;
  if (keycode == 'r' || keycode == 'g' || keycode == 'b')
    global->param = keycode == 'r' ? RED : keycode == 'g' ? GREEN : BLUE;
  if (keycode == UP || keycode == DOWN || keycode == LEFT ||
      keycode == RIGHT || keycode == ADD || keycode == SUB)
    event_key_n(keycode, global);
  return (EXIT_SUCCESS);
}

/*
** transformations.c for 103homogene.c in /home/przyby_m/projet/103homogene
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Thu Dec 15 16:30:28 2011 matthieu przybylski
** Last update Fri Dec 16 10:00:34 2011 matthieu przybylski
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "103homogene.h"

#define	RAD(x)	(((x) * (3.14159265)) / 180)

float	*translation(int *arg)
{
  float	*matrix;

  printf("Translation de vecteur (%d, %d)\n", arg[1], arg[2]);
  matrix = malloc((COLUMN * LINE) * sizeof(*matrix));
  matrix[0] = 1;
  matrix[1] = 0;
  matrix[2] = arg[1];
  matrix[3] = 0;
  matrix[4] = 1;
  matrix[5] = arg[2];
  matrix[6] = 0;
  matrix[7] = 0;
  matrix[8] = 1;
  return (matrix);
}

float	*homotetie(int *arg)
{
  float	*matrix;

  printf("Homotétie de rapport %d et %d\n", arg[1], arg[2]);
  matrix = malloc((COLUMN * LINE) * sizeof(*matrix));
  matrix[0] = arg[1];
  matrix[1] = 0;
  matrix[2] = 0;
  matrix[3] = 0;
  matrix[4] = arg[2];
  matrix[5] = 0;
  matrix[6] = 0;
  matrix[7] = 0;
  matrix[8] = 1;
  return (matrix);
}

float	*rotation(int *arg)
{
  float	*matrix;

  printf("Rotation d'angle %d\n", arg[1]);
  matrix = malloc((COLUMN * LINE) * sizeof(*matrix));
  matrix[0] = cosf(RAD(arg[1]));
  matrix[1] = -(sinf(RAD(arg[1])));
  matrix[2] = 0;
  matrix[3] = sinf(RAD(arg[1]));
  matrix[4] = cosf(RAD(arg[1]));
  matrix[5] = 0;
  matrix[6] = 0;
  matrix[7] = 0;
  matrix[8] = 1;
  return (matrix);
}

float	*symetrie(int *arg)
{
  float	*matrix;

  printf("Symétrie par rapport à un axe incliné de %d\n", arg[1]);
  matrix = malloc((COLUMN * LINE) * sizeof(*matrix));
  matrix[0] = cosf(2 * RAD(arg[1]));
  matrix[1] = sinf(2 * RAD(arg[1]));
  matrix[2] = 0;
  matrix[3] = sinf(2 * RAD(arg[1]));
  matrix[4] = -(cosf(2 * RAD(arg[1])));
  matrix[5] = 0;
  matrix[6] = 0;
  matrix[7] = 0;
  matrix[8] = 1;
  return (matrix);
}

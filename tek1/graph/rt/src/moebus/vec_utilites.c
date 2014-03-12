/*
** vec_utilites.c for moebus in /home/vink/projet/graph/rt/src/xml_src/src
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:25:28 2012 kevin platel
** Last update Sun Jun  3 16:25:28 2012 kevin platel
*/

#include	<math.h>
#include	"moebus.h"
#include	"vec3_utilities.h"

t_vec3 *make_vec3(double x, double y, double z, t_vec3 *out)
{
  out->x = x;
  out->y = y;
  out->z = z;
  return (out);
}

double lenth_vec3(t_vec3 *in)
{
  return (sqrt((in->x * in->x) + (in->y * in->y) + (in->z * in->z)));
}

t_vec3 *normalise_vec3(t_vec3 *in)
{
  double lenth;

  lenth = lenth_vec3(in);
  if (!EQUALZERO(lenth))
    {
      in->x = in->x / lenth;
      in->y = in->y / lenth;
      in->z = in->z / lenth;
    }
  return (in);
}

t_vec3 *substract_vec3(t_vec3 *inA, t_vec3 *inB, t_vec3 *out)
{
  out->x = inA->x - inB->x;
  out->y = inA->y - inB->y;
  out->z = inA->z - inB->z;
  return (out);
}

t_vec3 *vectorial_product3(t_vec3 *inA, t_vec3 *inB, t_vec3 *out)
{
  out->x = (inA->y * inB->z) - (inA->z * inB->y);
  out->y = (inA->z * inB->x) - (inA->x * inB->z);
  out->z = (inA->x * inB->y) - (inA->y * inB->x);
  return (out);
}

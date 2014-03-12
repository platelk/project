/*
** vec_utilites.c for moebus in /home/vink/moebus
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Tue May 22 09:14:57 2012 kevin platel
** Last update Tue May 22 09:39:04 2012 kevin platel
*/

#include	<math.h>
#include	"vec3_utilities.h"

t_vec3 make_vec3(double x, double y, double z)
{
  t_vec3 out;

  out.x = x;
  out.y = y;
  out.z = z;
  return out;
}

t_vec3 normalise_vec3(t_vec3 in)
{
  double lenth;

  lenth = sqrt(in.x*in.x+in.y*in.y+in.z*in.z);
  if(lenth != 0)
    {
      in.x = in.x / lenth;
      in.y = in.y / lenth;
      in.z = in.z / lenth;
    }
  return (in);
}

double lenth_vec3(t_vec3 in)
{
  return (sqrt(in.x*in.x+in.y*in.y+in.z*in.z));
}

t_vec3 substract_vec3(t_vec3 inA,t_vec3 inB)
{
  t_vec3 out;

  out.x = inA.x - inB.x;
  out.y = inA.y - inB.y;
  out.z = inA.z - inB.z;
  return out;
}

t_vec3 vectorial_product3(t_vec3 inA, t_vec3 inB)
{
  t_vec3 out;

  out.x = inA.y*inB.z - inA.z*inB.y;
  out.y = inA.z*inB.x - inA.x*inB.z;
  out.z = inA.x*inB.y - inA.y*inB.x;
  return out;
}

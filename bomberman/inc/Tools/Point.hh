//
// Point.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev/inc/Client/Tool
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Sun May 12 12:28:47 2013 alexis leprovost
// Last update Fri May 17 14:40:27 2013 alexis leprovost
//

#ifndef __POINT_HH__
#define __POINT_HH__

#include <sys/types.h>

struct Point
{
  int x;
  int y;

  Point();
  Point(int x, int y);
  Point(Point const& cpy);
  Point &operator=(Point const& cpy);

  static Point	convert(Point const& point, Point const& landmark);
  static Point	convert(int x, int y, int xx, int yy);
};

#endif

//
// Point.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev/inc/Client/Tool
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Sun May 12 12:29:46 2013 alexis leprovost
// Last update Mon May 20 13:13:38 2013 alexis leprovost
//

#include "Point.hh"

Point::Point()
  : x(0), y(0)
{

}

Point::Point(int x, int y)
  : x(x), y(y)
{

}

Point::Point(const Point &cpy)
  : x(cpy.x), y(cpy.y)
{

}

Point&	Point::operator=(Point const& cpy)
{
  if (this != &cpy)
    {
      this->x = cpy.x;
      this->y = cpy.y;
    }
  return (*this);
}

Point	Point::convert(Point const& point, Point const& landmark)
{
  Point	convert;

  convert.x = point.x - landmark.x;
  convert.y = -point.y + landmark.y;
  return (convert);
}

Point	Point::convert(int x, int y, int xx, int yy)
{
  return (Point::convert(Point(x, y), Point(xx, yy)));
}

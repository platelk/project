//
// Color.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Fri May 17 15:25:10 2013 alexis leprovost
// Last update Fri May 17 15:26:32 2013 alexis leprovost
//

#ifndef _COLOR_H_
#define _COLOR_H_

struct Color
{
  float red;
  float green;
  float blue;

  Color();
  Color(float red, float green, float blue);
  ~Color();
};

#endif /* _COLOR_H_ */

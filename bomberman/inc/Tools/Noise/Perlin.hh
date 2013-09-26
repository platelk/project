#ifndef __PERLIN_H__
# define __PERLIN_H__

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

class Perlin2D
{
private:

  float			_gradient[8][2];
  float			_unit;
  std::vector<int>	_perm;
  float			_res;

public:
  Perlin2D(float res);
  virtual ~Perlin2D();

  void	jubble();

  float	getValue(float x, float y);
  float	getValue(float x, float y, float res);
};

#endif /* !__PERLIN_H__ */

//
// Perlin.cpp for /home/vink/projet/cpp/bomberman/src/Tools/Noise/Perlin.cpp in /home/vink/projet/cpp/bomberman/src/Tools/Noise
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Thu May 30 18:54:31 2013 kevin platel
// Last update Sun Jun  2 14:53:56 2013 kevin platel
//

#include "Perlin.hh"

Perlin2D::Perlin2D(float res)
  : _res(res)
{
  this->_unit = 1/sqrt(2);
  for (int i = 0; i <= 256; ++i) this->_perm.push_back(i);
  this->jubble();

  this->_gradient[0][0] = this->_unit;
  this->_gradient[0][1] = this->_unit;

  this->_gradient[1][0] = -this->_unit;
  this->_gradient[1][1] = this->_unit;

  this->_gradient[2][0] = this->_unit;
  this->_gradient[2][1] = -this->_unit;

  this->_gradient[3][0] = -this->_unit;
  this->_gradient[3][1] = -this->_unit;

  this->_gradient[4][0] = 1.0;
  this->_gradient[4][1] = 0.0;

  this->_gradient[5][0] = -1.0;
  this->_gradient[5][1] = 0.0;

  this->_gradient[6][0] = 0.0;
  this->_gradient[6][1] = 1.0;

  this->_gradient[7][0] = 0.0;
  this->_gradient[7][1] = -1.0;

}

Perlin2D::~Perlin2D()
{
}

void	Perlin2D::jubble()
{
  std::random_shuffle(this->_perm.begin(), this->_perm.end());
}

float	Perlin2D::getValue(float x, float y)
{
  return this->getValue(x, y, this->_res);
}

float	Perlin2D::getValue(float x, float y, float res)
{
  float tempX,tempY;
  int x0,y0,ii,jj,gi0,gi1,gi2,gi3;
  float tmp,s,t,u,v,Cx,Cy,Li1,Li2;

  x /= res;
  y /= res;

  x0 = (int)(x);
  y0 = (int)(y);

  ii = x0 & 255;
  jj = y0 & 255;

  gi0 = this->_perm[ii + this->_perm[jj]] % 8;
  gi1 = this->_perm[ii + 1 + this->_perm[jj]] % 8;
  gi2 = this->_perm[ii + this->_perm[jj + 1]] % 8;
  gi3 = this->_perm[ii + 1 + this->_perm[jj + 1]] % 8;

  tempX = x-x0;
  tempY = y-y0;
  s = this->_gradient[gi0][0]*tempX + this->_gradient[gi0][1]*tempY;

  tempX = x-(x0+1);
  tempY = y-y0;
  t = this->_gradient[gi1][0]*tempX + this->_gradient[gi1][1]*tempY;

  tempX = x-x0;
  tempY = y-(y0+1);
  u = this->_gradient[gi2][0]*tempX + this->_gradient[gi2][1]*tempY;

  tempX = x-(x0+1);
  tempY = y-(y0+1);
  v = this->_gradient[gi3][0]*tempX + this->_gradient[gi3][1]*tempY;

  tmp = x-x0;
  Cx = 3 * tmp * tmp - 2 * tmp * tmp * tmp;

  Li1 = s + Cx*(t-s);
  Li2 = u + Cx*(v-u);

  tmp = y - y0;
  Cy = 3 * tmp * tmp - 2 * tmp * tmp * tmp;

  return Li1 + Cy*(Li2-Li1);
}

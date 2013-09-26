//
// Particle.hh for Particle in /home/guiho_r/depot/particule_engine/src
// 
// Made by ronan guiho
// Login   <guiho_r@epitech.net>
// 
// Started on  Wed Jun  5 18:30:03 2013 ronan guiho
// Last update Sat Jun  8 16:32:56 2013 ronan guiho
//

#ifndef __PARTICLE_HH__
#define __PARTICLE_HH__

#include "Image.hpp"
#include "Vector.hh"

typedef enum
{
  ISO = 0,
  RECT,
  ANY
} Pattern;

class Particle
{
private:
  Vector _pos;
  Vector _dir;
  Vector _rot;
  Vector _gravity;
  Vector _speed;
  float _life;
  float _fade;
  bool _alive;
  Vector _size;
  Vector _color;
  Pattern _pattern;
  gdl::Image _texture;
  std::string _path_texture;
public:
  Particle(const Vector &pos, const Vector &dir, const Vector &rot,
	   const Vector &gravity, const Vector &speed,
	   const float life, const float fade, const float size, const Pattern pattern,
	   const gdl::Image &text);
  Particle(const Vector &pos, const Vector &dir, const Vector &rot,
	   const Vector &gravity, const Vector &speed,
	   const float life, const float fade, const float size, const Pattern pattern,
	   const Vector &color);
  Particle(const Particle &particle);
  void setPosition(const Vector &pos);
  const Vector &getPosition() const;
  const Vector &getDirection() const;
  const Vector &getGravity() const;
  const Vector &getRotation() const;
  const Vector &getSpeed() const;
  const Vector &getSize() const;
  const Vector &getColor() const;
  const Pattern &getPattern() const;
  const std::string &getPathTexture() const;
  float getLife() const;
  float getFade() const;
  bool isAlive() const;
  void reset(const Particle &reset);
  void initialize();
  void update();
  void draw();
};

#endif

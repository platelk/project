//
// Camera.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Wed May 15 12:12:34 2013 alexis leprovost
// Last update Sun Jun  9 00:04:36 2013 alexis leprovost
//

#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "GameClock.hpp"
#include "Input.hpp"
#include "Vector.hh"
#include "Client/Interface/IWidgetObject.hh"

namespace Client
{
  class Camera : public IWidgetObject
  {
  private:
    Vector				_eye;
    Vector				_center;
    float				_fov;
    float				_ratio;
  public:
    Camera(float fov = 100.0f, float ratio = 1.3f);
    virtual ~Camera();

    void	setEye(float x, float y, float z);
    void	setCenter(float x, float y, float z);
    void	setEye(Vector eye);
    void	setCenter(Vector center);
    void	setFov(float fov);
    void	setRatio(float ratio);

    Vector	getEye() const;
    Vector	getCenter() const;
    float	getFov() const;
    float	getRatio() const;

    virtual void	initialize();
    virtual void	update(Event* event);
    virtual void	draw();
    virtual void	unload();

    static Vector	position;
  };
}

#endif /* _CAMERA_H_ */

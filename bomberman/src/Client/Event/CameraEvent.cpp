//
// CameraEvent.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev/src/Client/Interface
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Wed May 15 16:40:07 2013 alexis leprovost
// Last update Thu Jun  6 13:43:11 2013 alexis leprovost
//

#include "Client/Event/CameraEvent.hh"

namespace Client
{
  CameraEvent::CameraEvent()
    : Event(Event::CAMERA, ""),
      _eye(0.0f, 0.0f, 0.0f),
      _center(0.0f, 0.0f, 0.0f),
      _fov(0.0f),
      _ratio(0.0f)
  {

  }

  CameraEvent::CameraEvent(float ex, float ey, float ez, float cx, float cy, float cz,
			   float fov, float ratio)
    : Event(Event::CAMERA, ""),
      _eye(ex, ey, ez),
      _center(cx, cy, cz),
      _fov(fov),
      _ratio(ratio)
  {

  }


  CameraEvent::~CameraEvent()
  {

  }

  void	CameraEvent::setEye(float x, float y, float z)
  {
    this->_eye.x = x;
    this->_eye.y = y;
    this->_eye.z = z;
  }

  void	CameraEvent::setCenter(float x, float y, float z)
  {
    this->_center.x = x;
    this->_center.y = y;
    this->_center.z = z;
  }

  void	CameraEvent::setFov(float fov)
  {
    this->_fov = fov;
  }

  void	CameraEvent::setRatio(float ratio)
  {
    this->_ratio = ratio;
  }

  Vector const&	CameraEvent::getEye() const
  {
    return (this->_eye);
  }

  Vector const&	CameraEvent::getCenter() const
  {
    return (this->_center);
  }

  float		CameraEvent::getFov() const
  {
    return (this->_fov);
  }

  float		CameraEvent::getRatio() const
  {
    return (this->_ratio);
  }
}

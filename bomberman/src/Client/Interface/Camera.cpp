//
// Camera.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Wed May 15 12:12:54 2013 alexis leprovost
// Last update Sun Jun  9 00:05:04 2013 alexis leprovost
//

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Client/Interface/Camera.hh"
#include "Client/Interface/Interface.hh"
#include "Client/Event/CameraEvent.hh"

namespace Client
{
  Vector	Camera::position = Vector(0.0f, 0.0f, 0.0f);

  Camera::Camera(float fov, float ratio)
    : IWidgetObject(Interface::CAMERA),
      _eye(0.0f, 0.0f, 0.0f),
      _center(0.0f, 0.0f, 0.0f),
      _fov(fov),
      _ratio(ratio)
  {

  }

  Camera::~Camera()
  {

  }

  void Camera::initialize(void)
  {

  }

  void	Camera::update(Event* event)
  {
    CameraEvent*	cameraEvent = dynamic_cast<CameraEvent*>(event);

    if (cameraEvent)
      {
	this->_eye = cameraEvent->getEye();
	this->_center = cameraEvent->getCenter();
	this->_fov = cameraEvent->getFov();
	this->_ratio = cameraEvent->getRatio();
      }
  }

  void	Camera::draw()
  {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(this->_fov, this->_ratio, 1.0f, 100000.0f);
    gluLookAt(this->_eye.x, this->_eye.y, this->_eye.z,
	      this->_center.x, this->_center.y, this->_center.z,
	      0.0f, 1.0f, 0.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
  }

  void	Camera::unload()
  {

  }

  void	Camera::setEye(float x, float y, float z)
  {
    this->_eye.x = x;
    this->_eye.y = y;
    this->_eye.z = z;
  }

  void	Camera::setEye(Vector eye)
  {
    this->_eye = eye;
  }

  void	Camera::setCenter(float x, float y, float z)
  {
    this->_center.x = x;
    this->_center.y = y;
    this->_center.z = z;
  }

  void	Camera::setCenter(Vector center)
  {
    this->_center = center;
  }

  void	Camera::setFov(float fov)
  {
    this->_fov = fov;
  }

  void	Camera::setRatio(float ratio)
  {
    this->_ratio = ratio;
  }

  Vector	Camera::getEye() const
  {
    return (this->_eye);
  }

  Vector	Camera::getCenter() const
  {
    return (this->_center);
  }

  float		Camera::getFov() const
  {
    return (this->_fov);
  }

  float		Camera::getRatio() const
  {
    return (this->_ratio);
  }
}

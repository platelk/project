//
// CameraEvent.hh for bomberman in /home/leprov_a//project/tek2/bomberman/dev/src/Client/Interface
// 
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
// 
// Started on  Wed May 15 16:40:25 2013 alexis leprovost
// Last update Thu Jun  6 13:43:21 2013 alexis leprovost
//

#ifndef _CAMERAEVENT_H_
#define _CAMERAEVENT_H_

#include <string>

#include "Client/Event/Event.hh"
#include "Vector.hh"

namespace Client
{
  class CameraEvent : public Event
  {
    Vector	_eye;
    Vector	_center;
    float	_fov;
    float	_ratio;
  public:
    CameraEvent();
    CameraEvent(float ex, float ey, float ez, float cx, float cy, float cz,
		float fov, float ratio);
    virtual ~CameraEvent();

    void	setEye(float x, float y, float z);
    void	setCenter(float x, float y, float z);
    void	setFov(float fov);
    void	setRatio(float ratio);

    Vector const&	getEye() const;
    Vector const& 	getCenter() const;
    float		getFov() const;
    float		getRatio() const;

    static std::string const	EYE;
    static std::string const	CENTER;
    static std::string const	FOV;
    static std::string const	RATIO;
    static std::string const	ALL;
  };
}

#endif /* _CAMERAEVENT_H_ */

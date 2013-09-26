//
// InputJoy.cpp for /home/phalip_z/projet_tek2/Bomberman/controller/src/InputJoy.cpp in /home/phalip_z//projet_tek2/Bomberman/controller/inc
// 
// Made by phalip_z
// Login   <phalip_z@epitech.net>
// 
// Started on  Wed May 15 13:37:14 2013 phalip_z
// Last update Tue Jun  4 16:23:49 2013 phalip_z
//

#include	<sys/select.h>
#include	<sys/time.h>
#include	<unistd.h>
#include	<sstream>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<iostream>
#include	<stdlib.h>
#include	<strings.h>

#include	"Client/Controller/InputJoystick.hh"

namespace Client
{
  InputJoystick::InputJoystick(void)
    : _nb_joy(0), _way_joy("/dev/input/js"), _up(true)
  {
  }

  InputJoystick::~InputJoystick(){}

  bool	InputJoystick::isJoyButtonUp(void)
  {
    if (this->_up == true)
      {
	this->_up = false;
	return true;
      }
    else
      this->_up = true;
    return false;
  }

  bool	InputJoystick::isJoyButtonDown(InputJoystick::Button button, int idjoy)
  {
    if (((this->_joysticks[idjoy]).second).type /*& ~JS_EVENT_INIT)*/ == JS_EVENT_BUTTON)
      if (((this->_joysticks[idjoy]).second).number == button)
	if (((this->_joysticks[idjoy]).second).value == true)
	  return true;
    return false;
  }

  int	InputJoystick::getAxisPos(InputJoystick::Axis axis, int idjoy)
  {
    if ((((this->_joysticks[idjoy]).second).type & ~JS_EVENT_INIT) == JS_EVENT_AXIS)
      {
	if (((this->_joysticks[idjoy]).second).number == axis)
	  {
	    if ((axis == InputJoystick::AZ || axis == InputJoystick::BZ)
		&& ((this->_joysticks[idjoy]).second).value == 32767)
	      return ((this->_joysticks[idjoy]).second).value;
	    else if ((axis == InputJoystick::AX || axis == InputJoystick::AY ||
		      axis == InputJoystick::BX ||  axis == InputJoystick::BY)
		     && (((this->_joysticks[idjoy]).second).value > 25000
			 || ((this->_joysticks[idjoy]).second).value < -30000))
	      return ((this->_joysticks[idjoy]).second).value;
	    else
	      return 0;
	  }
	return 1;
      }
    return 1;
  }

  int	InputJoystick::nbJoystick(void) const
  {
    return _nb_joy;
  }

  void	InputJoystick::readFd(int idjoy)
  {
    read((this->_joysticks[idjoy].first)->getFd(),
	 &(this->_joysticks[idjoy].second), sizeof(struct js_event));
  }


  void	InputJoystick::active(void)
  {
    fd_set	readfds;
    int		i = -1;
    int		max_fd;
    timeval     time;


    time.tv_sec = 0;
    time.tv_usec = 10;
    FD_ZERO(&readfds);
    if (this->_nb_joy == 0)
      return;
    max_fd = (this->_joysticks[0].first)->getFd();
    while (++i < this->_nb_joy)
      {
	FD_SET((this->_joysticks[i].first)->getFd(), &readfds);
	if ((this->_joysticks[i].first)->getFd() > max_fd)
	  max_fd = (this->_joysticks[i].first)->getFd();
      }
    i = -1;
    if (select(max_fd + 1, &readfds, NULL, NULL, &time) != -1)
      while (++i < this->_nb_joy)
	if (FD_ISSET((this->_joysticks[i].first)->getFd(), &readfds))
	  readFd(i);
  }

  void	InputJoystick::update(void)
  {
    int		i = -1;
    int		count = 0;
    std::string tmp = "";
    std::ostringstream oss;


    while (++i <= 4)
      {
	oss << i + 1;
	tmp = this->_way_joy + oss.str();
	oss.str("");
	if (access(tmp.c_str(), R_OK) == 0)
	    count++;
      }
    if (count != this->_nb_joy)
      {
	this->_joysticks.clear();
	this->initJoystick();
      }
  }

  void	InputJoystick::initJoystick(void)
  {
    std::string tmp = "";
    int		fd;
    std::ostringstream oss;
    int		nb = 0;
    int		id = 0;
    struct js_event jtmp;

    bzero(&jtmp, sizeof(struct js_event));
    std::map<int, std::pair<Joystick *, js_event> >::iterator it;

    if (!this->_joysticks.empty())
      for (it = this->_joysticks.begin(); it != this->_joysticks.end(); ++it)
	if ((it->second).first)
	  close(((it->second).first)->getFd());
    while (nb <= 4)
      {
	oss << nb + 1;
	tmp = this->_way_joy + oss.str();
	oss.str("");
	if ((fd = open(tmp.c_str(), O_RDONLY)) != -1)
	  this->_joysticks[id++] = std::pair<Joystick *, js_event>(new Joystick(fd), jtmp);
	nb++;
      }
    this->_nb_joy = this->_joysticks.size();
  }

  InputJoystick::Joystick::Joystick(int fd)
    : _fd(fd)
  {
    ioctl(this->_fd, JSIOCGAXES, &(this->_nb_axis));
    ioctl(this->_fd, JSIOCGBUTTONS, &(this->_nb_button));
  }

  InputJoystick::Joystick::~Joystick(){}

  int		InputJoystick::Joystick::getFd(void) const
  {
    return this->_fd;
  }
};

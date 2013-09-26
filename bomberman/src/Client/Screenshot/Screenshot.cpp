//
// Screenshot.cpp for /home/phalip_z/projet_tek2/Bomberman/screenshot/src/Screenshot.cpp in /home/phalip_z//projet_tek2/Bomberman/screenshot/inc
// 
// Made by phalip_z
// Login   <phalip_z@epitech.net>
// 
// Started on  Mon May 27 13:58:05 2013 phalip_z
// Last update Sun Jun  9 17:44:34 2013 alexis leprovost
//

#include	<GL/gl.h>
#include	<GL/glu.h>
#include	"FreeImage.h"

#include	"Client/Screenshot/Screenshot.hh"

namespace Client
{
  std::string const Screenshot::BMP = ".bmp";
  std::string const Screenshot::JPEG = ".jpeg";
  std::string const Screenshot::PNG = ".png";

  Screenshot::Screenshot(const std::string &type)
    : _rgb(3), _type(type)
  {
  }

  Screenshot::~Screenshot()
  {
  }

  bool	   Screenshot::captureScreen(const std::string &file_name, const std::string &link,
				     size_t width, size_t height,
				     size_t pos_x, size_t pos_y) const
  {
    std::string tmp;

    tmp = link + file_name + this->_type;
    if (_rgb * width * height == 0)
      return false;
    FreeImage_Initialise();
    BYTE *pxl = new BYTE[width * height * this->_rgb];
    glReadPixels(pos_x, pos_y, width, height, GL_RGB, GL_UNSIGNED_BYTE, pxl);
    FIBITMAP *img = FreeImage_ConvertFromRawBits(pxl, width,
						 height, this->_rgb * width, 24,
						 0x0000FF, 0xFF0000, 0x00FF00);
    if (this->_type == Screenshot::BMP)
      FreeImage_Save(FIF_BMP, img, tmp.c_str(), 0);
    else if (this->_type == Screenshot::PNG)
      FreeImage_Save(FIF_PNG, img, tmp.c_str(), 0);
    else
      FreeImage_Save(FIF_JPEG, img, tmp.c_str(), 0);
    FreeImage_Unload(img);
    delete [] pxl;
    return true;
  }

  void	Screenshot::setType(const std::string &type)
  {
    this->_type = type;
  }

};

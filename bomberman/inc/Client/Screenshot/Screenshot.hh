#ifndef __SCREENSHOT_H__
# define __SCREENSHOT_H__

#include	<iostream>

namespace Client
{
  class Screenshot
  {
    int			_rgb;
    std::string		_type;

  public:
    Screenshot(const std::string &type = JPEG);
    virtual ~Screenshot();
    bool        captureScreen(const std::string &file_name, const std::string &link,
				 size_t width, size_t height,
				 size_t pos_x = 0, size_t pos_y = 0) const;
    void       	setType(const std::string &type);

    static std::string const BMP;
    static std::string const JPEG;
    static std::string const PNG;
  };
}

#endif /* !__SCREENSHOT_H__ */

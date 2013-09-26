//
// AllegroLibrary.cpp for /home/vink/projet/cpp/Nibler-patel-ozouf/src/Library/Allegro/AllegroLibrary.cpp in /home/vink/projet/cpp/Nibler-patel-ozouf
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Mon Mar 18 17:54:58 2013 kevin platel
//

#include <map>
#include "AllegroLibrary.hh"

AllegroLibrary::AllegroLibrary()
{
  this->display = 0;
  std::cout << "Try to init allegro..." << std::endl;
  if (!al_init())
    {
      std::cerr << "Error : can't init display" << std::endl;
    }
  else
    {
      std::cout << "display init" << std::endl;
    }

  this->display = al_create_display(640, 480);
  if (!this->display)
    {
      std::cerr << "Error : can't create display" << std::endl;
    }
  else
    {
      std::cout << "display create" << std::endl;
    }

  al_clear_to_color(al_map_rgb(0,0,0));
}

AllegroLibrary::~AllegroLibrary()
{
  al_destroy_display(this->display);
}

void	AllegroLibrary::init(std::string const &texture_path, std::vector<std::string> const &texture)
{
  for (unsigned int i = 0; i < texture.size(); i++)
    {
      ALLEGRO_BITMAP *img = al_load_bitmap((texture_path + texture[i]).c_str());
      (this->aff)[texture[i]] = img;
    }
  std::cout << "Init finish." << std::endl;
}

void	AllegroLibrary::drawRect(std::pair<int,int> const &pos, std::pair<int,int> const &size, std::string const &texture, std::string const &str)
{
  std::cout << "draw..." << std::endl;
  if (this->aff[texture])
    al_draw_bitmap_region(this->aff[texture],0,0,size.first, size.second, pos.first,pos.second,0);
  else
    std::cout << "Is NULL" << std::endl;
}

void	AllegroLibrary::reload(std::string const &texture_path, std::vector<std::string> const &texture)
{
}

void		AllegroLibrary::updateEvent(std::stack<std::string> &e)
{
}

void		AllegroLibrary::update()
{
  std::cout << "Print..." << std::endl;
  al_flip_display();
}

void	AllegroLibrary::quit()
{
}

extern "C"
{
  ILibrary*	create_lib()
  {
    return new AllegroLibrary();
  }
}

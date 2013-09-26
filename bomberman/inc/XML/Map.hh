#ifndef __MAP_HH__
#define __MAP_HH__

#include <string>
#include <vector>

#include "GameObject.hh"

class Map
{
public:
  Map(const std::string &, int, const std::string &,
      const std::string &);
  Map(const std::string &, int, const std::string &,
      const std::string &, const std::string &,
      std::vector<std::string>, const std::string &);
  ~Map();

  std::string				getName() const;
  int					getId() const;
  void					setId(int);
  std::string				getSerialContent() const;
  std::string				getSerialPlayer_1() const;
  std::string				getSerialPlayer_2() const;
  std::vector<std::string>      	getIa() const;
  std::string				getScreen() const;

private:
  std::string				_name;
  int					_id;
  std::string				_serialContent;
  std::string				_serialPlayer_1;
  std::string				_serialPlayer_2;
  std::vector<std::string>    		_ia;
  std::string				_screen;
};

#endif

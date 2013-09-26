//
// ScoreBox.cpp for /home/phalip_z/bomberman/src/Client/Interface/ScoreBox.cpp in /home/phalip_z//bomberman/src/Client/Interface
// 
// Made by phalip_z
// Login   <phalip_z@epitech.net>
// 
// Started on  Fri Jun  7 21:14:04 2013 phalip_z
// Last update Tue Jun 11 09:49:02 2013 alexis leprovost
//

#include	<sstream>

#include	"Client/Interface/ScoreBox.hh"
#include	"XML/ConfXML.hh"
#include	"Client/Core.hh"

namespace Client
{
  ScoreBox::TextObject::TextObject(int score, const std::string &name, Score::Game type)
  {
    std::ostringstream oss;
    std::string		tmp;

    oss << score;
    this->textName.setText(name);
    if (type  == Score::LOCAL)
      tmp = "local";
    else
      tmp = "online";
    this->textType.setText(tmp);
    this->textScore.setText(oss.str());
  }

  ScoreBox::TextObject::~TextObject()
  {
  }

  void	ScoreBox::TextObject::initialize()
  {
    this->textName.initialize();
    this->textType.initialize();
    this->textScore.initialize();
  }

  void	ScoreBox::TextObject::update(Event* )
  {
  }

  void	ScoreBox::TextObject::draw()
  {
    this->textName.draw();
    this->textType.draw();
    this->textScore.draw();
  }

  void	ScoreBox::TextObject::unload()
  {
    this->textName.unload();
    this->textType.unload();
    this->textScore.unload();
  }

  void		ScoreBox::TextObject::setX(int x)
  {
    this->textName.setX(x / 1.9);
    this->textType.setX(textName.getX() + 200);
    this->textScore.setX(textType.getX() + 175);
  }

  void     	ScoreBox::TextObject::setY(int y, int mult)
  {
    this->textName.setY(-y + mult);
    this->textType.setY(-y + mult);
    this->textScore.setY(-y + mult);
  }

  void     	ScoreBox::TextObject::setZ(int z)
  {
    this->textName.setZ(z);
    this->textType.setZ(z);
    this->textScore.setZ(z);
  }

  void     	ScoreBox::TextObject::setPosition(int x, int y, int z, int mult)
  {
    this->textName.setX(x / 2.3);
    this->textType.setX(textName.getX() + 160);
    this->textScore.setX(textType.getX() + 160);
    this->textName.setY(-y + mult);
    this->textType.setY(-y + mult);
    this->textScore.setY(-y + mult);
    this->textName.setZ(z);
    this->textType.setZ(z);
    this->textScore.setZ(z);
  }

  void     	ScoreBox::TextObject::setWidth(size_t width)
  {
    this->textName.setWidth(width);
    this->textType.setWidth(width);
    this->textScore.setWidth(width);
  }

  void     	ScoreBox::TextObject::setHeight(size_t )
  {
  }

ScoreBox::ScoreBox(std::string const& name,
		   std::string const& background)
  : IWidgetObject(name), _background(background), _nbMax(10)
  {
    std::map<int, Score *>	tmp = Core::confXML.getScores();
    std::map<int, Score *>::iterator it = tmp.end();
    int	i;
    std::string		stmp = "";

    this->_background.setFilename(background);
    if (!tmp.empty())
      for (i = 0; i < 10 && it != tmp.begin(); ++i)
	{
	  --it;
	  this->_profileScore.push_back(TextObject(it->first, (it->second)->getName(),
	  					   (it->second)->getGame()));
	}
  }

  ScoreBox::~ScoreBox()
  {
  }

  void	ScoreBox::initialize()
  {
    std::list<TextObject >::iterator	it2;
    std::map<int, Score *>::iterator	it;
    std::map<int, Score *>		tmp = Core::confXML.getScores();

    this->_background.initialize();
    if (!tmp.empty())
      for (it = tmp.begin(), it2 = this->_profileScore.begin(); it != tmp.end(); ++it)
	{
	  (*it2).initialize();
	  ++it2;
	}
  }

  void	ScoreBox::update(Event*)
  {
  }

  void	ScoreBox::draw()
  {
    std::list<TextObject >::iterator	it;

    this->_background.draw();
    if (!this->_profileScore.empty())
	for (it = this->_profileScore.begin(); it != this->_profileScore.end(); ++it)
	  (*it).draw();
  }

  void	ScoreBox::unload()
  {
    std::list<TextObject >::iterator	it;

    this->_background.unload();
    if (!this->_profileScore.empty())
      for (it = this->_profileScore.begin(); it != this->_profileScore.end(); ++it)
	(*it).unload();
  }

  void		ScoreBox::setX(int x)
  {
    std::list<TextObject >::iterator	it;

    this->_background.setX(x);
    if (!this->_profileScore.empty())
      for (it = this->_profileScore.begin(); it != this->_profileScore.end(); ++it)
	(*it).setX(x);
  }

  void		ScoreBox::setY(int y)
  {
    std::list<TextObject >::iterator	it;
    int	i = 1;

    this->_background.setY(y);
    if (!this->_profileScore.empty())
      for (it = this->_profileScore.begin(); it != this->_profileScore.end(); ++it)
	{
	  (*it).setY(y, i);
	  i -= 50;
	}
  }

  void		ScoreBox::setZ(int z)
  {
    std::list<TextObject >::iterator	it;

    this->_background.setZ(z);
    if (!this->_profileScore.empty())
      for (it = this->_profileScore.begin(); it != this->_profileScore.end(); ++it)
	(*it).setZ(z);
 }

  void		ScoreBox::setPosition(int x, int y, int z)
  {
    std::list<TextObject >::iterator	it;
    int		i = 1;

    this->_background.setPosition(x, y, z);
    if (!this->_profileScore.empty())
      for (it = this->_profileScore.begin(); it != this->_profileScore.end(); ++it)
	{
	  (*it).setPosition(x, y, z, i);
	  i++;
	}
  }

  void		ScoreBox::setWidth(size_t width)
  {
    std::list<TextObject >::iterator	it;

    this->_background.setWidth(width);
    if (!this->_profileScore.empty())
      for (it = this->_profileScore.begin(); it != this->_profileScore.end(); ++it)
	(*it).setWidth(width);
  }

  void		ScoreBox::setHeight(size_t height)
  {
    this->_background.setHeight(height);
  }
};

#ifndef __SCOREBOX_H__
# define __SCOREBOX_H__

#include	<list>
#include	<string>

#include	"Client/Interface/Image.hh"
#include	"Client/Interface/IWidgetObject.hh"
#include	"Client/Interface/Widget.hh"
#include	"Client/Interface/Text.hh"
#include	"XML/Score.hh"

namespace Client
{
  class ScoreBox : public IWidgetObject
  {
  public:
    struct TextObject
    {
      Text	textName;
      Text	textType;
      Text	textScore;

      TextObject(int score, const std::string &name, Score::Game type);
      virtual ~TextObject();
      void	initialize();
      void	update(Event* event);
      void	draw();
      void	unload();

      void	setX(int x);
      void     	setY(int y, int mult);
      void     	setZ(int z);
      void     	setPosition(int x, int y, int z, int mult);
      void     	setWidth(size_t width);
      void     	setHeight(size_t height);
    };

  private:
    Image			_background;
    std::list<TextObject >	_profileScore;
    int				_nbMax;

  public:
    ScoreBox(std::string const& name, std::string const& background);
    virtual ~ScoreBox();

    virtual void	initialize();
    virtual void	update(Event* event);
    virtual void	draw();
    virtual void	unload();

    void		setX(int x);
    void		setY(int y);
    void		setZ(int z);
    void		setPosition(int x, int y, int z);
    void		setWidth(size_t width);
    void		setHeight(size_t height);
  };
}

#endif /* !__SCOREBOX_H__ */

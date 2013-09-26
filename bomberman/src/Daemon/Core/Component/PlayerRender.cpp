//
// PlayerRender.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev
//
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
//
// Started on  Wed May 29 11:43:25 2013 alexis leprovost
// Last update Tue Jun 11 09:44:53 2013 alexis leprovost
//

#include "Life.hh"
#include "Position.hh"
#include "Color.hh"
#include "PlayerRender.hh"
#include "GameObject.hh"
#include "Characteristic.hh"
#include "Position.hh"
#include "Characteristic.hh"
#include "Client/Core.hh"

#define ABS(x)	((x) > 0 ? (x) : ((x) * -1))

namespace Daemon
{
  std::string const	PlayerRender::T_POSE = "t-pose";
  std::string const	PlayerRender::TEST = "test";
  std::string const	PlayerRender::IDLE = "idle";
  std::string const	PlayerRender::RUN = "run";
  std::string const	PlayerRender::THROW = "throw";
  std::string const	PlayerRender::PSY = "psy";
  std::string const	PlayerRender::NAME = "playerRender";

  PlayerRender::PlayerRender(GameObject* owner, std::string const& name, float size)
    : Render(owner, name, size),
      _image1("assets/clips/menu/default.png", Color(1.0f, 1.0f, 1.0f)),
      _image2("assets/clips/menu/life.png", Color(0.0f, 1.0f, 0.0f))
  {
    this->setName(PlayerRender::NAME);
    this->_isInit = false;
    if (this->_owner)
      {
	this->_owner->addEvent("has_throw_bomb", new Action<PlayerRender>(*this, &PlayerRender::eventThrowBomb));
	this->_owner->addEvent("has_move", new Action<PlayerRender>(*this, &PlayerRender::eventMove));
	this->_isInit = true;
      }
    this->_init = false;
    this->_manual[PlayerRender::T_POSE] = std::pair<bool, float>(false, 0.0f);
    this->_manual[PlayerRender::TEST] = std::pair<bool, float>(false, 1.0f);
    this->_manual[PlayerRender::IDLE] = std::pair<bool, float>(false, 10.0f);
    this->_manual[PlayerRender::RUN] = std::pair<bool, float>(true, 2.5f);
    this->_manual[PlayerRender::THROW] = std::pair<bool, float>(true, 5.0f);
    this->_manual[PlayerRender::PSY] = std::pair<bool, float>(false, 2.5f);
  }

  PlayerRender::~PlayerRender()
  {
    if (this->_owner && this->_isInit)
      {
	this->_owner->removeEvent("hasThrowBomb");
	this->_owner->removeEvent("hasMove");
      }
  }

  void	PlayerRender::initialize()
  {
    this->_clock.reset();
    this->_clock2.reset();
    this->_image1.initialize();
    this->_image2.initialize();
    this->_image1.setWidth(100);
    this->_image2.setWidth(100);
    this->_image1.setHeight(20);
    this->_image2.setHeight(20);
    if (!this->_init && this->_modelName != "")
      {
	this->_init = true;
	this->_model = gdl::Model::load(this->_modelName);
	this->_update = true;
      }
    gdl::Model::cut_animation(this->_model, "Take 001", 0, 1, PlayerRender::T_POSE);
    gdl::Model::cut_animation(this->_model, "Take 001", 4, 59, PlayerRender::TEST);
    gdl::Model::cut_animation(this->_model, "Take 001", 66, 187, PlayerRender::IDLE);
    gdl::Model::cut_animation(this->_model, "Take 001",  202, 214, PlayerRender::RUN);
    gdl::Model::cut_animation(this->_model, "Take 001",  232, 242, PlayerRender::THROW);
    gdl::Model::cut_animation(this->_model, "Take 001",  253, 538, PlayerRender::PSY);
    if (this->_owner && !this->_isInit)
      {
	this->_owner->addEvent("hasThrowBomb", new Action<PlayerRender>(*this, &PlayerRender::eventThrowBomb));
	this->_owner->addEvent("hasMove", new Action<PlayerRender>(*this, &PlayerRender::eventMove));
	this->_isInit = true;
      }
  }

  void	PlayerRender::update()
  {
    if (this->_init)
      {
	if (!this->_clock.isRunning() || this->_clock.isTimeOut(0.25f))
	  {
	    if (this->_anim == PlayerRender::RUN)
	      this->_model.stop_animation(this->_anim);
	    if (this->_model.anim_is_ended(this->_anim))
	      this->play((this->_anim = PlayerRender::IDLE));
	  }
	if (this->_update)
	  {
	    if (!this->_anim.empty() && this->_model.anim_is_ended(this->_anim))
	      this->_model.play(this->_anim);
	    this->_model.update(*Client::Core::gameClock);
	    this->_update = false;
	  }
	if (!this->_clock2.isRunning() || this->_clock2.isTimeOut(1.0f / 60.0f))
	  {
	    this->_model.update(*Client::Core::gameClock);
	    this->_clock2.reset();
	    this->_clock2.start();
	  }
	if (this->_owner)
	  {
	    Daemon::Life* life = dynamic_cast<Daemon::Life*>(this->_owner->getComponent(Daemon::Life::NAME));
	    Daemon::Position* pos = dynamic_cast<Daemon::Position*>(this->_owner->getComponent(Daemon::Position::NAME));
	    this->_image2.setWidth((life->getLife() * 100) / life->getMaxLife());
	    this->_image1.setPosition(pos->getX(), pos->getZ() + 1000, pos->getY());
	    this->_image2.setPosition(pos->getX(), pos->getZ() + 1000, pos->getY());
	  }
      }
  }

  float			PlayerRender::_getSpeed()
  {
    float		speed;
    Manual::iterator	it = this->_manual.find(this->_anim);

    if (it == this->_manual.end())
      return (1.0f);
    speed = (*it).second.second;
    if (!(*it).second.first || !this->_owner)
      return (speed);
    Daemon::Characteristic* characteristic = dynamic_cast<Daemon::Characteristic*>(this->_owner->getComponent(Daemon::Characteristic::NAME));
    speed *= characteristic->getSpeed();
    return (speed);
  }

  void			PlayerRender::draw()
  {
    if (this->_init && this->_owner)
      {
	Position*	position = dynamic_cast<Position*>(this->_owner->getComponent(Position::NAME));
	if (position)
	  {
	    glPushMatrix();
	    glLoadIdentity();
	    glTranslatef(position->getX(), position->getZ(), position->getY());
	    float  angle = atan(ABS(position->getDy()) / ABS(position->getDx()));
	    angle = (angle * 180.0f) / M_PI;
	    if (position->getDy() > 0 && position->getDx() > 0)
	      angle = 360 - angle;
	    else if (position->getDy() < 0 && position->getDx() < 0)
	      angle = 180.0f - angle;
	    else if (position->getDy() > 0 && position->getDx() < 0)
	      angle += 180.0;
	    else
	      angle = angle;
	    angle = static_cast<int>(angle + 90) % 360;
	    glRotatef(angle, 0.0f, 1.0f, 0.0f);
	    glScalef(this->_size, this->_size, this->_size);
	    if (!this->_anim.empty())
	      this->_model.set_anim_speed(this->_anim, this->_getSpeed());
	    this->_model.draw();
	    glPopMatrix();
	  }
	this->_update = true;
	this->_image1.draw();
	this->_image2.draw();
      }
  }

  PlayerRender*		PlayerRender::unserialize(std::stringstream &s, GameObject *owner)
  {
    std::stringstream ss;
    ss << this->unPack(s);

    return new PlayerRender(owner, this->getData(ss), str_to_double(this->getData(ss)));
  }

  PlayerRender*		PlayerRender::clone(Daemon::GameObject* owner) const
  {
    return new PlayerRender(owner, this->getModelName(), this->getSize());
  }

  void		        PlayerRender::eventThrowBomb(Trame&)
  {
    if (this->_init)
      {
    	if (!this->_anim.empty() && this->_anim != PlayerRender::THROW)
    	  this->stop(this->_anim);
    	this->play((this->_anim = PlayerRender::THROW));
    	this->_clock.reset();
    	this->_clock.start();
      }
  }

  void		        PlayerRender::eventMove(Trame&)
  {
    if (this->_init && this->_anim != PlayerRender::THROW)
      {
    	if (!this->_anim.empty() && this->_anim != PlayerRender::RUN)
    	  this->stop(this->_anim);
    	this->play((this->_anim = PlayerRender::RUN));
    	this->_clock.reset();
    	this->_clock.start();
      }
  }

  void			PlayerRender::play(std::string const& anim)
  {
    if (this->_init && anim != this->_anim)
      {
    	this->_model.play(anim);
    	this->_anim = anim;
      }
  }

  void			PlayerRender::stop(std::string const& anim)
  {
    if (this->_init)
      {
	this->_model.stop_animation(anim);
	this->_anim = "";
      }
  }
}

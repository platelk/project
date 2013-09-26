//
// Trigger.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/dev/src/Client/Interface
//
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
//
// Started on  Wed May 15 15:56:26 2013 alexis leprovost
//

#include <iostream>
#include <sys/types.h>

#include "utils.hh"
#include "Position.hh"
#include "Render.hh"
#include "Player.hh"
#include "GameObject.hh"
#include "Trame.hh"
#include "Timer.hh"
#include "Factory.hh"
#include "Falco.hh"
#include "Position.hh"
#include "Client/Event/KeyboardEvent.hh"
#include "Client/Controller/Input.hh"
#include "Client/Trigger/Trigger.hh"
#include "Client/Interface/Stage.hh"
#include "Client/Event/CameraEvent.hh"
#include "Client/Event/UpdateEvent.hh"
#include "Client/Event/MouseEvent.hh"
#include "Client/Event/JoystickEvent.hh"
#include "Client/Interface/Interface.hh"
#include "Client/Interface/TextBox.hh"
#include "Client/Interface/KeyBox.hh"
#include "Client/Interface/Camera.hh"
#include "Client/Interface/Button.hh"
#include "Client/Interface/ButtonManager.hh"
#include "Client/Interface/CharacterBox.hh"
#include "Client/Interface/ProfileBox.hh"
#include "Client/Interface/SoundBox.hh"
#include "Client/Interface/LogicTree.hh"
#include "Client/Network/ClientNetwork.hh"
#include "Client/Core.hh"

namespace Client
{
  void	Trigger::dispatch(Widget* widget, Event* event)
  {
    UpdateEvent*	updateEvent = dynamic_cast<UpdateEvent*>(event);

    if (updateEvent && widget)
      {
	size_t const	n = widget->getNbWidgetObject();
	widget->dispatchEvent(updateEvent->getEvent());
	for (size_t i = 0; i < n; ++i)
	  widget->getWidgetObjectAt(i)->dispatchEvent(updateEvent->getEvent());
      }
  }

  void	Trigger::initialize(Widget* widget, Event*)
  {
    if (widget)
      {
	size_t const	n = widget->getNbWidgetObject();
	for (size_t i = 0; i < n; ++i)
	  widget->getWidgetObjectAt(i)->initialize();
      }
  }

  void	Trigger::draw(Widget* widget, Event*)
  {
    size_t const	n = widget->getNbWidgetObject();

    for (size_t i = 0; i < n; ++i)
      widget->getWidgetObjectAt(i)->draw();
  }

  void	Trigger::dynamic(Widget* widget, Event*)
  {
    if (widget && widget->getName() == Interface::WELCOME)
      {
	Button*	new_profile = dynamic_cast<Button*>(widget->getWidgetObjectAt(2));
	Button* load_profile = dynamic_cast<Button*>(widget->getWidgetObjectAt(3));
	Button* score = dynamic_cast<Button*>(widget->getWidgetObjectAt(4));
	if (!Core::confXML.getProfiles().empty())
	  {
	    new_profile->setLink(ButtonManager::Top, 4);
	    new_profile->setLink(ButtonManager::Bottom, 1);
	    load_profile->show();
	    score->setLink(ButtonManager::Top, 1);
	  }
	else
	  {
	    new_profile->setLink(ButtonManager::Top, 4);
	    new_profile->setLink(ButtonManager::Bottom, 2);
	    load_profile->hide();
	    score->setLink(ButtonManager::Top, 0);
	  }
      }
    if (widget && widget->getName() == Interface::NEW_PROFILE)
      {
	TextBox* name = dynamic_cast<TextBox*>(widget->getWidgetObjectAt(2));
	Button* ok = dynamic_cast<Button*>(widget->getWidgetObjectAt(3));
	Button* back = dynamic_cast<Button*>(widget->getWidgetObjectAt(4));
	if (name->getText().empty())
	  {
	    name->setLink(ButtonManager::Top, 2);
	    name->setLink(ButtonManager::Bottom, 2);
	    ok->hide();
	    back->setLink(ButtonManager::Top, 0);
	    back->setLink(ButtonManager::Left, -1);
	    back->setLink(ButtonManager::Bottom, 0);
	  }
	else
	  {
	    name->setLink(ButtonManager::Top, -1);
	    name->setLink(ButtonManager::Bottom, 1);
	    ok->show();
	    back->setLink(ButtonManager::Top, 0);
	    back->setLink(ButtonManager::Left, 1);
	    back->setLink(ButtonManager::Bottom, -1);
	  }
      }
    if (widget && widget->getName() == Interface::PLAY)
      {
	Button* custom_game = dynamic_cast<Button*>(widget->getWidgetObjectAt(5));
	Button* load_game = dynamic_cast<Button*>(widget->getWidgetObjectAt(6));
	Button* create_game = dynamic_cast<Button*>(widget->getWidgetObjectAt(7));
	custom_game->setLink(ButtonManager::Bottom, 3);
	load_game->hide();
	create_game->setLink(ButtonManager::Top, 1);
      }
  }

  void	Trigger::save(Widget* widget, Event*)
  {
    if (widget && widget->getParent() &&
	widget->getParent()->getName() == Interface::NEW_PROFILE)
      {
	TextBox* name = dynamic_cast<TextBox*>(widget->getParent()->getWidgetObjectAt(2));
	Core::profile = new Profile(name->getText(), Core::confXML.getParsLevel(), Core::confXML.getParsPersos(), Core::confXML.getAchievments());
	Core::confXML.addProfile(Core::profile);
      }
    if (widget && widget->getParent() &&
	widget->getParent()->getName() == Interface::LOAD_PROFILE)
      {
	ProfileBox* profileBox = dynamic_cast<ProfileBox*>(widget->getParent()->getWidgetObjectAt(2));
	Core::profile = profileBox->getProfile();
	if (!Core::profile)
	  {
	    Event	event(Event::STATE, Interface::WELCOME);
	    Stage::getInstance()->dispatchEvent(&event);
	  }
      }
  }

  void	Trigger::update(Widget* widget, Event* event)
  {
    UpdateEvent* updateEvent = dynamic_cast<UpdateEvent*>(event);

    if (updateEvent && widget)
      {
	size_t const	n = widget->getNbWidgetObject();
	for (size_t i = 0; i < n; ++i)
	  widget->getWidgetObjectAt(i)->update(updateEvent->getEvent());
      }
  }

  void	Trigger::state(Widget*, Event* event)
  {
    static Timer	clock;

    if (!clock.isRunning() || clock.isTimeOut(0.1f))
      {
	Widget*	widget = Stage::getInstance()->getChild(event->getName());
	if (widget)
	  {
	    Event	eventInitialize(Event::INITIALIZE, Event::INITIALIZE);
	    Stage::getInstance()->setState(widget);
	    widget->dispatchEvent(&eventInitialize);
	  }
	clock.reset();
	clock.start();
      }
  }

  void	Trigger::quit(Widget*, Event* event)
  {
    KeyboardEvent*	keyboardEvent = dynamic_cast<KeyboardEvent*>(event);

    if (keyboardEvent)
      {
	if (keyboardEvent->getKeyCode() == Input::Keys::Escape)
	  Core::on = false;
      }
    else
      Core::on = false;
  }

  void	Trigger::target(Widget* widget, Event*)
  {
    Button*		button = dynamic_cast<Button*>(widget);
    Widget*		state = Stage::getInstance()->getState();
    static Timer	clock;

    if (button && state && (!clock.isRunning() || clock.isTimeOut(0.25f)))
      {
	Event	eventState(Event::STATE, button->getTarget());
	Stage::getInstance()->dispatchEvent(&eventState);
	clock.reset();
	clock.start();
      }
  }

  void	Trigger::settings(Widget* widget, Event* event)
  {
    Profile* profile = Core::profile;

    if (widget && profile && event && event->getType() == Event::INITIALIZE)
      {
	KeyBox* key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(3));
	key->lock(true);
	key->addChar(static_cast<Input::Keys::Key>(profile->getKey(Profile::UP, Profile::ONE)));
	key->lock(false);
	key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(4));
	key->lock(true);
	key->addChar(static_cast<Input::Keys::Key>(profile->getKey(Profile::DOWN, Profile::ONE)));
	key->lock(false);
	key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(5));
	key->lock(true);
	key->addChar(static_cast<Input::Keys::Key>(profile->getKey(Profile::LEFT, Profile::ONE)));
	key->lock(false);
	key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(6));
	key->lock(true);
	key->addChar(static_cast<Input::Keys::Key>(profile->getKey(Profile::RIGHT, Profile::ONE)));
	key->lock(false);
	key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(7));
	key->lock(true);
	key->addChar(static_cast<Input::Keys::Key>(profile->getKey(Profile::THROW, Profile::ONE)));
	key->lock(false);
	key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(8));
	key->lock(true);
	key->addChar(static_cast<Input::Keys::Key>(profile->getKey(Profile::SPELL, Profile::ONE)));
	key->lock(false);
	key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(9));
	key->lock(true);
	key->addChar(static_cast<Input::Keys::Key>(profile->getKey(Profile::UP, Profile::TWO)));
	key->lock(false);
	key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(10));
	key->lock(true);
	key->addChar(static_cast<Input::Keys::Key>(profile->getKey(Profile::DOWN, Profile::TWO)));
	key->lock(false);
	key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(11));
	key->lock(true);
	key->addChar(static_cast<Input::Keys::Key>(profile->getKey(Profile::LEFT, Profile::TWO)));
	key->lock(false);
	key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(12));
	key->lock(true);
	key->addChar(static_cast<Input::Keys::Key>(profile->getKey(Profile::RIGHT, Profile::TWO)));
	key->lock(false);
	key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(13));
	key->lock(true);
	key->addChar(static_cast<Input::Keys::Key>(profile->getKey(Profile::THROW, Profile::TWO)));
	key->lock(false);
	key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(14));
	key->lock(true);
	key->addChar(static_cast<Input::Keys::Key>(profile->getKey(Profile::SPELL, Profile::TWO)));
	key->lock(false);
	SoundBox*	sound = dynamic_cast<SoundBox*>(widget->getWidgetObjectAt(15));
	sound->setPowerBar(profile->getEffect());
	sound = dynamic_cast<SoundBox*>(widget->getWidgetObjectAt(16));
	sound->setPowerBar(profile->getAmbiance());
      }
    if (widget && widget->getParent() && profile && event && event->getType() == Event::STATE)
      {
	widget = widget->getParent();
	KeyBox* key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(3));
	key->lock(true);
	profile->setKey(static_cast<Input::Keys::Key>(key->getLastKey()), Profile::UP, Profile::ONE);
	key->lock(false);
	key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(4));
	key->lock(true);
	profile->setKey(static_cast<Input::Keys::Key>(key->getLastKey()), Profile::DOWN, Profile::ONE);
	key->lock(false);
	key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(5));
	key->lock(true);
	profile->setKey(static_cast<Input::Keys::Key>(key->getLastKey()), Profile::LEFT, Profile::ONE);
	key->lock(false);
	key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(6));
	key->lock(true);
	profile->setKey(static_cast<Input::Keys::Key>(key->getLastKey()), Profile::RIGHT, Profile::ONE);
	key->lock(false);
	key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(7));
	key->lock(true);
	profile->setKey(static_cast<Input::Keys::Key>(key->getLastKey()), Profile::THROW, Profile::ONE);
	key->lock(false);
	key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(8));
	key->lock(true);
	profile->setKey(static_cast<Input::Keys::Key>(key->getLastKey()), Profile::SPELL, Profile::ONE);
	key->lock(false);
	key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(9));
	key->lock(true);
	profile->setKey(static_cast<Input::Keys::Key>(key->getLastKey()), Profile::UP, Profile::TWO);
	key->lock(false);
	key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(10));
	key->lock(true);
	profile->setKey(static_cast<Input::Keys::Key>(key->getLastKey()), Profile::DOWN, Profile::TWO);
	key->lock(false);
	key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(11));
	key->lock(true);
	profile->setKey(static_cast<Input::Keys::Key>(key->getLastKey()), Profile::LEFT, Profile::TWO);
	key->lock(false);
	key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(12));
	key->lock(true);
	profile->setKey(static_cast<Input::Keys::Key>(key->getLastKey()), Profile::RIGHT, Profile::TWO);
	key->lock(false);
	key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(13));
	key->lock(true);
	profile->setKey(static_cast<Input::Keys::Key>(key->getLastKey()), Profile::THROW, Profile::TWO);
	key->lock(false);
	key = dynamic_cast<KeyBox*>(widget->getWidgetObjectAt(14));
	key->lock(true);
	profile->setKey(static_cast<Input::Keys::Key>(key->getLastKey()), Profile::SPELL, Profile::TWO);
	key->lock(false);
	SoundBox*	sound = dynamic_cast<SoundBox*>(widget->getWidgetObjectAt(15));
	profile->setEffect(sound->getPowerBar());
	sound = dynamic_cast<SoundBox*>(widget->getWidgetObjectAt(16));
	profile->setAmbiance(sound->getPowerBar());
	if (profile != 0)
	  {
	    Client::Core::sounds.setAmbianceVolume((static_cast<float>(profile->getAmbiance()) \
						    / 100.0 ), Sound::AMBIANCE);
	    Client::Core::sounds.setAmbianceVolume((static_cast<float>(profile->getEffect()) \
						    / 100.0 ), Sound::EFFECT);
	  }
      }
  }

  void	Trigger::random(Widget*, Event*)
  {
    static bool		state = false;
    static Timer	clock;

    if (!clock.isRunning() && !Core::network->isConnect())
      {
	state = Core::network->connect(Core::ip, Core::port);
	clock.start();
      }
    else
      {
	if (!state)
	  {
	    Event	eventState(Event::STATE, Interface::PLAY);
	    Core::network->disconnect();
	    Stage::getInstance()->dispatchEvent(&eventState);
	    clock.reset();
	  }
	else
	  {
	    Widget*	widget = Stage::getInstance()->getChild(Interface::GAME);
	    LogicTree*	logicTree = dynamic_cast<LogicTree*>(widget->getWidgetObject(Interface::LOGIC_TREE));
	    if (logicTree->getIdPlayer() != -1 && clock.isTimeOut(0.25f))
	      {
		Event		eventState(Event::STATE, Interface::LOAD_GAME);
		Daemon::Trame	trame(logicTree->getIdPlayer(), "game_start", "player", "", "", "");
		ClientNetwork::sendq->push(trame.toString());
		Daemon::GameObject*	player = GameObjectFactory::factory.create(CharacterBox::getRandName());
		trame.setEvent("select_player");
		trame.setArgument(player->serialize());
		ClientNetwork::sendq->push(trame.toString());
		delete player;
		for (size_t i = (rand() % (9 - 4) + 4); i > 0; --i)
		  {
		    Daemon::GameObject* player = GameObjectFactory::factory.create(CharacterBox::getRandName());
		    Thread<const char *, int>* a = new Thread<const char *, int>(&system, std::string(std::string(std::string("./src/IA/main.py 127.0.0.1 ") + int_to_str(Core::port) + std::string(" '")) + player->serialize() + std::string("'")).c_str());
		    a->run();
		    Core::bot.push_back(a);
		    sleep(1);
		  }
		trame.setEvent("game_run");
		trame.setArgument("");
		if (Core::ip == "127.0.0.1")
		  ClientNetwork::sendq->push(trame.toString());
		Stage::getInstance()->dispatchEvent(&eventState);
		clock.reset();
		Core::type = Score::Game::LOCAL;
	      }
	  }
      }
  }

  void	Trigger::connect(Widget*, Event*)
  {
    static Timer	clock;
    static bool		state = false;

    if (!clock.isRunning() && !Core::network->isConnect())
      {
	state = Core::network->connect(Core::ip, Core::port);
	clock.start();
      }
    else
      {
	if (!state)
	  {
	    Event	eventState(Event::STATE, Interface::PLAY);
	    Core::network->disconnect();
	    Stage::getInstance()->dispatchEvent(&eventState);
	    clock.reset();
	  }
	else
	  {
	    Widget*		widget = Stage::getInstance()->getChild(Interface::GAME);
	    LogicTree*	logicTree = dynamic_cast<LogicTree*>(widget->getWidgetObject(Interface::LOGIC_TREE));
	    if (logicTree->getIdPlayer() != -1 && clock.isTimeOut(0.25f))
	      {
		Daemon::Trame	trame(logicTree->getIdPlayer(), "game_start", "player", "", "", "");
		ClientNetwork::sendq->push(trame.toString());
		Event	eventState(Event::STATE, Interface::SELECTION);
		Stage::getInstance()->dispatchEvent(&eventState);
		clock.reset();
		state = false;
	      }
	  }
      }
  }

  void	Trigger::select(Widget* widget, Event*)
  {
    CharacterBox*	characterBox = dynamic_cast<CharacterBox*>(widget->getParent()->getWidgetObject(Interface::CHARACTER_BOX));
    LogicTree*		logicTree = dynamic_cast<LogicTree*>(Stage::getInstance()->getChild(Interface::GAME)->getWidgetObject(Interface::LOGIC_TREE));
    Daemon::GameObject*	player = GameObjectFactory::factory.create(characterBox->getPlayerName(0));
    Daemon::Trame	trame(logicTree->getIdPlayer(), "select_player", "player", "", "", player->serialize());
    ClientNetwork::sendq->push(trame.toString());
    delete player;
    trame.setEvent("game_run");
    trame.setArgument("");
    Core::type = Score::Game::ONLINE;
    if (Core::ip == "127.0.0.1")
      ClientNetwork::sendq->push(trame.toString());
    Event		eventState(Event::STATE, Interface::LOAD_GAME);
    Stage::getInstance()->dispatchEvent(&eventState);
  }

  void	Trigger::route(Widget*, Event* event)
  {
    Widget*	widget = Stage::getInstance()->getChild(Interface::GAME);
    UpdateEvent	updateEvent(UpdateEvent::OBJECT, event);

    if (widget)
      widget->dispatchEvent(&updateEvent, true);
  }

  void	Trigger::synchronisation(Widget*, Event*)
  {
    LogicTree*				logicTree = dynamic_cast<LogicTree*>(Stage::getInstance()->getChild(Interface::GAME)->getWidgetObject(Interface::LOGIC_TREE));
    std::deque<Daemon::GameObject*>&	gameObject = logicTree->getGameObject();
    Daemon::Render*			render;

    for (size_t i = 0; i < gameObject.size(); ++i)
      {
	render = dynamic_cast<Daemon::Render*>(gameObject[i]->getComponentFamily(Daemon::Render::NAME));
	if (render)
	  render->initialize();
      }
    Daemon::Trame	trame(logicTree->getIdPlayer(), "connected", "player", "", int_to_str(logicTree->getIdPlayer()), "");
    ClientNetwork::sendq->push(trame.toString());
  }

  void	Trigger::start(Widget*, Event*)
  {
    Widget*		state = Stage::getInstance()->getState();

    if (state)
      {
	Event		eventState(Event::STATE, Interface::GAME);
	Event		eventInitialize(Event::INITIALIZE, Event::INITIALIZE);
	Stage::getInstance()->dispatchEvent(&eventInitialize);
	Stage::getInstance()->dispatchEvent(&eventState);
	if (Core::profile)
	  Client::Core::sounds.setAmbianceVolume((static_cast<float>(Core::profile->getAmbiance()) \
						  / 100.0 ), Sound::AMBIANCE);
	  Client::Core::sounds.setAmbianceVolume((static_cast<float>(Core::profile->getEffect()) \
						  / 100.0 ), Sound::EFFECT);
      }
  }

  void	Trigger::menu(Widget*, Event*)
  {
    Camera*	camera = dynamic_cast<Camera*>(Stage::getInstance()->getWidgetObject(Interface::CAMERA));

    if (camera)
      {
	camera->setEye(0.0f, 0.0f, 500.0f);
	camera->setCenter(0.0f, 0.0f, 0.0f);
	camera->setFov(100);
      }
    Stage::getInstance()->setFrame(60);
  }

  void	Trigger::game(Widget* widget, Event*)
  {
    Camera*	camera = dynamic_cast<Camera*>(Stage::getInstance()->getWidgetObject(Interface::CAMERA));
    if (camera && widget)
      {
	LogicTree*	logicTree = dynamic_cast<LogicTree*>(widget->getWidgetObject(Interface::LOGIC_TREE));
	if (logicTree)
	  {
	    Daemon::GameObject*	player = logicTree->getPlayer();
	    if (player)
	      {
		Daemon::Position*	position = dynamic_cast<Daemon::Position*>(player->getComponent(Daemon::Position::NAME));
		if (position)
		  {
		    camera->setEye(position->getX(), position->getZ() + 5000.0f, position->getY() + 3000.0f);
		    camera->setCenter(position->getX(), position->getZ(), position->getY());
		    camera->setFov(40);
		  }
	      }
	  }
      }
    Stage::getInstance()->setFrame(180);
  }

  void	Trigger::soundGame(Widget*, Event*)
  {
    (Core::sounds.getSound("Welcome"))->stop();
    (Core::sounds.getSound("game"))->play();
  }

  void	Trigger::end(Widget* widget, Event*)
  {
    if (widget)
      {
	LogicTree* logicTree = dynamic_cast<LogicTree*>(widget->getWidgetObject(Interface::LOGIC_TREE));
	logicTree->clear();
	if (Core::profile)
	  {
	    int a = rand() % (1000 - 50) + 50;
	    Core::profile->addXp(a);
	    Core::profile->addGamesPlayed(1);
	    Core::profile->addPlayersKilled(rand() % (10 - 1) + 1);
	    Core::profile->addDamages(rand() % (500 - 100) + 100);
	    Core::confXML.addScore(new Score(Core::profile->getName(), Core::profile->getId(), a, Core::type));
	  }
	Event	event(Event::STATE, Interface::END);
	Stage::getInstance()->dispatchEvent(&event);
	Core::network->disconnect();
	(Core::sounds.getSound("game"))->stop();
	(Core::sounds.getSound("Welcome"))->play();
      }
  }

  void	Trigger::disconnect(Widget*, Event*)
  {
    Core::network->disconnect();
  }

  void	Trigger::escape(Widget* widget, Event* event)
  {
    KeyboardEvent* keyboardEvent = dynamic_cast<KeyboardEvent*>(event);
    JoystickEvent* joystickEvent = dynamic_cast<JoystickEvent*>(event);

    if (widget)
      {
	if ((keyboardEvent && keyboardEvent->getKeyCode() == Input::Keys::Escape) ||
	    (joystickEvent && joystickEvent->getButton() == Input::JoystickButton::START))
	  widget->show();
      }
  }
}

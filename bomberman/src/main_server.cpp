//
// main_server.cpp for bomberman in /home/leprov_a//project/tek2/bomberman/bomberman/src
//
// Made by alexis leprovost
// Login   <leprov_a@epitech.net>
//
// Started on  Sun Jun  9 15:39:11 2013 alexis leprovost
// Last update Tue Jun 11 02:24:52 2013 kevin platel
//

#include <iostream>
#include <cstdlib>

// Characters
#include "GameObject.hh"
#include "Player.hh"
#include "Mario.hh"
#include "Pit.hh"
#include "Sonic.hh"
#include "Shrek.hh"
#include "SacBoy.hh"
#include "Gohan.hh"
#include "Darunia.hh"
#include "Peach.hh"
#include "Link.hh"
#include "Falco.hh"
#include "Kratos.hh"
#include "Naruto.hh"
#include "Lucario.hh"
#include "Superman.hh"
#include "Megaman.hh"

// Decors
#include "Decor.hh"
#include "WoodBox.hh"
#include "BlastBox.hh"
#include "BarrelWood.hh"
#include "Palm.hh"
#include "SandGround.hh"
#include "WallRockTall.hh"
#include "DispersalEffect.hh"

// Bombs
#include "Bomb.hh"

// Components
#include "Ground.hh"
#include "Life.hh"
#include "Explose.hh"
#include "Position.hh"
#include "Move.hh"
#include "ThrowBomb.hh"
#include "Colider.hh"
#include "NewPlayer.hh"
#include "Network.hh"
#include "Render.hh"
#include "Game.hh"
#include "Store.hh"
#include "Mario.hh"
#include "Kratos.hh"
#include "SacBoy.hh"
#include "Characteristic.hh"
#include "PlayerRender.hh"
#include "DispersalRender.hh"
#include "Update.hh"
#include "Bonus.hh"
#include "BonusSpawn.hh"

#include "Client/Core.hh"
#include "utils.hh"
#include "Factory.hh"
#include "Core.hh"
#include "Tools/MapGenerator.hh"

static void	init()
{
  // Characters
  GameObjectFactory::factory.learn(Daemon::GameObject::NAME, new Daemon::GameObject(Daemon::GameObject::NAME, 0));
  GameObjectFactory::factory.learn(Player::NAME, new Player(0));
  GameObjectFactory::factory.learn(Mario::NAME, new Mario(0));
  GameObjectFactory::factory.learn(Pit::NAME, new Pit(0));
  GameObjectFactory::factory.learn(Sonic::NAME, new Sonic(0));
  GameObjectFactory::factory.learn(Shrek::NAME, new Shrek(0));
  GameObjectFactory::factory.learn(SacBoy::NAME, new SacBoy(0));
  GameObjectFactory::factory.learn(Gohan::NAME, new Gohan(0));
  GameObjectFactory::factory.learn(Darunia::NAME, new Darunia(0));
  GameObjectFactory::factory.learn(Peach::NAME, new Peach(0));
  GameObjectFactory::factory.learn(Link::NAME, new Link(0));
  GameObjectFactory::factory.learn(Falco::NAME, new Falco(0));
  GameObjectFactory::factory.learn(Kratos::NAME, new Kratos(0));
  GameObjectFactory::factory.learn(Naruto::NAME, new Naruto(0));
  GameObjectFactory::factory.learn(Lucario::NAME, new Lucario(0));
  GameObjectFactory::factory.learn(Superman::NAME, new Superman(0));
  GameObjectFactory::factory.learn(Megaman::NAME, new Megaman(0));

  // Decors
  GameObjectFactory::factory.learn(Decor::NAME, new Decor(0));
  GameObjectFactory::factory.learn(WoodBox::NAME, new WoodBox(0));
  GameObjectFactory::factory.learn(Palm::NAME, new Palm(0));
  GameObjectFactory::factory.learn(BlastBox::NAME, new BlastBox(0));
  GameObjectFactory::factory.learn(BarrelWood::NAME, new BarrelWood(0));
  GameObjectFactory::factory.learn(SandGround::NAME, new SandGround(0));
  GameObjectFactory::factory.learn(WallRockTall::NAME, new WallRockTall(0));

  // Effect
  GameObjectFactory::factory.learn(DispersalEffect::NAME, new DispersalEffect(0, "", 0, 0, 0, 0, 0.0f, ""));

  // Bombs
  GameObjectFactory::factory.learn(Bomb::NAME, new Bomb(0));

  // Components
  ComponentFactory::factory.learn(Daemon::GroundRender::NAME, new Daemon::GroundRender(0, ""));
  ComponentFactory::factory.learn(Daemon::DispersalRender::NAME, new Daemon::DispersalRender(0, "", 0, 0, ""));
  ComponentFactory::factory.learn(Daemon::Life::NAME, new Daemon::Life(0, 100, 100));
  ComponentFactory::factory.learn(Daemon::Explose::NAME, new Daemon::Explose(0, 500, 2, 20));
  ComponentFactory::factory.learn(Daemon::Position::NAME, new Daemon::Position(0));
  ComponentFactory::factory.learn(Daemon::Move::NAME, new Daemon::Move(0));
  ComponentFactory::factory.learn(Daemon::ThrowBomb::NAME, new Daemon::ThrowBomb(0));
  ComponentFactory::factory.learn(Daemon::Colider::NAME, new Daemon::Colider(0));
  ComponentFactory::factory.learn(Daemon::Networks::NAME, new Daemon::Networks(0));
  ComponentFactory::factory.learn(Daemon::NewPlayer::NAME, new Daemon::NewPlayer(0));
  ComponentFactory::factory.learn(Daemon::Render::NAME, new Daemon::Render(0));
  ComponentFactory::factory.learn(Daemon::PlayerRender::NAME, new Daemon::PlayerRender(0, ""));
  ComponentFactory::factory.learn(Daemon::Store::NAME, new Daemon::Store(0));
  ComponentFactory::factory.learn(Daemon::Characteristic::NAME, new Daemon::Characteristic(0));
  ComponentFactory::factory.learn(Daemon::Update::NAME, new Daemon::Update(0));
  ComponentFactory::factory.learn(Daemon::Bonus::NAME, new Daemon::Bonus(0));
  ComponentFactory::factory.learn(Daemon::BonusSpawn::NAME, new Daemon::BonusSpawn(0));
}

Daemon::GameObject	*create_tree(size_t width, size_t height, float frequency, size_t min, size_t max, size_t object)
{
  MapGenerator		gen(width, height, frequency, min, max, object);
  Daemon::GameObject *game = new Game();

  gen.genMap(game);
  return (game);
}

int main(int argc, char const *argv[])
{
  size_t	width;
  size_t	height;
  float		frequency;
  size_t	min;
  size_t	max;
  size_t	object;

  if (argc != 2)
    {
      std::cout << "Usage: " << argv[0] << " port" << std::endl;
      return (EXIT_FAILURE);
    }
  init();
  srand(time(0));
  Daemon::EventTree::core = new Daemon::Core;
  Daemon::DaemonServer *server = new Daemon::DaemonServer(str_to_int(std::string(argv[1])));
  Daemon::DaemonServer::sendq->setNetwork(server);
  Daemon::EventTree::reseau = Daemon::DaemonServer::execq;
  sleep(1);
  while (true)
  {
    Daemon::EventTree::core->reset();
    width = rand() % (8000 - 4000) + 4000;
    height = rand() % (8000 - 4000) + 4000;
    frequency = (static_cast<float>((rand() % 50) + 30) / 100.0f);
    max =  rand() % (3000 - 1000) + 1000;
    min = rand() % (max - 500) + 500;
    object = rand() % (250 - 50) + 50;
    Daemon::EventTree::root = create_tree(width, height, frequency, min, max, object);
    if (Daemon::EventTree::core->wait())
      if (Daemon::EventTree::core->connection())
	if (Daemon::EventTree::core->sync())
	  {
	    Daemon::EventTree::core->run();
	    //	    server->disconnectAll();
	  }
  }
  return (EXIT_SUCCESS);
}

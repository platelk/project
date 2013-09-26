#include <ParsSaves.hh>

ParsSaves::ParsSaves(const std::string & nameFile, const std::string & directoryWay)
  : _nameFile(nameFile), _tiny(new OverTiny(nameFile)), _directoryWay(directoryWay)
{
  this->parsSaves();
}

ParsSaves::~ParsSaves()
{}

std::string					ParsSaves::intToString(int a)
{
  std::stringstream s;

  s << a;
  return s.str();
}

void						ParsSaves::parsSaves()
{
  if (this->_tiny->docIsLoad()){
    this->_tiny->getRootNode("Saves");
    this->_tiny->getNode("Save");
    while (this->_tiny->getActualNode()){
      std::string		file = this->_directoryWay + this->_tiny->getStringAttribute("name") + "_" + this->_tiny->getStringAttribute("id") + ".xml";
      if (this->parsSave(file))
	this->_saves.push_back(this->parsSave(file));
      this->_tiny->getNextNode();
    }
  }
}

Map *					ParsSaves::parsSave(const std::string & nameFile)
{
  std::string			name = "";
  int				id = 0;
  std::string			serialContent = "";
  std::string			serialPlayer_1 = "";
  std::string			serialPlayer_2 = "";
  std::string			screen = "";
  OverTiny*			tiny = new OverTiny(nameFile);
  std::vector<std::string>	ia;

  if (tiny->docIsLoad()){
    tiny->getRootNode("Save");
    name = tiny->getRootStringAttribute("name");
    id = tiny->getRootIntegerAttribute("id");
    if (tiny->getNode("Content"))
      serialContent = tiny->getStringAttribute("serial");
    if (tiny->getNode("Player_1"))
      serialPlayer_1 = tiny->getStringAttribute("serial");
    if (tiny->getNode("Player_2"))
      serialPlayer_2 = tiny->getStringAttribute("serial");
    if (tiny->getNode("IA"))
      ia.push_back(tiny->getStringAttribute("serial"));
    while (tiny->getNextNode("IA"))
      ia.push_back(tiny->getStringAttribute("serial"));
    if (tiny->getNode("Screen"))
      screen = tiny->getStringAttribute("img");
    delete tiny;
    return new Map(name, id, serialContent, serialPlayer_1, serialPlayer_2, ia, screen);
  }
  return 0;
}

void						ParsSaves::saveSaves()
{
  std::ofstream				file;

  file.open(this->_nameFile.c_str(), std::ios::out | std::ios::trunc);
  if (!file){}
  else{
    file << "<Saves>" << std::endl;
    for (std::vector<Map *>::iterator it = this->_saves.begin(); it != this->_saves.end(); ++it){
      file << "\t<Save "
	   << "name=\"" << (*it)->getName() << "\" "
	   << "id=\"" << (*it)->getId() << "\"/>" << std::endl;
      this->saveSave((this->_directoryWay + (*it)->getName() + "_" + this->intToString((*it)->getId()) + ".xml"), *it);
    }
    file << "</Saves>" << std::endl;
    file.close();
  }
}

void						ParsSaves::saveSave(const std::string &nameFile, Map *map)
{
  std::ofstream				file;

  file.open(nameFile.c_str(), std::ios::out | std::ios::trunc);
  if (!file){}
  else{
    file << "<Save "
	 << "name=\"" << map->getName() << "\" id=\"" << map->getId()
	 << "\">" << std::endl;
    file << "\t<Content serial=\"" << map->getSerialContent() << "\"/>" << std::endl;
    file << "\t<Player_1 serial=\"" << map->getSerialPlayer_1() << "\"/>" << std::endl;
    file << "\t<Player_2 serial=\"" << map->getSerialPlayer_2() << "\"/>" << std::endl;
    if (!map->getIa().empty()){
      std::vector<std::string> ias = map->getIa();
      for (std::vector<std::string>::iterator it = ias.begin(); it != ias.end(); ++it)
	file << "\t<IA serial=\"" << (*it) << "\"/>" << std::endl;
    }
    file << "\t<Screen img=\"" << map->getScreen() << "\"/>" << std::endl;
    file << "</Save>" << std::endl;
    file.close();
  }
}

Map*					ParsSaves::getSave(const std::string & name, int id) const
{
  if (!this->_saves.empty())
    for (std::vector<Map *>::const_iterator it = this->_saves.begin(); it != this->_saves.end(); ++it){
      if ((*it)->getName().compare(name) == 0
	  && (*it)->getId() == id)
	return *it;
    }
  return 0;
}

std::vector<Map *>	       	       	ParsSaves::getSavesByName(const std::string & name) const
{
  std::vector<Map *>		saves;

  if (this->_saves.size() > 0)
    for (std::vector<Map *>::const_iterator it = this->_saves.begin(); it != this->_saves.end(); ++it){
      if ((*it)->getName().compare(name) == 0)
	saves.push_back(*it);
    }
  return saves;
}

std::vector<Map *>			ParsSaves::getSaves() const
{
  return this->_saves;
}

void					ParsSaves::addSave(Map *map)
{
  std::string				name = map->getName();
  int					id  = 0;
  bool					exist = false;

  for (std::vector<Map *>::iterator it = this->_saves.begin(); it != this->_saves.end(); ++it){
    if ((*it)->getName().compare(name) == 0){
      exist = true;
      if ((*it)->getId() > id)
	id = (*it)->getId();
    }
  }
  if (exist == true)
    map->setId(id);
  this->_saves.push_back(map);
}

void					ParsSaves::deleteSave(Map *map)
{
  std::string				name = map->getName();

  for (std::vector<Map *>::iterator it = this->_saves.begin(); it != this->_saves.end(); ++it){
    if ((*it)->getName().compare(name) == 0
	&& map->getId() == (*it)->getId()){
      this->_saves.erase(it);
    }
  }
}

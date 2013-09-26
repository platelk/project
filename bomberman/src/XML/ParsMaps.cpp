#include <ParsMaps.hh>

ParsMaps::ParsMaps(const std::string & nameFile, const std::string & directoryWay)
  : _nameFile(nameFile), _tiny(new OverTiny(nameFile)), _directoryWay(directoryWay)
{
  this->parsMaps();
}

ParsMaps::~ParsMaps()
{}

std::string					ParsMaps::intToString(int a)
{
  std::stringstream s;

  s << a;
  return s.str();
}

void						ParsMaps::parsMaps()
{
  if (this->_tiny->docIsLoad()){
    this->_tiny->getRootNode("Maps");
    this->_tiny->getNode("Map");
    while (this->_tiny->getActualNode()){
      std::string		file = this->_directoryWay + this->_tiny->getStringAttribute("name") + "_" + this->_tiny->getStringAttribute("id") + ".xml";
      if (this->parsMap(file))
	this->_maps.push_back(this->parsMap(file));
      this->_tiny->getNextNode();
    }
  }
}

Map *					ParsMaps::parsMap(const std::string & nameFile)
{
  std::string			name = "";
  int				id = 0;
  std::string			serialContent = "";
  std::string			screen = "";
  OverTiny*			tiny = new OverTiny(nameFile);

  if (tiny->docIsLoad()){
    tiny->getRootNode("Map");
    name = tiny->getRootStringAttribute("name");
    id = tiny->getRootIntegerAttribute("id");
    if (tiny->getNode("Content"))
      serialContent = tiny->getStringAttribute("serial");
    if (tiny->getNode("Screen"))
      screen = tiny->getStringAttribute("img");
    delete tiny;
    return new Map(name, id, serialContent, screen);
  }
  return 0;
}

void						ParsMaps::saveMaps()
{
  std::ofstream				file;

  file.open(this->_nameFile.c_str(), std::ios::out | std::ios::trunc);
  if (!file){}
  else{
    file << "<Maps>" << std::endl;
    for (std::vector<Map *>::iterator it = this->_maps.begin(); it != this->_maps.end(); ++it){
      file << "\t<Map "
	   << "name=\"" << (*it)->getName() << "\" "
	   << "id=\"" << (*it)->getId() << "\"/>" << std::endl;
      this->saveMap((this->_directoryWay + (*it)->getName() + "_" + this->intToString((*it)->getId()) + ".xml"), *it);
    }
    file << "</Maps>" << std::endl;
    file.close();
  }
}

void						ParsMaps::saveMap(const std::string &nameFile, Map *map)
{
  std::ofstream				file;

  file.open(nameFile.c_str(), std::ios::out | std::ios::trunc);
  if (!file){}
  else{
    file << "<Map "
	 << "name=\"" << map->getName() << "\" id=\"" << map->getId()
	 << "\">" << std::endl;
    file << "\t<Content serial=\"" << map->getSerialContent() << "\"/>" << std::endl;
    file << "\t<Screen img=\"" << map->getScreen() << "\"/>" << std::endl;
    file << "</Map>" << std::endl;
    file.close();
  }
}

Map*					ParsMaps::getMap(const std::string & name, int id) const
{
  if (this->_maps.size() > 0)
    for (std::vector<Map *>::const_iterator it = this->_maps.begin(); it != this->_maps.end(); ++it){
      if ((*it)->getName().compare(name) == 0
	  && (*it)->getId() == id)
	return *it;
    }
  return 0;
}

std::vector<Map *>	       	       	ParsMaps::getMapsByName(const std::string & name) const
{
  std::vector<Map *>		maps;

  if (this->_maps.size() > 0)
    for (std::vector<Map *>::const_iterator it = this->_maps.begin(); it != this->_maps.end(); ++it){
      if ((*it)->getName().compare(name) == 0)
	maps.push_back(*it);
    }
  return maps;
}

std::vector<Map *>			ParsMaps::getMaps() const
{
  return this->_maps;
}

void					ParsMaps::addMap(Map *map)

{  std::string				name = map->getName();
  int					id  = 0;
  bool					exist = false;

  for (std::vector<Map *>::iterator it = this->_maps.begin(); it != this->_maps.end(); ++it){
    if ((*it)->getName().compare(name) == 0){
      exist = true;
      if ((*it)->getId() > id)
	id = (*it)->getId();
    }
  }
  if (exist == true)
    map->setId(id);
  this->_maps.push_back(map);
}

void					ParsMaps::deleteMap(Map *map)
{
  std::string				name = map->getName();

  for (std::vector<Map *>::iterator it = this->_maps.begin(); it != this->_maps.end(); ++it){
    if ((*it)->getName().compare(name) == 0
	&& map->getId() == (*it)->getId()){
      this->_maps.erase(it);
    }
  }
}

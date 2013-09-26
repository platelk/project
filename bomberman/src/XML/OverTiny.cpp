//C++
#include	<iostream>

//Local
#include	<OverTiny.hh>

OverTiny::OverTiny(std::string nameFile)
{
  this->_doc = new tinyxml2::XMLDocument();
  if (this->_doc->LoadFile(nameFile.c_str()) != tinyxml2::XML_NO_ERROR){
    this->_loadSucces = false;
  }
  else
    this->_loadSucces = true;
}

OverTiny::~OverTiny()
{}

bool		       	OverTiny::docIsLoad() const
{
  return this->_loadSucces;
}

tinyxml2::XMLDocument*		OverTiny::getDoc() const
{
  return this->_doc;
}

void			      	OverTiny::clearDoc()
{
  this->_doc->DeleteNode(this->_root);
}

bool				OverTiny::saveDoc()
{
  if (!this->_nameFile.empty()){
    this->_doc->SaveFile(this->_nameFile.c_str());
    return true;
  }
  return false;
}

bool				OverTiny::saveDoc(const std::string &nameFile)
{
  if (!this->_nameFile.empty()){
    this->_doc->SaveFile(nameFile.c_str());
    return true;
  }
  return false;
}

tinyxml2::XMLElement*		OverTiny::getRootNode(const std::string &nameNode)
{
  if (this->docIsLoad()){
    this->_root = this->_doc->FirstChildElement(nameNode.c_str());
    if(!this->_root)
      return NULL;
  }
  return this->_root;
}

tinyxml2::XMLElement*		OverTiny::getNode(const std::string &nameNode)
{
  if (this->docIsLoad() && this->_root){
    this->_actualNode = this->_root->FirstChildElement(nameNode.c_str());
    if (!this->_actualNode)
      return NULL;
  }
  return this->_actualNode;
}

tinyxml2::XMLElement*		OverTiny::getNextNode()
{
  if (this->docIsLoad() && this->_actualNode){
    this->_actualNode = this->_actualNode->NextSiblingElement();
    if (!this->_actualNode){
      return NULL;
    }
  }
  return this->_actualNode;
}

tinyxml2::XMLElement*		OverTiny::getNextNode(const std::string &search)
{
  if (this->docIsLoad() && this->_actualNode){
    this->_actualNode = this->_actualNode->NextSiblingElement(search.c_str());
    if (!this->_actualNode){
      return NULL;
    }
  }
  return this->_actualNode;
}

tinyxml2::XMLElement*		OverTiny::getNextNode(tinyxml2::XMLElement& elem)
{
    this->_actualNode = elem.NextSiblingElement();
    if (!this->_actualNode)
      return NULL;
  return this->_actualNode;
}

tinyxml2::XMLElement*		OverTiny::getChildNode(const std::string &nameNode)
{
  if (this->docIsLoad() && this->_actualNode){
    this->_actualChildNode = this->_actualNode->FirstChildElement(nameNode.c_str());
    if (!this->_actualChildNode)
      return NULL;
  }
  return this->_actualChildNode;
}

tinyxml2::XMLElement*		OverTiny::getNextChildNode()
{
  if (this->_actualChildNode){
    this->_actualChildNode = this->_actualChildNode->NextSiblingElement();
    if (!this->_actualChildNode)
      return NULL;
  }
  return this->_actualChildNode;
}

tinyxml2::XMLElement*		OverTiny::getNextChildNode(tinyxml2::XMLElement& elem)
{
  this->_actualChildNode = elem.NextSiblingElement();
  if (!this->_actualChildNode)
    return NULL;
  return this->_actualChildNode;
}

std::string			OverTiny::getRootStringAttribute(const std::string &att)
{
  std::string ret = "";

  if (this->_root != NULL)
    ret = this->_root->Attribute(att.c_str());
  return ret;
}

std::string			OverTiny::getStringAttribute(const std::string &att)
{
  std::string ret = "";

  if (this->_actualNode != NULL)
    ret = this->_actualNode->Attribute(att.c_str());
  return ret;
}

std::string			OverTiny::getChildStringAttribute(const std::string &att)
{
  std::string ret = "";

  if (this->_actualChildNode != NULL)
    ret = this->_actualChildNode->Attribute(att.c_str());
  return ret;
}

int				OverTiny::getRootIntegerAttribute(const std::string &att)
{
  int i = 0;

  if (this->_root != NULL)
    this->_root->QueryIntAttribute(att.c_str(), &i);
  return i;
}

int				OverTiny::getIntegerAttribute(const std::string &att)
{
  int i = 0;

  if (this->_actualNode != NULL)
    this->_actualNode->QueryIntAttribute(att.c_str(), &i);
  return i;
}

int				OverTiny::getChildIntegerAttribute(const std::string &att)
{
  int i = 0;

  if (this->_actualChildNode != NULL)
    this->_actualChildNode->QueryIntAttribute(att.c_str(), &i);
  return i;
}

tinyxml2::XMLElement*		OverTiny::getActualRoot() const
{
  return this->_root;
}

tinyxml2::XMLElement*		OverTiny::getActualNode() const
{
  return this->_actualNode;
}

tinyxml2::XMLElement*		OverTiny::getActualChildNode() const
{
  return this->_actualChildNode;
}

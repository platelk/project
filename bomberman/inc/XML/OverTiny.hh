#ifndef __OVER_TINY_HH__
#define __OVER_TINY_HH__

#include	<string>

#include	<tinyxml2.h>

class OverTiny
{
public:
  OverTiny(std::string);
  ~OverTiny();

  bool				docIsLoad() const;

  //get Node
  tinyxml2::XMLDocument*       	getDoc() const;
  void			       	clearDoc();
  bool				saveDoc();
  bool				saveDoc(const std::string &);
  tinyxml2::XMLElement*		getRootNode(const std::string &);
  tinyxml2::XMLElement*		getNode(const std::string &);
  tinyxml2::XMLElement*		getNextNode();
  tinyxml2::XMLElement*		getNextNode(const std::string &);
  tinyxml2::XMLElement*		getNextNode(tinyxml2::XMLElement &);

  //get Child Node
  tinyxml2::XMLElement*		getChildNode(const std::string &);
  tinyxml2::XMLElement*		getNextChildNode();
  tinyxml2::XMLElement*		getNextChildNode(tinyxml2::XMLElement &);

  //get attribut
  std::string 			getRootStringAttribute(const std::string &);
  std::string 			getStringAttribute(const std::string &);
  std::string		        getChildStringAttribute(const std::string &);
  int				getRootIntegerAttribute(const std::string &);
  int				getIntegerAttribute(const std::string &);
  int				getChildIntegerAttribute(const std::string &);

  //getters
  tinyxml2::XMLElement*		getActualRoot() const;
  tinyxml2::XMLElement*		getActualNode() const;
  tinyxml2::XMLElement*		getActualChildNode() const;

private:
  bool				_loadSucces;
  std::string			_nameFile;

  //actual Node
  tinyxml2::XMLDocument*       	_doc;
  tinyxml2::XMLElement*		_root;
  tinyxml2::XMLElement*		_actualNode;
  tinyxml2::XMLElement*		_actualChildNode;
};

#endif

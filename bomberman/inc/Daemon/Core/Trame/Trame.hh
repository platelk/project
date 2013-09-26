#ifndef __TRAME_H__
# define __TRAME_H__

#include <iostream>
#include <sstream>
#include <vector>

namespace Daemon
{
  class Trame
  {
  private:
    std::string         	    _arg;
    std::string			        _event;
    int			                _id;
    std::string             	_targ_id;
    std::string	                _targ_type;
    std::string			        _type;

    std::string    getData(std::stringstream &ss);
    void    recupId(std::stringstream &ss);
    void    recupEvent(std::stringstream &ss);
    void    recupType(std::stringstream &ss);
    void    recupTargetType(std::stringstream &ss);
    void    recupTargetId(std::stringstream &ss);
    void    recupArgument(std::stringstream &ss);

    void    transformData(std::stringstream &ss, int i) const;
    void    transformData(std::stringstream &ss, const std::string & s) const;

  public:
    Trame(const std::string &msg);
    Trame(int id,
	  const std::string &event,
	  const std::string &type,
	  const std::string &targ_type,
	  const std::string & targ_id,
	  const std::string &arg);

    virtual ~Trame();

    void		init(const std::string &msg);
    void        init(int id,
                    const std::string &event,
                    const std::string &type,
                    const std::string &targ_type,
                    const std::string & targ_id,
                    const std::string &arg);

    std::string	                getArgument() const;
    std::string			        getEvent() const;
    int				            getId() const;
    std::vector<std::string>	getTargetId() const;
    std::vector<std::string>	getTargetType() const;
    std::string			        getType() const;

    void      setArgument(std::string arg);
    void      setEvent(const std::string &e);
    void      setId(int id);
    void      setTargetId(std::string tab_id);
    void      setTargetType(std::string targ_type);
    void      setType(const std::string &type);

    std::string toString() const;

    bool	exec;
  };
}

#endif /* !__TRAME_H__ */

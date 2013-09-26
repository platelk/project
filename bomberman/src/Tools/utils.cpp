//
// utils.cpp for /home/vink/rendu/rush-mars-2016-platel_k/src/protocol/utils.cpp in /home/vink/rendu/rush-mars-2016-platel_k/inc/proto
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Sat Mar  9 16:27:20 2013 kevin platel
// Last update Sat Jun  8 19:31:30 2013 kevin platel
//

#include <iostream>
#include <vector>
#include <sstream>

std::string int_to_str(int i)
{
  std::stringstream ss("");

  ss << i;
  return (ss.str());
}

int str_to_int(const std::string &s)
{
  std::stringstream ss(s);
  int i = 0;

  ss >> i;
  return i;
}

std::string double_to_str(double i)
{
  std::stringstream ss;

  ss << i;
  return ss.str();
}

double str_to_double(const std::string &s)
{
  std::stringstream ss(s);
  float i = 0.0;

  ss >> i;
  return i;
}

std::vector<std::string> split_string(const std::string &s, char delim)
{
  std::vector<std::string> elems;
  std::stringstream ss(s);
  std::string item;
  std::vector<std::string> v;

  if (s == "")
    return std::vector<std::string>();
  v.push_back(s);
  if (s.find(delim) == std::string::npos)
    return v;
  while(std::getline(ss, item, delim))
    {
      elems.push_back(item);
    }
  return elems;
}

static std::vector<std::string> rec_split_string(const std::string &s, const std::string &delim, unsigned int n)
{
  std::vector<std::string>	res;
  std::vector<std::string>	tot_res;
  std::vector<std::string>	res_aux;

  if (n >= delim.size())
    {
      res.push_back(s);
      return (res);
    }
  res = split_string(s, delim.at(n));
  for (unsigned int i = 0; i < res.size(); ++i)
    {
      res_aux = rec_split_string(res[i], delim, n+1);
      if (res_aux.size())
	tot_res.insert(tot_res.begin() + (tot_res.size()), res_aux.begin(), res_aux.end());
       }
  return (tot_res);
}

std::vector<std::string> split_string(const std::string &s, const std::string &delim)
{
  std::vector<std::string> v;

  v.push_back(s);
  if (s == "")
    return std::vector<std::string>();
  if (s.find(delim) == std::string::npos)
    return v;
  return (rec_split_string(s, delim, 0));
}

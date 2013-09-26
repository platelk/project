//
// main.cpp for /home/vink/projet/cpp/bomberman/src/main.cpp in /home/vink/projet/cpp/bomberman/src
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Sun Jun  9 20:59:50 2013 kevin platel
// Last update Tue Jun 11 11:49:13 2013 alexis leprovost
//

#include <cstdlib>
#include <string>
#include "Fork.hpp"

int main(int ac, char **av)
{
  std::string port = "5252";
  std::string ip = "127.0.0.1";

  if (ac > 1)
    port = std::string(av[1]);
  if (ac > 2)
    ip = std::string(av[2]);

  Fork<char const *, int> a(&system, std::string("./bin/server " + port).c_str());
  a.run();
  system(std::string("./bin/client " + port + " " + ip).c_str());
  a.stop();
  system("killall server");
  system("killall client");
  return 0;
}

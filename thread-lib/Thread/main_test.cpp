//
// main_test.cpp for /home/vink/projet/cpp/thread-lib/Thread/main_test.cpp in /home/vink/projet/cpp/thread-lib/Thread
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Apr 16 01:27:41 2013 kevin platel
// Last update Thu Apr 18 14:32:11 2013 vink
//

#include <unistd.h>
#include <time.h>
#include "Thread.hpp"
#include "ThreadPool.hpp"
#include "Fork.hpp"

int	add(int a)
{
  return (a + a);
}

int	my_func(int param)
{
  int	i;

  for (i = 0; i < 1; i++)
    {
      sleep(1);
    }
  return (param);
}

int main()
{
  Thread<int, int> a(&my_func);
  ThreadPool<int, int>	pool(5, 5, &add);
  Fork<int, int>	b(&my_func);
  int	nb;

  a.run();
  pool.sendRessource(42);
  pool.sendRessource(8);
  pool.sendRessource(23);
  pool.sendRessource(42);
  pool.sendRessource(8);
  pool.sendRessource(23);
  pool.sendRessource(42);
  pool.sendRessource(8);
  pool.sendRessource(23);
  pool.sendRessource(42);
  pool.sendRessource(8);
  pool.sendRessource(23);
  pool.sendRessource(42);
  pool.sendRessource(8);
  pool.sendRessource(23);
  pool.sendRessource(42);
  pool.sendRessource(8);
  pool.sendRessource(23);
  pool.sendRessource(42);
  pool.sendRessource(8);
  pool.sendRessource(23);
  std::cout << "GETTING !" << std::endl;
  printf("Ressource = %d\n", pool.getRessource());
  printf("Ressource = %d\n", pool.getRessource());
  printf("Ressource = %d\n", pool.getRessource());
  printf("Ressource = %d\n", pool.getRessource());
  printf("Ressource = %d\n", pool.getRessource());
  printf("Ressource = %d\n", pool.getRessource());
  printf("Ressource = %d\n", pool.getRessource());
  printf("Ressource = %d\n", pool.getRessource());
  printf("Ressource = %d\n", pool.getRessource());
  printf("Ressource = %d\n", pool.getRessource());
  printf("Ressource = %d\n", pool.getRessource());
  printf("Ressource = %d\n", pool.getRessource());
  printf("Ressource = %d\n", pool.getRessource());
  printf("Ressource = %d\n", pool.getRessource());
  printf("Ressource = %d\n", pool.getRessource());
  printf("Ressource = %d\n", pool.getRessource());
  printf("Ressource = %d\n", pool.getRessource());
  printf("Ressource = %d\n", pool.getRessource());
  std::cin >> nb;
  return 0;
}

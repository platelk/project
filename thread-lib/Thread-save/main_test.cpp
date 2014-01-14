//
// main_test.cpp for /home/vink/projet/cpp/thread-lib/Thread/main_test.cpp in /home/vink/projet/cpp/thread-lib/Thread
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Tue Apr 16 01:27:41 2013 kevin platel
// Last update Thu Apr 18 03:02:41 2013 vink
//

#include <unistd.h>
#include <time.h>
#include "Thread.hpp"
#include "ThreadPool.hpp"

int	add(int a)
{
  return (a + a);
}

int	my_func(int param)
{
  int	i;

  for (i = 0; i < 10; i++)
    {
      sleep(1);
    }
  return (42);
}

int main(int argc, char *argv[])
{
  Thread<int, int> a(&my_func);
  ThreadPool<int, int>	pool(5, &add);


  a.run();
  pool.sendRessource(42);
  pool.sendRessource(8);
  pool.sendRessource(23);
  while (a.isStop() == true);
  while (a.isStop() == false)
    {
      printf("waitting [%lf]...\n", a.getTime());
      usleep(2000);
    }
  printf("time %lf (%d)\n", a.getTime(), a.join(NULL));
  printf("Ressource = %d", pool.getRessource());
  return 0;
}

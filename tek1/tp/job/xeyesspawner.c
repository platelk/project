/*
** xeyesspawner.c for job in /home/vink/projet/tp/job
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Mar  8 10:04:29 2012 kevin platel
** Last update Thu Mar  8 11:17:41 2012 kevin platel
*/


#include <unistd.h>

int	main(int ac, char **av)
{
  int	nb;
  int	id;
  int	f_id;
  int	gid;

  nb = atoi(av[1]) + 1;
  gid = 0;
  while (nb)
    {
      if ((id = fork()) == 0)
	{
	  execlp("./xeyes_fedo64", "xeyes_fedo64", 0);
	}
      else
	{
	  if (nb == atoi(av[1]) + 1)
	    f_id = id;
	  if (setpgid(id, gid) == -1)
	    {
	      write(2, "erreur setpgrid\n", strlen("erreur setpgrid\n"));
	      perror("setpgid");
	    }
	  if (f_id == id)
	    {
	      if (tcsetpgrp(0, getpgid(id)) == -1)
		write(2, "erreur tcspgrid\n", strlen("erreur tcspgrid\n"));
	      if (tcsetpgrp(1, getpgid(id)) == -1)
		write(2, "erreur tcspgrid\n", strlen("erreur tcspgrid\n"));
	    }
	  sleep(3);
	}
      nb--;
    }
  return (0);
}

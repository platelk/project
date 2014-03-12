/*
** main.c for main in /home/ozouf_h//rush-troll-oz-pl/trunk/Domilkins
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Fri Jun  8 16:15:23 2012 harold ozouf
** Last update Fri Jun  8 17:11:06 2012 harold ozouf
*/

#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>

#define		FD		1
#define		MAGIC		"NYAN"
#define		DELAIS_MAX	"30"
#define		NBR_PORTE	"255"
#define		DELAIS_PORTE	"3"

void	attack_gate(int fd, char *login, char *ville, char *num_gate)
{
  write(fd, MAGIC, strlen(MAGIC));
  write(fd, ":", 1);
  write(fd, ville, strlen(ville));
  write(fd, ":", 1);
  write(fd, login, strlen(login));
  write(fd, ":", 1);
  write(fd, num_gate, strlen(num_gate));
  write(fd, ":", 1);
  write(fd, MAGIC, strlen(MAGIC));
  write(fd, "\n", 1);
}

void	write_rulez(int fd)
{
  write(fd, MAGIC, strlen(MAGIC));
  write(fd, ":", 1);
  write(fd, DELAIS_MAX, strlen(DELAIS_MAX));
  write(fd, ":", 1);
  write(fd, NBR_PORTE, strlen(NBR_PORTE));
  write(fd, ":", 1);
  write(fd, DELAIS_PORTE, strlen(DELAIS_PORTE));
  write(fd, ":", 1);
  write(fd, MAGIC, strlen(MAGIC));
  write(fd, "\n", 1);
}

int	main(int argc, char **argv)
{
  if (argc == 2)
    {
      if (!strcmp("--help", argv[1]))
	printf(" login | ville | num_gate \n");
    }
  if (argc == 8)
    {
      write_rulez(FD);
      sleep(1);
      attack_gate(FD, argv[1], argv[2], argv[3]);
    }
  return (0);
}

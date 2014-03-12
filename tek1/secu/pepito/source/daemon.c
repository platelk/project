/*
** Epitech Security Lab
** http://esl.epitech.net - <staff@esl.epitech.eu>
**
** Zerk wrote this.
** As long as you retain this notice you can do whatever
** you want with this stuff. If we meet some day, and you
** think this stuff is worth it, you can buy me a Chimay
** blue in return.
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>

#include <sys/stat.h>

#include "pepito.h"

#include "daemon.h"
#include "network.h"

/* Main daemon functions ---------------------------------------- */

/* sig */

void
sigHandler(int sig)
{
  switch (sig) {
  case SIGINT:
    fprintf(stderr, "Process received SIGINT.\n" \
	    "Exiting\n");
    break;
  case SIGTERM:
    fprintf(stderr, "Process received SIGTERM.\n" \
	    "Exiting\n");
    break;
  }
  remove("pepito.pid");
  exit(EXIT_SUCCESS);
}

/* run */

int
checkOtherProcess(void)
{
  struct stat		buf;

  if (stat("pepito.pid", &buf) == 0) {
    fprintf(stderr, "Daemon is already running.\n"	  \
	    "If it's not, please check 'pepito.pid'.\n"	  \
	    "Exiting\n");
    return -1;
  }
  return 0;
}

int
savePid(void)
{
  FILE*			pidFile;
  pid_t			pid;

  if (!(pidFile = fopen("pepito.pid", "w"))) {
    fprintf(stderr, "Cannot save process id.\n" \
	    "Exiting\n");
    return -1;
  }
  pid = getpid();
  fprintf(pidFile, "%i", pid);
  fclose(pidFile);
  return 0;
}

int
runDaemon(int debug)
{
  char			packetPtr[PACKETLEN];
  size_t	       	packetSize;
  struct sockaddr_in	sa;

  if (checkOtherProcess())
    return (EXIT_FAILURE);
  signal(SIGTERM, sigHandler);
  signal(SIGINT, sigHandler);
  signal(SIGUSR1, sigHandler);

  if (!debug) {
    daemon(1, 1);
    if (savePid())
      return EXIT_FAILURE;
  }

  fprintf(stderr, "Daemon started\n");

  initConnection(&sa);
  while (1) {
    setClient(acceptClient(&sa));
    bzero(packetPtr, PACKETLEN);
    getPacket(packetPtr, &packetSize);
    handlePacket(packetPtr, packetSize);
    setClient(-1);
  }
  setSock(-1);
  return EXIT_SUCCESS;
}

/* stop */

int
stopDaemon(void)
{
  int			pid;
  FILE*			pidFile;

  if ((pidFile = fopen("pepito.pid", "r")) == NULL)
    return EXIT_SUCCESS;
  fscanf(pidFile, "%i", &pid);
  kill(pid, SIGUSR1);
  fprintf(stderr, "Stopping daemon (%i)\n", pid);
  remove("pepito.pid");
  return EXIT_SUCCESS;
}

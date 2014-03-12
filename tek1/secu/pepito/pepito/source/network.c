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

#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <netinet/in.h>

#include "pepito.h"

#include "network.h"
#include "utils.h"

static int	       	sockFd = -1;
static int	       	client = -1;

void
initConnection(struct sockaddr_in *sa)
{
  if ((sockFd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    die("socket()");

  bzero(sa, sizeof *sa);
  sa->sin_family = AF_INET;
  sa->sin_port = htons(PORT);
  sa->sin_addr.s_addr = htonl(INADDR_ANY);

  if (setsockopt(sockFd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)) < 0)
    die("setsockopt()");
  if (bind(sockFd, (struct sockaddr *)sa, sizeof *sa) < 0)
    die("bind()");
  if (listen(sockFd, 1) < 0)
    die("listen()");
}

int
acceptClient(struct sockaddr_in *sa)
{
  int			res;
  socklen_t	       	sa_len = sizeof *sa;

  if ((res = accept(sockFd, (struct sockaddr *)sa, &sa_len)) < 0)
    die("accept()");
  return res;
}

int
getPacket(void *packetPtr, size_t *packetSize)
{
  if ((*(ssize_t *)packetSize = recv(client, packetPtr, PACKETLEN, 0)) < 0)
    die("recv()");
  if (*packetSize > 0)
    return (1);
  return 0;
}

void
sendLogMessage(char *msg)
{
  write(client, msg, strlen(msg));
  fprintf(stderr, msg);
}

void
setClient(int fd)
{
  if (client != -1)
    close(client);
  client = fd;
}

void
setSock(int fd)
{
  if (sockFd != -1)
    close(sockFd);
  sockFd = fd;
}

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

#ifndef			_NETWORK_H__
# define		_NETWORK_H__

#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <netinet/in.h>

void			initConnection(struct sockaddr_in *sa);
int			acceptClient(struct sockaddr_in *sa);
int			getPacket(void *packetPtr, size_t *packetSize);
void			sendLogMessage(char *msg);

void			setClient(int fd);
void			setSock(int fd);

#endif		    /* !_NETWORK_H__ */

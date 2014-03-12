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

#ifndef		__DAEMON_H__
# define	__DAEMON_H__

#define NORMAL 0
#define DEBUG  1

int			runDaemon(int debug);
int			stopDaemon(void);

int			savePid(void);
int			checkOtherProcess(void);
void			sigHandler(int sig);

#endif	    /* !__DAEMON_H__ */

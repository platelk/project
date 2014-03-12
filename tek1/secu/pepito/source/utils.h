/*
** Epitech Security Lab
** http://esl.epitech.net - <staff@esl.epitech.eu>
**
** Mota, The Polish Plumber and Zerk wrote this.
** As long as you retain this notice you can do whatever
** you want with this stuff. If we meet some day, and you
** think this stuff is worth it, you can buy us [:drinks:]*
** in return.
*/

#ifndef		__UTILS_H__
# define	__UTILS_H__

void			die(char *fctName);

char			getChar(void **p);
int 			getNumber(void **p, size_t *packetSize);
char 			*getStr(void **p, size_t *l);

#endif

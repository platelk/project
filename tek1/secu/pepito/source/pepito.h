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

#ifndef		__PEPITO_H__
# define	__PEPITO_H__

#define PACKETLEN	0x1000
#define PORT		0x7A69

#define PASSWD_CHANGE		"Password successfully changed\n"
#define AD_CHANGE		"Advertisement successfully changed\n"
#define PASSWD_FAIL		"Wrong password\n"

#define INGREDIENT_BOUGHT	"Ingredient successfully acquired.\n"
#define UNKNOWN_INGREDIENT	"Unknown ingredient.\n"
#define UNKNOWN_RECIPE		"Unknown recipe.\n"

#define NOBODY		0
#define ADMIN		1
#define USER		2

int			checkPassword(char *password);

int			handlePacket(void *packetPtr, size_t packetSize);

#endif

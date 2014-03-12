/* Epitech Security Lab
 * http://esl.epitech.net - <staff@esl.epitech.net>
 *
 * Kevin Szkudlapski wrote this.
 * As long as you retain this notice you can do whatever
 * you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me an
 * absinthe in return.
 *
 */

#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 != *s2)
	{
		s1++;
		s2++;
	}
	return *s1 - *s2;
}

int main(void)
{
	struct utsname un;
	const char *p = "UNIX BarbieOS";

	if (getenv("UNAME_s"))
	{
		puts("UNAME_s must be unset");
		return 0;
	}
	if (uname(&un) == -1)
	{
		perror("uname");
		return 0;
	}
	printf("You are running under %s\n", un.sysname);

	if (!my_strcmp(un.sysname, p))
	{
		puts("You did it :) PASS_KEY\n");
		return 1;
	}

	printf("This program has been designed to run under %s, please upgrade your OS.\n", p);

	return 0;
}

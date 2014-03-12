
#include <stdio.h>
#include <string.h>

#define BUF_SZ 2

char const * const passphrase = "cyte";

int
main(int ac, char **av) {
	struct s {
		char *a;
		char n[BUF_SZ];
		char c;
		int (*f)(int, char**);
	} ss = {
		.a = 0,
		.c = 0,
		.n = {0},
		.f = &main,
	};
	return (ac > 1 ? strcpy(ss.n, 1[av]) && (ss.c == *passphrase) && puts(passphrase) : ss.f - &main + 1);
}

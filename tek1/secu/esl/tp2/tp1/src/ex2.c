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

#include <stdlib.h>
#include <stdio.h>

void my_exit(void)
{
	puts("PASS_KEY");
}

int main(void)
{
	atexit(my_exit);
	_Exit(EXIT_SUCCESS);
}

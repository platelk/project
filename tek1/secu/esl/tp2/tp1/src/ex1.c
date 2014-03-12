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

#include <stdio.h>
#include <strings.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!strcmp(av[1], "PASS_KEY" + 2))
		{
			puts("You did it :)\n");
			return 1;
		}
	}
	puts("You failed");
	printf("%s : pass\n", av[0]);
	return 0;
}

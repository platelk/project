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
#include <time.h>
#include <stdlib.h>

int main(void)
{
	time_t t = time(NULL);
	struct tm *cur_time = gmtime(&t);
	if (cur_time->tm_year > 108)
	{
		puts("Licence expired");
		return 1;
	}

	puts("You did it :) PASS_KEY\n");
	return 0;
}

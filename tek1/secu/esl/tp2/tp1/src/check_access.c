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
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define AUTH_LOGIN    "root"
#define AUTH_ID	      0

typedef enum	  e_auth
{
  AUTH,
  NO_AUTH
} t_auth;

t_auth	  weak_check(void)
{
  if (getuid() == AUTH_ID)
    return (AUTH);
  return (NO_AUTH);
}

int	  main(void)
{
  if (weak_check() == NO_AUTH)
    {
      fprintf(stderr, "Ca ne va pas etre possible.\n");
      return (EXIT_FAILURE);
    }
  printf("Welcome %s your secret is PASS_KEY\n", getlogin());
  return (EXIT_SUCCESS);
}

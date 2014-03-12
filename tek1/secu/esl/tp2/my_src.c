#include <stdio.h>
#include <stdlib.h>

void	encrypt(char *str)
{
  while (*str)
    {
      printf("%x", *str ^ '\xdd');
      str++;
    }
}

int	main(int ac, char **av)
{
  char	str[] = "Je te casse la gorge\n";

  encrypt(str);
  return (0);
}

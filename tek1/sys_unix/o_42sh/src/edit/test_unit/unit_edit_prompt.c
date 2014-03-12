#include	<stdlib.h>
#include	<stdio.h>

#include	"edit.h"
#include	"env.h"
#include	"config.h"

int	main(void)
{
  t_config	*c1;
  t_config	*c2;

  c1 = config_parser(".unit");
  c2 = config_parser(".error");
  printf("%s\n%s\n", c1->prompt, c2->prompt);
  return (0);
}

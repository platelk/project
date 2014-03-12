#include	<stdlib.h>
#include	<stdio.h>

#include	"config.h"
#include	"my.h"
#include	"xsys.h"

int	main(void)
{
  t_config	*config;

  if ((config = config_parser("./test_unit/.unit")) == NULL ||
      (config = config_parser("./test_unit/.error")) != NULL)
    {
      printf("Parser Fail.\n");
      return (1);
    }
  printf("Parser Ok.\n");
  return (0);
}

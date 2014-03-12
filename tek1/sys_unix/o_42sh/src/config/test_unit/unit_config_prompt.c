#include	<stdlib.h>
#include	<stdio.h>

#include	"config.h"
#include	"xsys.h"
#include	"my.h"

int	main(void)
{
  t_config	config;

  printf("Resultat attendu :\n- \"Just a basic prompt > \"\n");
  printf("Resultat obtenu :\n");
  config.prompt = NULL;
  config_prompt("set prompt=\"Just a basic prompt > \"", &config);
  if (my_strcmp("Just a basic prompt > ", config.prompt))
    {
      printf("- (nulle).\n");
      return (1);
    }
  printf("- \"%s\"\n", config.prompt);
  return (0);
}

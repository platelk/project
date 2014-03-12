#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"config.h"
#include	"xsys.h"
#include	"my.h"

int	main(void)
{
  t_config	config;

  printf("Résultat attendu :\n- TOTO=LOL\n- TITI=TROLOLO\n- KEVIN=NOOB\n");
  printf("Résultat obtenu :\n");
  config.env= NULL;
  config_env("setenv TOTO \"LOL\"", &config);
  config_env("setenv TITI \"TROLOLO\"", &config);
  config_env("setenv KEVIN \"NOOB\"", &config);
  if (strcmp("KEVIN", config.env->name) || strcmp("NOOB", config.env->value) ||
      strcmp("TITI", config.env->prev->name) || strcmp("TROLOLO", config.env->prev->value) ||
      strcmp("TOTO", config.env->prev->prev->name) || strcmp("LOL", config.env->prev->prev->value))
    {
      printf("- (nulle)\n");
      return (1);
    }
  while (config.env && config.env->prev)
    config.env = config.env->prev;
  while (config.env)
    {
      printf("- %s=%s\n", config.env->name, config.env->value);
      config.env = config.env->next;
    }
  return (0);
}

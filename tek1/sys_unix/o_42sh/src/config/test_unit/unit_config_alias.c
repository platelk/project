#include	<stdio.h>
#include	<stdlib.h>

#include	"config.h"
#include	"xsys.h"
#include	"my.h"

int	main(void)
{
  t_config	config;

  printf("Résultat attendu :\n- %s \"%s\"\n- %s \"%s\"\n- %s \"%s\"\n", "z", "zlock", "rm", "rm -i", "ll", "ls -la");
  printf("Résultat obtenu :\n");
  config.alias= NULL;
  config_alias("alias ll 'ls -la'", &config);
  config_alias("alias rm 'rm -i'", &config);
  config_alias("alias z 'zlock'", &config);
  if (my_strcmp("z", config.alias->initial) || my_strcmp("zlock", config.alias->alias) ||
      my_strcmp("rm", config.alias->next->initial) || my_strcmp("rm -i", config.alias->next->alias) ||
      my_strcmp("ll", config.alias->next->next->initial) || my_strcmp("ls -la", config.alias->next->next->alias))
    {
      printf("- (nulle).\n");
      return (1);
    }
  while (config.alias)
    {
      printf("- %s - \"%s\"\n", config.alias->initial, config.alias->alias);
      config.alias = config.alias->next;
    }
  return (0);
}

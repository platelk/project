#include	<stdio.h>
#include	<stdlib.h>

#include	"config.h"
#include	"xsys.h"

int	main(void)
{
  t_config	config;

  printf("Resultat attendu :\n- autolist=1\n- complete=1\n");
  printf("Resultat obtenu :\n");
  if ((config.option = xmalloc(sizeof(int *) * MAX_OPTION_NUMBER)) == NULL)
    return (1);
  config_globing("set autolist", &config);
  config_globing("set complete", &config);
  if (!config.option[AUTOLIST] || !config.option[COMPLETE])
    {
      printf("- (nulle)\n");
      return (1);
    }
  printf("- autolist=%d\n- complete=%d\n", config.option[AUTOLIST], config.option[COMPLETE]);
  return (0);
}


#include	<stdlib.h>
#include	<stdio.h>

#include	"config.h"
#include	"xsys.h"

int	main(void)
{
  t_config	config;

  printf("Resultat attendu :\n- history=100\n- savehist=1000\n");
  printf("Resultat obtenu :\n");
  if ((config.option = xmalloc(sizeof(int *) * MAX_OPTION_NUMBER)) == NULL)
    return (1);
  config_history("set history=100", &config);
  config_savehist("set savehist=1000", &config);
  if (config.option[HISTORY] != 100 || config.option[SAVEHIST] != 1000)
    {
      printf("- (nulle)\n");
      return (1);
    }
  printf("- history=%d\n- savehist=%d\n", config.option[HISTORY], config.option[SAVEHIST]);
  return (0);
}

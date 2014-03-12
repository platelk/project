#include <stdlib.h>
#include "my.h"
#include "stru.h"

struct s_stock_par *my_param_to_tab(int ac, char **av);
int	my_show_tab(struct s_stock_par *par);

int	main(int argc, char **argv)
{
  my_show_tab(my_param_to_tab(argc, argv));
  return (0);
}

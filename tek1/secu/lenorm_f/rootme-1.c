65cn,ll#include <stdio.h>
#include <string.h>


#define BUF_SZ 10

#define __ strncpy

char const * const passphrase = "cyte";


int  main(int ac, char **av) 
{
  char a[BUF_SZ];
  char t[BUF_SZ];
  
  if (ac < 2)
    return 1;
  
  char const * const $0 = av[0];
  bzero(0[av], strlen($0));
  __(t, 1[av], BUF_SZ);
  if  (*a == *passphrase)
    puts(passphrase);
  else
    puts("Non.");
  
  return 0;
}

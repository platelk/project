/*
** main.c for main in /home/platel_k/projet/my_printf
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Nov  9 10:00:59 2011 kevin platel
** Last update Tue Nov 29 22:07:46 2011 kevin platel
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "printf.h"

#include <stdio.h>

int	main(int ac, char **av)
{
  int ret[2];
  char *str = "astek";
  char stre[] = {'a', 's', 10, 'e', 'k', 0};
  char  *str3 = "astek";
  char	str2[5];

  
  printf("##### Tests simple : 1 point par test reussi #####\n");
  printf(   "0) Modulo [%%] : {%%}\n");
  my_printf("=> Modulo [%%] : {%%}\n");
  printf(   "1) Nombre signe [d] : {%d}\n", 42);
  my_printf("=> Nombre signe [d] : {%d}\n", 42);
  printf(   "2) Nombre signe [i] : {%i}\n", 42);
  my_printf("=> Nombre signe [i] : {%i}\n", 42);
  printf(   "3) Nombre octal [o] : {%o}\n", 012345);
  my_printf("=> Nombre octal [o] : {%o}\n", 012345);
  printf(   "3) Nombre octal [o] : {%o}\n", 0);
  my_printf("=> Nombre octal [o] : {%o}\n", 0);
  printf(   "4) Nombre non signe [u] : {%u}\n", 42);
  my_printf("=> Nombre non signe [u] : {%u}\n", 42);
  printf(   "5) Nombre hexadecimal [x] : {%x}\n", 0x12345);
  my_printf("=> Nombre hexadecimal [x] : {%x}\n", 0x12345);
  printf(   "6) Nombre hexadecimal [X] : {%X}\n", 0x12345);
  my_printf("=> Nombre hexadecimal [X] : {%X}\n", 0x12345);
  printf(   "7) Nombre binaire [b] : {101111101111110000001}\n");
  my_printf("=> Nombre binaire [b] : {%b}\n", 1564545);
  printf(   "8) Caractere [c] : {%c}\n", 42);
  my_printf("=> Caractere [c] : {%c}\n", 42);
  printf(   "9) Chaine [s] : {%s}\n", stre);
  my_printf("=> Chaine [s] : {%s}\n", stre);
  printf(   "10) Chaine etendue [S] : as\\012ek\n");
  my_printf("=>  Chaine etendue [S] : %S\n", stre);
  printf(   "11) Pointeur [p] : {%p}\n", str);
  my_printf("=>  Pointeur [p] : {%p}\n", str);
  printf(   "12) Mauvais parametre [k] : {%k}\n", 42);
  my_printf("=>  Mauvais parametre [k] : {%k}\n", 42);

  printf("Appuyez sur [entree] pour continuer...\n");
  getchar();

  printf("\n##### Tests pour verifier : -1pt par resultat errone #####\n");
  printf(   "1) Affichage multiple [d d d] : {%d} {%d} {%d}\n", 0, 42, 2147483647);
  my_printf("=> Affichage multiple [d d d] : {%d} {%d} {%d}\n", 0, 42, 2147483647);
  printf(   "2) Affichage multiple [d d d] : {%d} {%d} {%d}\n", -0, -42, -2147483648);
  my_printf("=> Affichage multiple [d d d] : {%d} {%d} {%d}\n", -0, -42, -2147483648);
  printf(   "3) Affichage multiple [c d s] : {%c} {%d} {%s}\n", 42, 42, str);
  my_printf("=> Affichage multiple [c d s] : {%c} {%d} {%s}\n", 42, 42, str);
  printf(   "4) Affichage multiple [X p d] : {%X} {%p} {%d}\n", 0x12345, str, 42);
  my_printf("=> Affichage multiple [X p d] : {%X} {%p} {%d}\n", 0x12345, str, 42);
  printf(   "5) Affichage multiple [s S X] : {%s} {as\\012ek} {%X}\n", str, -1);
  my_printf("=> Affichage multiple [s S X] : {%s} {%S} {%X}\n", str, stre, -1);
  printf(   "5) Affichage long [d d d ...] : %d %d %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC);
  my_printf("=> Affichage long [d d d ...] : %d %d %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC);
  printf(   "6) Affichage long [s S s ...] : %s as\\012ek %s as\\012ek %s as\\012ek %s as\\012ek %s as\\012ek %s as\\012ek\n", str, str, str, str, str, str);
  my_printf("=> Affichage long [s S s ...] : %s %S %s %S %s %S %s %S %s %S %s %S\n", str, stre, str, stre, str, stre, str, stre, str, stre, str, stre);
  printf("Appuyez sur une touche pour continuer...\n");
  getchar();

  printf("\n##### Formatage : 1pt pour 3 tests reussis  #####\n");
  printf(   "1) Formatage simple [#d] : {%#d}\n", 42);
  my_printf("=> Formatage simple [#d] : {%#d}\n", 42);
  printf(   "2) Formatage simple [#x] : {%#x}\n", 0x12345);
  my_printf("=> Formatage simple [#x] : {%#x}\n", 0x12345);
  printf(   "3) Formatage simple [#o] : {%#o}\n", 012345);
  my_printf("=> Formatage simple [#o] : {%#o}\n", 012345);
  printf(   "4) Formatage simple [0d] : {%0d}\n", 42);
  my_printf("=> Formatage simple [0d] : {%0d}\n", 42);
  printf(   "5) Formatage simple [5d] : {%5d}\n", 42);
  my_printf("=> Formatage simple [5d] : {%5d}\n", 42);
  printf(   "7) Formatage simple [-d] : {%-d}\n", 42);
  my_printf("=> Formatage simple [-d] : {%-d}\n", 42);
  printf(   "8) Formatage simple [+d] : {%+d}\n", 42);
  my_printf("=> Formatage simple [+d] : {%+d}\n", 42);
  printf(   "9) Formatage simple [+d] : {%+d}\n", -42);
  my_printf("=> Formatage simple [+d] : {%+d}\n", -42);
  printf(   "10) Formatage multiple [ 5d] : {% 5d}\n", 42);
  my_printf("=>  Formatage multiple [ 5d] : {% 5d}\n", 42);
  printf(   "11) Formatage multiple [-32o] : {%-32o}\n", 012345);
  my_printf("=>  Formatage multiple [-32o] : {%-32o}\n", 012345);
  printf(   "12) Formatage multiple [-10+d] : {%+-10d}\n", 12345);
  my_printf("=>  Formatage multiple [-10+d] : {%-10+d}\n", 12345);
  printf(   "13) Formatage compose [-5cP] : %-5cP\n", 42);
  my_printf("=>  Formatage compose [-5cP] : %-5cP\n", 42);
  printf(   "14) Formatage compose [-30sP]: %-30sP\n", str);
  my_printf("=> Formatage compose [-30sP]: %-30sP\n", str);
  printf(   "15) Formatage compose [-4SP] : as\\012ekP\n");
  my_printf("=>  Formatage compose [-4SP] : %-4SP\n", stre);
  printf(   "16) Formatage ultracompose [-6.3x] : {%-6.3x}\n", 0x12345);
  my_printf("=>  Formatage ultracompose [-6.3x] : {%-6.3x}\n", 0x12345);
  printf(   "17) Formatage ultracompose [#15.12b] : {101111101111110000001}\n");
  my_printf("=>  Formatage ultracompose [#15.12b] : {%#15.12b}\n", 1564545);
  printf(   "18) Formatage ultracompose [#-6.3d] : {%#-6.3d}\n", -2147483648);
  my_printf("=>  Formatage ultracompose [#-6.3d] : {%#-6.3d}\n", -2147483648);
  printf(   "19) Formatage long [p x lx] : {%p} {%x} {%lx}\n", 0x42424242, 0x42424242, 0x42424242);
  my_printf("=>  Formatage long [p x lx] : {%p} {%x} {%lx}\n", 0x42424242, 0x42424242, 0x42424242);
  printf(   "20) Formatage pourcent [30%%] : {%30%}\n");
  my_printf("=>  Formatage pourcent [30%%] : {%30%}\n");
  printf(   "21) Formatage pourcent [-30pourcent] : {%-30%}\n");
  my_printf("=>  Formatage pourcent [-30pourcent] : {%-30%}\n");
  ret[0] = printf(   "22) Test de la valeur de retour [-10+d s] : {%+-10d} {%s}\n", 12345, str);
  ret[1] = my_printf("=>  Test de la valeur de retour [-10+d s] : {%+-10d} {%s}\n", 12345, str);
  printf(   "23) Verification de la valeur de retour [d] : {%d}\n", ret[0]);
  my_printf("=>  Verification de la valeur de retour [d] : {%d}\n", ret[1]);
  printf(   "24) Test de pile [c c] : {%c} {%c}\n", 0x4142434444434241);
  my_printf("=>  Test de pile [c c] : {%c} {%c}\n", 0x4142434444434241);
  printf(   "25) Test de NULL : {%s}\n", NULL);
  my_printf("=>  Test de NULL : {%s}\n", NULL);
  
  str2[0] = 't';
  str2[1] = 'o';
  str2[2] = 14;
  str2[3] = 'o';
  str2[4] = '\0';;
  
  printf("1)\n");
  printf(   "P : [s] : {%s}\n", str3);
  my_printf("My: [s] : {%s}\n\n", str3);

  printf("2)\n");
  printf(   "P : [S] : {to\\016o}\n");
  my_printf("My: [S] : {%S}\n\n", str2);

  printf("3)\n");
  printf(   "P : [d] : {%d}\n", 42);
  my_printf("My: [d] : {%d}\n\n", 42);

  printf("4)\n");
  printf(   "P : [i] : {%i}\n", 42);
  my_printf("My: [i] : {%i}\n\n", 42);

  printf("5)\n");
  printf(   "P : [c] : {%c}\n", 'A');
  my_printf("My: [c] : {%c}\n\n", 'A');

  printf("6)\n");
  printf(   "P : [x] : {%x}\n", 42);
  my_printf("My: [x] : {%x}\n\n", 42);

  printf("7)\n");
  printf(   "P : [X] : {%X}\n", 42);
  my_printf("My: [X] : {%X}\n\n", 42);

  printf("8)\n");
  printf(   "P : [b] : {101010}\n");
  my_printf("My: [b] : {%b}\n\n", 42);

  printf("9)\n");
  printf(   "P : [o] : {%o}\n", 42);
  my_printf("My: [o] : {%o}\n\n", 42);

  printf("10)\n");
  printf(   "P : [u] : {%u}\n", 0x2A);
  my_printf("My: [u] : {%u}\n\n", 0x2A);

  printf("11)\n");
  printf(   "P : [p] : {%p}\n", str3);
  my_printf("My: [p] : {%p}\n\n", str3);

  printf("12)\n");
  printf(   "P : [p] : {%p}\n", &str3);
  my_printf("My: [p] : {%p}\n\n", &str3);

  printf("13)\n");
  printf(   "P : [%] : {%%}\n");
  my_printf("My: [%] : {%%}\n\n");

  printf("14)\n");
  printf(   "P : [dd] : {%d%d}\n", 42, 42);
  my_printf("My: [dd] : {%d%d}\n\n", 42, 42);

  printf("15)\n");
  printf(   "P : [d d] : {%d} {%d}\n", 42, 42);
  my_printf("My: [d d] : {%d} {%d}\n\n", 42, 42);

  printf("16)\n");
  printf(   "P : [k d z] : {%k} {%d} {%K}\n", 42);
  my_printf("My: [k d z] : {%k} {%d} {%K}\n\n", 42);

  printf("17)\n");
  printf(   "P : [2s] : {%2sblabla} {%d}\n", "abc", 42);
  my_printf("My: [2s] : {%2sblabla} {%d}\n\n", "abc", 42);

  printf("18)\n");
  printf(   "P : [+-5d] : {%+-5d}\n", 42);
  my_printf("My: [+-5d] : {%+-5d}\n\n", 42);

  printf("19)\n");
  printf(   "P : [003s] : {%003s}\n", "coco");
  my_printf("My: [003s] : {%003s}\n\n", "coco");

  printf("20)\n");
  printf(   "P : [- 3.6d] : {%- 3.6d}\n", 42);
  my_printf("My: [- 3.6d] : {%- 3.6d}\n\n", 42);

  printf("21)\n");
  printf(   "P : [-0d] : {%-0d}\n", 42);
  my_printf("My: [-0d] : {%-0d}\n\n", 42);

  printf("22)\n");
  printf(   "P : [     3    d] : {        %     3    d}\n", 4);
  my_printf("My: [     3    d] : {        %     3    d}\n\n", "coco");

  printf("23)\n");
  printf(   "P : [b] : {     111011100110101100100111111111}\n", 999999999);
  my_printf("My: [b] : {     %b}\n\n", 999999999);

  printf("24)\n");
  printf(   "P : [s] : {%%%s}\n", "test");
  my_printf("My: [s] : {%%%s}\n\n", "test");

  printf("25)\n");
  printf(   "P : [ddddddddddddddd] : {%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d}\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  my_printf("My: [ddddddddddddddd] : {%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d}\n\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

  printf("26)\n");
  printf(   "P : [#dx] : {%#dx}\n", 421);
  my_printf("My: [#dx] : {%#dx}\n\n", 421);

  printf("27)\n");
  printf(   "P : [test] : {%test%%}\n");
  my_printf("My: [test] : {%test%%}\n\n");

  printf("28\n");
  printf(   "P : [k et d+++xXs] : {%k et %%d+%+%+%x%X%s}\n", 4, 2, "test");
  my_printf("My: [k et d+++xXs] : {%k et %%d+%+%+%x%X%s}\n\n", 4, 2, "test");

  printf("29)\n");
  /*printf(   "P : [.374206-42ds] : {%.374206-42d%s}\n", 42, "test");
  my_printf("My: [.374206-42ds] : {%.374206-42d%s}\n", 42, "test");*/

  printf("30)\n");
  /*printf(   "P : [ - s [] ~'] : { - %s [] ~'}\n");*/
  /*my_printf("My: [ - s [] ~'] : { - %s [] ~'}\n");*/

  printf("31)\n");
  printf(   "P : [ - s [] ~'] : { - %s [] ~'}\n", NULL);
  my_printf("My: [ - s [] ~'] : { - %s [] ~'}\n", NULL);

  ret[0] = printf(   "P : [-10+d s] : {%-+10d} {%s}\n", 12345, str3);
  ret[1] = my_printf("My: [-10+d s] : {%-+10d} {%s}\n", 12345, str3);
  printf("Test de la valeur de retour \n\tMy: %d\n\t%d\n", ret[0], ret[1]); 
  my_printf("(core dump) Segmentation fault ;)\n");


  
  return(0);
}

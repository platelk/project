/*
** init_image.c for corewar in /home/guiho_r/tek1/corewar/source/VM/image
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Mar  7 19:10:00 2012 ronan guiho
** Last update Tue Mar 13 11:01:04 2012 ronan guiho
*/

#include <stdlib.h>

#include "vm.h"
#include "corewar.h"

t_image		*init_image_el(char *path, int size)
{
  int		i;
  char		*path_image;
  char		*tmp;
  t_image	*image_tab;

  i = -1;
  if ((image_tab = malloc(sizeof(t_image) * size)) == NULL)
     return (NULL);
   while (++i < size)
     {
       tmp = my_getstr(i, "0123456789");
       path_image = my_str_concat(tmp, FORMAT_IMAGE);
       image_tab[i].img = IMG_Load(my_str_concat(path, path_image));
       printf("[*] Loading %s\n", my_str_concat(path, path_image));
       free(tmp);
       free(path_image);
    }
  return (image_tab);
}

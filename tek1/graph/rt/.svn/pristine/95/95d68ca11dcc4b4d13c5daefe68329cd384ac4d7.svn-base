/*
** determ_img_type.c for determ_image_type in /home/jordan/Projets/Epitech/rt/rt/src/init
** 
** Made by jordan vanwalleghem
** Login   <vanwal_j@epitech.net>
** 
** Started on  Wed May 30 14:58:50 2012 jordan vanwalleghem
** Last update Sat Jun  2 06:30:03 2012 jordan vanwalleghem
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "my.h"

#define	IMG_ERROR -1
#define JPG 1
#define	XPM 2
#define	BMP 3

int	determ_img_type(char *path)
{
  int fd;
  int readed;
  char buff[100];
  int ret;

  if (path == NULL || access(path, F_OK) == -1 ||
      (fd = open(path, O_RDONLY)) == -1)
    return (IMG_ERROR);
  ret = IMG_ERROR;
  if ((readed = read(fd, buff, 50)) <= 5);
  else if (readed > 9 && my_strncmp(buff + 6, "JFIF", 3) == 0)
    ret = JPG;
  else if (readed > 9 && my_strncmp(buff, "/* XPM */" , 8) == 0)
    ret = XPM;
  else if (readed > 2 && my_strncmp(buff, "BM", 1) == 0)
    ret = BMP;
  close(fd);
  return (ret);
}

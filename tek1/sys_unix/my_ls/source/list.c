/*
** list.c for list in /home/platel_k/projet/my_ls/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Nov 28 10:37:12 2011 kevin platel
** Last update Thu May 10 11:47:12 2012 kevin platel
*/

#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#include "my.h"
#include "my_ls.h"
#include "data.h"

void	my_put_right(struct stat *info)
{
  S_ISDIR(info->st_mode) ? my_putchar('d') :
    S_ISLNK(info->st_mode) ? my_putchar('l') :
    S_ISSOCK(info->st_mode) ? my_putchar('s') :
    S_ISFIFO(info->st_mode) ? my_putchar('f') : my_putchar('-');
  info->st_mode & S_IRUSR ? my_putchar('r') : my_putchar('-');
  info->st_mode & S_IWUSR ? my_putchar('w') : my_putchar('-');
  info->st_mode & S_IXUSR ? my_putchar('x') : my_putchar('-');
  info->st_mode & S_IRGRP ? my_putchar('r') : my_putchar('-');
  info->st_mode & S_IWGRP ? my_putchar('w') : my_putchar('-');
  info->st_mode & S_IXGRP ? my_putchar('x') : my_putchar('-');
  info->st_mode & S_IROTH ? my_putchar('r') : my_putchar('-');
  info->st_mode & S_IWOTH ? my_putchar('w') : my_putchar('-');
  info->st_mode & S_IXOTH ? my_putchar('x') : my_putchar('-');
}

void	put_id(uid_t pwuid)
{
  struct passwd *uid;

  uid = getpwuid(pwuid);
  if (uid != NULL)
    my_printf(" %s", uid->pw_name);
}

void	put_gid(gid_t gruid)
{
  struct group *gid;

  gid = getgrgid(gruid);
  if (gid != NULL)
    my_printf(" %s", gid->gr_name);
}

void	listing(t_data *directory, char *link, int opt)
{
  struct stat	info;
  char		*link_file;
  char		*date;

  link_file = link_of_file(link, directory);
  if ((lstat(link_file, &info)) == -1)
    {
      perror("lstat");
      exit(0);
    }
  my_put_right(&info);
  my_printf(" %d", info.st_nlink);
  put_id(info.st_uid);
  put_gid(info.st_gid);
  my_printf(" %d", info.st_size);
  date = &(ctime(&(info.st_atime)))[4];
  date[12] = '\0';
  my_printf(" %s", date);
  my_printf(" %s\n", directory->name);
}

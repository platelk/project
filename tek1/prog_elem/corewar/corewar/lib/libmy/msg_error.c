/*
** msg_error.c for lib in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar
** 
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
** 
** Started on  Mon Jan 23 16:09:09 2012 alexandre deceneux
** Last update Tue Mar 13 10:49:50 2012 ronan guiho
*/

#include <unistd.h>

void	msg_error(char *str)
{
  write(2, str, my_strlen(str));
}

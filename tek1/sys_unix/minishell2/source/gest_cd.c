/*
** gest_cd.c for gest_cd in /home/platel_k/projet/minishell1
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Fri Dec 16 10:45:48 2011 kevin platel
** Last update Wed Feb 15 10:22:33 2012 kevin platel
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "minishell.h"
#include "env.h"
#include "pwd.h"

t_pwd	 *go_to_home(t_env *envp, t_pwd *my_pwd)
{
  free_pwd(my_pwd);
  my_pwd = NULL;
  while (envp != NULL && (my_strcmp(envp->name, "HOME") != 0))
    envp = envp->next;
  if (envp != NULL && envp->content != NULL)
    {
      if (chdir(envp->content) == -1)
	my_printf("Error No var HOME in env\n");
      else
	my_pwd = creat_pwd(envp->content);
    }
  else
    {
      if (chdir("/home") == -1)
	(my_printf("Error /home not exist\n"));
      else
	my_pwd = creat_pwd("/home");
    }
  return (my_pwd);
}

t_pwd	*gest_cd(char *link, t_env *envp, t_pwd *my_pwd)
{
  if (link == NULL || my_strcmp("~", link) == 0)
    my_pwd = go_to_home(envp, my_pwd);
  else if (my_strcmp("-", link) == 0)
    {
      free_pwd(my_pwd);
      while (envp != NULL && my_strcmp(envp->name, "OLDPWD") != 0)
	envp = envp->next;
      if (envp != NULL && envp->content != NULL)
	{
	  if ((chdir(envp->content)) == -1)
	    my_printf("Error no OLDPWD\n");
	  else
	    (my_pwd = creat_pwd(envp->content));
	  show_dir(my_pwd);
	  my_putchar('\n');
	}
      else
	if ((chdir("/") == -1))
	  my_printf("Error no / dir\n");
	else
	  (my_pwd = creat_pwd("/"));
    }
  else
    my_printf("Error no suh file or directory\n");
  return (my_pwd);
}

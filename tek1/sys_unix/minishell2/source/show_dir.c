/*
** show_dir.c for show_dir in /home/platel_k/projet/minishell1/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Dec 12 20:07:59 2011 kevin platel
** Last update Tue Feb 28 17:21:31 2012 kevin platel
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "minishell.h"
#include "env.h"
#include "pwd.h"

t_pwd   *change_dir(char *link, t_env **envp, t_pwd *my_pwd)
{
  char	*pwd;

  pwd = NULL;
  if (chdir(link) == -1)
    my_pwd = gest_cd(link, (*envp), my_pwd);
  else
    {
      pwd = pwd_to_char(my_pwd);
      (*envp) = add_new_with_two_arg("OLDPWD", pwd, (*envp));
      if (link[0] == '/')
	{
	  free_pwd(my_pwd);
	  my_pwd = creat_pwd(link);
	}
      else
	my_pwd = update_pwd(link, my_pwd);
    }
  (*envp) = add_new_with_two_arg("PWD", pwd_to_char(my_pwd), (*envp));
  if (pwd != NULL)
    free(pwd);
  return (my_pwd);
}

void	show_dir(t_pwd *my_pwd)
{
  t_pwd	*tmp;

  tmp = my_pwd;
  while (tmp != NULL)
    {
      if (tmp && tmp->prev != NULL && my_strcmp(tmp->prev->name, "/") == 0)
	my_printf("%s", tmp->name);
      else if (my_strcmp(tmp->name, "/") != 0)
	my_printf("/%s", tmp->name);
      else
	my_printf("%s", tmp->name);
      if (tmp)
	tmp = tmp->next;
    }
}

void	free_pwd(t_pwd *my_pwd)
{
  t_pwd	*tmp;

  tmp = NULL;
  if (my_pwd != NULL)
    {
      while (my_pwd != NULL &&  my_pwd->prev != NULL)
	my_pwd = my_pwd->prev;
      while (my_pwd != NULL)
	{
	  if (tmp != NULL)
	    {
	      free(tmp->name);
	      free(tmp);
	    }
	  tmp = my_pwd;
	  my_pwd = my_pwd->next;
	}
      if (tmp != NULL)
	{
	  free(tmp->name);
	  free(tmp);
	}
    }
}

t_pwd	*add_pwd(char *element, t_pwd *my_pwd)
{
  t_pwd	*new;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  new->next = NULL;
  new->prev = my_pwd;
  new->name = my_strdup(element);
  if (my_pwd != NULL)
    my_pwd->next = new;
  return (new);
}

/*
** manag_pwd.c for manag_pwd.c in /home/platel_k/projet/minishell1
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Wed Dec 14 15:32:16 2011 kevin platel
** Last update Mon Feb  6 21:24:47 2012 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "minishell.h"
#include "env.h"

t_pwd	*new_pwd(char *element, t_pwd *my_pwd)
{
  t_pwd	*new;

  new = malloc(sizeof(*new));
  new->prev = NULL;
  new->next = my_pwd;
  new->name = my_strdup(element);
  if (my_pwd != NULL)
    my_pwd->prev = new;
  return (new);
}

t_pwd	*del_one_pwd(t_pwd *pwd)
{
  t_pwd	*tmp;

  tmp = pwd;
  if (tmp != NULL)
    {
      pwd->prev != NULL ? (pwd = pwd->prev) : (pwd = pwd->next);
      if (pwd == NULL)
	pwd = new_pwd("/", pwd);
      else
	pwd->next = NULL;
      free(tmp->name);
      free(tmp);
    }
  return (pwd);
}

t_pwd	*creat_pwd(char *link)
{
  char	**tab;
  t_pwd	*my_pwd;
  int	i;

  i = 0;
  my_pwd = NULL;
  tab = my_link_wordtab(link);
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	i++;
      i--;
      while (i >= 0)
	{
	  my_pwd = new_pwd(tab[i], my_pwd);
	  i--;
	}
      my_pwd = new_pwd("/", my_pwd);
    }
  tab = freewordtab(tab);
  if (tab != NULL)
    free(tab);
  return (my_pwd);
}

t_pwd   *update_pwd(char *link, t_pwd *my_pwd)
{
  char	**tab;
  int	i;

  tab = my_link_wordtab(link);
  i = 0;
  while (my_pwd != NULL && my_pwd->next != NULL)
    my_pwd = my_pwd->next;
  while (tab[i] != NULL)
    {
      if (my_strcmp(tab[i], "..") == 0)
	my_pwd = del_one_pwd(my_pwd);
      else if (my_strcmp(tab[i], ".") != 0)
	my_pwd = add_pwd(tab[i], my_pwd);
      i++;
    }
  while (my_pwd != NULL && my_pwd->prev != NULL)
    my_pwd = my_pwd->prev;
  tab = freewordtab(tab);
  if (tab != NULL)
    free(tab);
  return (my_pwd);
}

char	*pwd_to_char(t_pwd *my_pwd)
{
  t_pwd	*tmp;
  int	lenght;
  char	*char_pwd;

  char_pwd = NULL;
  lenght = 0;
  tmp = my_pwd;
  while (tmp != NULL)
    {
      lenght += (my_strlen(tmp->name) + 1);
      tmp = tmp->next;
    }
  char_pwd = malloc((lenght + 1) * sizeof(char));
  char_pwd[0] = '\0';
  while (my_pwd != NULL)
    {
      char_pwd = my_strcat(char_pwd, my_pwd->name);
      char_pwd = my_strcat(char_pwd, "/");
      my_pwd = my_pwd->next;
    }
  return (char_pwd);
}

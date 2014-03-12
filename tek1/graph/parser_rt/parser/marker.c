/*
** balise.c for balise in /home/ozouf_h//projet/rtv1/parser/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Tue Feb 14 16:13:32 2012 harold ozouf
** Last update Tue May  1 11:36:39 2012 kevin platel
*/

#include	<stdlib.h>
#include	"xfnt.h"
#include	"str.h"
#include	"aff.h"
#include	"marker.h"

int	get_size_next_marker(char *xml)
{
  int	i;
  int	j;
  int	n;

  i = 0;
  j = 0;
  n = 0;
  while (xml[i] != '\0')
    {
      if (i > 0 && xml[i - 1] == '<' && xml[i] != '/')
	n = 1;
      if (xml[i] == '>' && n == 1)
	if (j > 0)
	  return (j);
      if (n == 1)
	j++;
      i++;
    }
  return (-1);
}

int	get_next_marker(char **xml, char **name)
{
  int	i;
  int	j;
  int	n;

  i = 0;
  j = 0;
  n = 0;
  while ((*xml)[i] != '\0')
    {
      if (i > 0 && (*xml)[i - 1] == '<' && (*xml)[i] != '/')
	n = 1;
      if ((*xml)[i] == '>' && n == 1)
	if (j > 0)
	  {
	    *xml += i + 1;
	    return ((*name)[j] = '\0');
	  }
      if (n == 1)
	(*name)[j++] = (*xml)[i];
      i++;
    }
  return (-1);
}

int	get_end_marker(char **xml, char *name)
{
  int	i;
  char	*tmp;

  tmp = *xml;
  i = 0;
  while (*tmp)
    {
      if (tmp[0] == MARKER_PRE && tmp[1] && tmp[1] == MARKER_END)
	{
	  tmp += 2;
	  i += 2;
	  if (my_strncmp(name, tmp, my_first_strlen(name)) == 0)
	    {
	      while (tmp && *tmp != MARKER_SUF)
		tmp++;
	      if (*tmp == MARKER_SUF)
		return (i - 2);
	    }
	}
      tmp++;
      i++;
    }
  my_putchar('"');
  my_putstr(name);
  my_putchar('"');
  xexit("Error: missing marker\n");
  return (i);
}

int	delete_marker(char **xml, char *name)
{
  int	done;

  done = 0;
  while (**xml && done == 0)
    {
      if ((*xml)[1] != '\0' && (*xml)[0] == MARKER_PRE &&
	  (*xml)[1] == MARKER_END)
	{
	  *xml += 2;
	  if (my_strncmp(name, *xml, my_strlen(name)) == 0)
	    {
	      *xml += my_strlen(name);
	      if (**xml != '\0' && **xml == MARKER_SUF)
		{
		  *xml += 1;
		  done = 1;
		}
	    }
	}
      *xml += 1;
    }
  return (0);
}

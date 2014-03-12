/*
** edit_keyword.c for 42sh in /home/leprov_a//depot/42sh/src/edit
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Apr 25 11:01:48 2012 alexis leprovost
** Last update Sat May 19 11:14:33 2012 alexis leprovost
*/

#include	"xsys.h"
#include	"edit.h"
#include	"my.h"

void	edit_keyword(char **tab)
{
  tab[0] = DELETE_EDIT_STRING;
  tab[1] = LEFT_EDIT_STRING;
  tab[2] = RIGHT_EDIT_STRING;
  tab[3] = UP_EDIT_STRING;
  tab[4] = DOWN_EDIT_STRING;
  tab[5] = SUPPR_EDIT_STRING;
  tab[6] = CLEAR_EDIT_STRING;
  tab[7] = START_EDIT_STRING;
  tab[8] = END_EDIT_STRING;
  tab[9] = CTRLB_EDIT_STRING;
  tab[10] = CTRLF_EDIT_STRING;
  tab[11] = CTRLH_EDIT_STRING;
  tab[12] = CTRLP_EDIT_STRING;
  tab[13] = CTRLT_EDIT_STRING;
  tab[14] = CTRLU_EDIT_STRING;
  tab[15] = CTRLK_EDIT_STRING;
  tab[16] = CTRLW_EDIT_STRING;
  tab[17] = CTRLY_EDIT_STRING;
  tab[18] = CTRLX_EDIT_STRING;
  tab[19] = CTRLFG_EDIT_STRING;
  tab[20] = CTRLFD_EDIT_STRING;
  tab[21] = TAB_EDIT_STRING;
  tab[22] = CTRLR_EDIT_STRING;
  tab[MAX_EDIT_KEYWORD_NUMBER - 1] = NULL;
}

int	edit_iskeyword(char *str, char **keyword)
{
  int	i;

  i = -1;
  if (keyword == NULL)
    return (MAX_EDIT_KEYWORD_NUMBER - 1);
  while (keyword[++i])
    if (!my_strncmp(keyword[i], str, (my_strlen(keyword[i]) - 1)))
      return (i);
  return (i);
}

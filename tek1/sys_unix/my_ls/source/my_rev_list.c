/*
** my_rev_list.c for my_rev_list in /home/platel_k/projet/my_ls/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Nov 23 12:25:11 2011 kevin platel
** Last update Wed Nov 23 12:28:06 2011 kevin platel
*/

void		my_rev_list(t_data **begin)
{
  t_data	*tmp;
  t_data	*tmp2;

  while ((*begin)->next != NULL)
    {
      tmp = (*begin);
      (*begin) = (*begin)->next;
      tmp2 = tmp->prev;
      tmp->prev = tmp->next;
      tmp->next = tmp2;
    }
}

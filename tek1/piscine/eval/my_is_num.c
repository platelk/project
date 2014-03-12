/*
** is_nume.c for Is_num in /home/platel_k//projet/piscine/eval
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Oct 28 11:32:31 2011 kevin platel
** Last update Fri Oct 28 14:23:14 2011 kevin platel
*/

int	my_is_num(char c)
{
  if ((c <= '9') && (c >= '0'))
    return (0);
  return (1);
}

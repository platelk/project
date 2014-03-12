/*
** isalpha.c for isalpha in /home/platel_k/lib/c
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sun Nov 20 11:28:26 2011 kevin platel
** Last update Thu Dec  1 09:43:31 2011 kevin platel
*/

int	my_is_alpha(char c)
{
  if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
    return (1);
  return (0);
}

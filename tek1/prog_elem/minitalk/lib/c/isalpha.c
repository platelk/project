/*
** isalpha.c for isalpha in /home/platel_k/lib/c
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sun Nov 20 11:28:26 2011 kevin platel
** Last update Wed Nov 23 10:48:48 2011 kevin platel
*/

int	is_alpha(char c)
{
  if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
    return (1);
  return (0);
}

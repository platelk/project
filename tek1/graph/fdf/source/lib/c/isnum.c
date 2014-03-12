/*
** isnum.c for isnum in /home/platel_k/lib/c
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sun Nov 20 11:16:28 2011 kevin platel
** Last update Sun Nov 20 11:24:45 2011 kevin platel
*/

int	isnum(char c)
{
  if (c > '9' || c < '0')
    return (1);
  return (0);
}

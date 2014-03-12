/*
** main.c for Sapin in /home/platel_k//projet/piscine/sapin
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sat Oct  8 17:46:01 2011 kevin platel
** Last update Mon Feb 20 11:33:45 2012 kevin platel
*/
void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	main()
{
  int size;

  size = -1;
  sapin2(size);
}

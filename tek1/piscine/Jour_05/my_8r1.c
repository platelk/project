/*
** my_8r1.c for my_8r1 in /home/platel_k//projet/piscine/Jour_05
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Oct  7 18:11:53 2011 kevin platel
** Last update Fri Oct  7 22:17:16 2011 kevin platel
*/
int	init(char tab[][8], int x, int y)
{
  while (x < 8)
    {
      while (y < 8)
	{
	  tab[x][y] = 0;
	  y = y +1;
	}
      y = 0;
      x = x + 1;
    }
}

char	add_queen(char tab[][8], int queen)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (x < 8)
    {
      while (y < 8)
        {
	  if (tab[x][y] == 0)
	    {
	      tab[x][y] = 1;
	    }
          y = y +1;
        }
      y = 0;
      x = x + 1;
    }
  if (queen == 1)
    return (0);
  return (add_queen(tab, queen - 1));
}

int	my_8r1()
{
  char	chessboard[8][8];
  char	x;
  char	y;

  x = 0;
  y = 0;
  init(chessboard, x, y);
  add_queen(chessboard, 8);
}

/*
** sapin2.c for Sapin in /home/platel_k//projet/piscine/sapin
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sun Oct  9 10:33:00 2011 kevin platel
** Last update Sun Oct  9 20:00:24 2011 kevin platel
*/
int	space(int size, int line, int spa, int floor)
{
  if (spa >= ((size / 2) - 1) - (line / 2))
      return (0);
  my_putchar(' ');
  return (space(size, line, spa + 1, floor));
}

int	star(int tot_star, int sta, char c)
{
  if ( sta > tot_star)
    return (0);
  my_putchar(c);
  return (star(tot_star, sta + 1, c));
}

int	add_floor(int floor, int line, int size, int old_line)
{
  if ((floor + 4) < line)
    return (old_line + line);
  space(size, old_line - (floor + 1)/2 + (line * 2) - 1, 1, floor);
  star((old_line - (floor + 1)/2 + (line * 2)) - 1, 1, '*');
  my_putchar('\n');
  return (add_floor(floor, line + 1, size, old_line));
}

int	calc_c(int size,int floor)
{
  int	tot_c;
  int	line;

  line = 0;
  tot_c = 4;
  while (floor != size)
    {
      tot_c = tot_c + (3 + (floor + 1)/2);
      floor = floor + 1;
    }
  while (tot_c >= 0)
    {
      line = line + 2;
      tot_c = tot_c - 1;
    }
  return (line);
}

void	sapin2(int size)
{
  int	floor;
  int	line;
  int	old_line;

  floor = 0;
  old_line = 0;
      
  line = size;
  size = calc_c(size, floor);
  while (floor <= line)
    {
      old_line = add_floor(floor, 1, size, old_line);
      floor = floor + 1;
    }
  floor = 0;
  while (line > floor)
    {
      space(size , ((line/2) * 2), 1, 1);
      star(1 + (line/2 * 2) , 1, '|');
      my_putchar('\n');
      floor = floor + 1;
    }
}

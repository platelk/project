/*
** colle5.c for Colle2-5 in /home/platel_k//projet/piscine/colle2/colle5
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sat Oct 15 16:28:05 2011 kevin platel
** Last update Sat Oct 15 17:32:30 2011 kevin platel
*/
void	display(int pos_ball, int pos_text, char *str)
{
  int	i;

  i = 0;
  my_putchar('\r');
  while (i != pos_ball)
    {
      my_putchar(' ');
      i = i + 1;
    }
  my_putchar('*');
  i = i + 1;
  while (i != pos_text)
    {
      my_putchar(' ');
      i = i + 1;
    }
  my_putstr(str);
}

void    rev_display(int pos_ball, int pos_text, char *str)
{
  int   i;

  i = 0;
  my_putchar('\r');
  while (i != pos_text)
    {
      my_putchar(' ');
      i = i + 1;
    }
  my_putstr(str);
  i = i + 1;
  while (i != pos_ball)
    {
      my_putchar(' ');
      i = i + 1;
    }
  my_putchar('*');
}

int	main(int argc, char **argv)
{
  int	i;
  int pos_ball;
  int pos_text;
  int direction;
  char	*str;

  str = "salut";
  direction = 1;
  pos_ball = 0;
  pos_text = 1;
  i = 0;
  while (1)
    {
      display(pos_ball, pos_text, "salut");
      pos_ball = pos_ball + direction;
      if (pos_ball == pos_text)
	{
	  direction = direction * (-1);
	  pos_text = pos_text + 1;
	}
      if (pos_ball == 0 || pos_ball == 20)
	direction = direction * (-1);
      if (pos_ball + my_strlen(str) > 20)
	{
	  pos_ball = 20;
	  direction = -1;
	}
      usleep(1000);
    }
}

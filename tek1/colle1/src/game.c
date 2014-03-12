/*
** game.c for game in /home/vink/projet/colle/src
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Apr 19 14:22:52 2012 kevin platel
** Last update Thu Apr 19 16:44:23 2012 kevin platel
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"master.h"

int	is_instr(char c, char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	return (EXIT_SUCCESS);
      i++;
    }
  return (EXIT_FAILURE);
}

int	is_inpion(char *pion, char *enter)
{
  int	i;

  i = 0;
  while (enter[i])
    {
      if (is_instr(enter[i], pion) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      i++;
    }
  return (EXIT_SUCCESS);
}

void	print_placement(int good, int bad)
{
  my_putstr("\nPions bien places : ");
  my_putnbr(good);
  my_putstr("\nPions mal places : ");
  my_putnbr(bad);
  my_putstr("\n");
}

int	is_solution(char *sol, char *test, char *pion, int slot)
{
  int	good;
  int	bad;
  int	i;

  i = 0;
  good = 0;
  bad = 0;
  if (my_strlen(sol) != my_strlen(test))
    print_len_err(slot);
  while (sol[i] && test[i])
    {
      if (is_instr(test[i], pion) == EXIT_FAILURE)
	return (put_error_pion(test[i]));
      if (test[i] == sol[i])
	good++;
      else if (is_instr(test[i], sol) == EXIT_SUCCESS)
	bad++;
      i++;
    }
  if (good == my_strlen(sol))
    return (1);
  print_placement(good, bad);
  return (0);
}

int	game(char *code, char *pion, int tentative, int slot)
{
  int	win;
  int	round;
  char	buffer[24];
  int	len;

  if (check_game(code, pion, slot, tentative) == 1)
    return (1);
  my_putstr("Trouverez-vous le code secret ?\n");
  round = 1;
  win = 0;
  while (tentative >= round && win != 1)
    {
      my_putstr("---\n");
      write(1, "Round ", 6);
      my_putnbr(round);
      write(1, "\n>", 1);
      len = read(0, buffer, 23);
      buffer[len - 1] = 0;
      win = is_solution(code, buffer, pion, slot);
      round++;
    }
  win_msg(round - 1, win, code);
  free(code);
  free(pion);
  return (0);
}

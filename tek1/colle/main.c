typedef struct mdr
{
  double	a;
} t_b;

typedef struct lol
{
  t_b a;
} t_lol;

int	main(int ac, char **av)
{
  int	tab[3][3];
  t_lol	x;

  x.a.a = 0.1f;
  printf("valeur de a = %f\n", x.a.a);
  x.a.a = x.a.a + 0.1f;
  printf("valeur de a + 0.1 = %f\n", x.a.a);

  return (0);
}

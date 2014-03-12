/*
** Epitech Security Lab
** http://esl.epitech.net - <staff@esl.epitech.eu>
**
** Djo wrote this.
** As long as you retain this notice you can do whatever
** you want with this stuff. If we meet some day, and you
** think this stuff is worth it, you can buy me a Chimay
** blue in return.
*/

#ifndef           __RECIPES_H__
# define          __RECIPES_H__

# define Recipe_MDMA    0
# define Recipe_Whisky  1
# define Recipe_Cum     2
# define Recipe_LSD     3
# define Secret_Recipe  4

# define MDMA           0
# define WHISKY         1
# define CUM            2
# define LSD            3
# define CHOCOLATE      4
# define FLOUR          5

/* tableau de structure des recettes */
typedef struct    s_recipes
{
  char            *name;          /* nom de la recette */
  int             quantity;       /* nombre de recette faite */
}                 t_recipes;

typedef struct    s_stock
{
  char            *name;
  int             quantity;
}                 t_stock;

#endif     /* !__RECIPES_H__ */

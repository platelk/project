/*
** obj_create_object.c for obj in /home/vink/projet/graph/xml/obj_src
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Mon May  7 15:14:23 2012 kevin platel
** Last update Tue May  8 13:49:44 2012 kevin platel
*/

void		*obj_bzero_dim(double *tab)
{
  tab[X] = 0.0;
  tab[Y] = 0.0;
  tab[Z] = 0.0;
}

t_object	*obj_init_dimension(t_xtree *tmp, t_object *new)
{
  if ((tmp = xml_find_in_tree(tree, STRING_LOC)) != NULL)
    {
      new->position[X] = my_getnbr(xml_find_attr(tmp->attr, STRING_X));
      new->position[Y] = my_getnbr(xml_find_attr(tmp->attr, STRING_Y));
      new->position[Z] = my_getnbr(xml_find_attr(tmp->attr, STRING_Z));
    }
  else
    obj_bzero_dim(new->position);
  if ((tmp = xml_find_in_tree(tree, STRING_ROT)) != NULL)
    {
      new->rotation[X] = my_getnbr(xml_find_attr(tmp->attr, STRING_X));
      new->rotation[Y] = my_getnbr(xml_find_attr(tmp->attr, STRING_Y));
      new->rotation[Z] = my_getnbr(xml_find_attr(tmp->attr, STRING_Z));
    }
  else
    obj_bzero_dim(new->rotation);
  if ((tmp = xml_find_in_tree(tree, STRING_PER)) != NULL)
    {
      new->perturbation[X] = my_getnbr(xml_find_attr(tmp->attr, STRING_X));
      new->perturbation[Y] = my_getnbr(xml_find_attr(tmp->attr, STRING_Y));
      new->perturbation[Z] = my_getnbr(xml_find_attr(tmp->attr, STRING_Z));
    }
  else
    obj_bzero_dim(new->perturbation);
  return (new);
}

t_object	*obj_add_object(t_xtree *tree, t_object *obj)
{
  t_object	*new;
  t_xtree	*tmp;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  new = obj_init_dimension(tree, new);
  new->type = (t_type) obj_get_type(tree->name);
  if (new->type < 0)
    return (NULL);
  tmp = xml_find_in_tree(tree, STRING_COL);
  new->color = my_getnbr(tmp->content);
  new->next = NULL;
  new->prev = obj;
  if (obj)
    obj->next = new;
  return (new);
}

t_object	*obj_create_list_object(t_xtree *tree)
{
  t_object	*obj;
  t_object	*tmp;

  tree = xml_find_in_tree(tree, STRING_OBJ);
  if (tree == NULL)
    return (NULL);
  tree = tree->sun;
  if (tree == NULL)
    return (NULL);
  obj = obj_add_object(tree, obj);
  tree = tree->next;
  tmp = obj;
  while (tree)
    {
      tmp = obj_add_object(tree, tmp);
      tree = tree->next;
    }
  return (obj);
}

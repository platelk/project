/*
** main.c for unit_test in /home/guiho_r/tek1/42sh/src/stack_exec/unit_test
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Apr 12 10:40:00 2012 ronan guiho
** Last update Wed Apr 18 20:12:19 2012 ronan guiho
*/

#include <stdlib.h>

#include "env.h"
#include "node.h"
#include "child.h"
#include "execute.h"

void		display_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    printf("Tab[%d]=%s\n", i, tab[i++]);
}

void		fill_child(t_child **list, char *str)
{
  t_child	*tmp;
  t_child	*ptr;
  t_node	*ptr1;

  tmp = *list;
  ptr = malloc(sizeof(*ptr));
  ptr1 = malloc(sizeof(*ptr1));
  ptr1->id = ARG;
  ptr1->content = my_strdup(str);
  ptr1->child = NULL;
  ptr->nd = ptr1;
  ptr->next = NULL;
  if (*list == NULL)
    *list = ptr;
  else
    {
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = ptr;
    }
}

t_node		*create_command(char *str)
{
  int		i;
  char		**tab;
  t_node	*master_node;
  t_child	*list_child;

  i = 0;
  tab = my_strtok(str, " ", TOK_DELIM);
  master_node = malloc(sizeof(*master_node));
  master_node->content = my_strdup(tab[i++]);
  master_node->id = CMD;
  list_child = NULL;
  while (tab[i])
    {
      fill_child(&list_child, tab[i]);
      i++;
    }
  master_node->child = list_child;
  return (master_node);
}

int		test_execute(char *str)
{
  int		i;
  char		**tab;
  t_node	*master_node;
  t_child	*list_child;
  t_env		*env;

  i = 0;
  env = malloc(sizeof(*env));
  env->name = my_strdup("PATH");
  env->value = my_strdup("/usr/lib64/ccache:/usr/sbin:/usr/bin:/sbin:/bin:/usr/school/sbin:/usr/school/bin:/usr/netsoul/sbin:/usr/netsoul/bin:/usr/kerberos/sbin:/usr/kerberos/bin:/usr/local/sbin:/usr/local/bin:/home/guiho_r/go/bin");
  env->next = NULL;
  env->prev = NULL;
  tab = my_strtok(str, " ", TOK_DELIM);
  master_node = malloc(sizeof(*master_node));
  master_node->content = my_strdup(tab[i++]);
  list_child = NULL;
  while (tab[i])
    {
      fill_child(&list_child, tab[i]);
      i++;
    }
  master_node->child = list_child;
  int state;
  pid_t pid;
  pid = fork();
  if (pid == 0)
    {
      exec_command(master_node, env);
      exit (1);
    }
  else
    wait(&state);
}

int		test_pipe(char *command)
{
  char		**tab;
  t_env		*env;

  env = malloc(sizeof(*env));
  env->name = my_strdup("PATH");
  env->value = my_strdup("/usr/lib64/ccache:/usr/sbin:/usr/bin:/sbin:/bin:/usr/school/sbin:/usr/school/bin:/usr/netsoul/sbin:/usr/netsoul/bin:/usr/kerberos/sbin:/usr/kerberos/bin:/usr/local/sbin:/usr/local/bin:/home/guiho_r/go/bin");
  env->next = NULL;
  env->prev = NULL;
  tab = my_strtok(command, "|", TOK_DELIM);
  int i = 0;
  while (tab[i])
    i++;
  if (i == 2)
    {
      t_node	*master;
      t_node	*ptr1;
      t_node	*ptr2;
      t_child	*child1;
      t_child	*child2;

      master = malloc(sizeof(*master));
      ptr1 = create_command(tab[0]);
      ptr2 = create_command(tab[1]);
      child1 = malloc(sizeof(*child1));
      child2 = malloc(sizeof(*child2));
      child1->next = child2;
      child2->next = NULL;
      child1->nd = ptr1;
      child2->nd = ptr2;
      master->child = child1;
      master->id = PIPE;
      if ((exec_pipe(master, env)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else
    {
      my_putstr("HAHHA\n");
    }
}

int		test_redirection(char *command)
{
  char		**tab;
  t_node	*ptr;
  t_child	*ptr1;
  t_child	*ptr2;
  t_node	*cmd1;
  t_node	*cmd2;
  enum e_token	flag;
  int		i;
  t_env		*env;
  int		flag1;

  i = 0;
  flag1 = 0;
  while (command[i] && flag1 == 0)
    {
      if (command[i] != '\0')
	{
	  if (command[i] == '>' && command[i + 1] == '>')
	    {
	      flag = D_RED_RIGHT;
	      flag1 = 1;
	    }
	  else if (command[i] == '<' && command[i + 1] == '<')
	    {
	      flag = D_RED_LEFT;
	      flag1 = 1;
	    }
	  else if (command[i] == '>' && command[i + 1] != '>')
	    {
	      flag = S_RED_RIGHT;
	      flag1 = 1;
	    }
	  else if (command[i] == '<' && command[i + 1] != '<')
	    {
	      flag = S_RED_LEFT;
	      flag1 = 1;
	    }
	}
      i++;
    }
  tab = my_strtok(command, "<>", TOK_DELIM);
  cmd1 = create_command(tab[0]);
  cmd2 = create_command(tab[1]);
  ptr1 = malloc(sizeof(*ptr1));
  ptr2 = malloc(sizeof(*ptr2));
  ptr = malloc(sizeof(*ptr));
  ptr1->nd = cmd1;
  ptr2->nd = cmd2;
  ptr1->next = ptr2;
  ptr2->next = NULL;
  ptr->child = ptr1;
  ptr->id = flag;
  env = malloc(sizeof(*env));
  env->name = my_strdup("PATH");
  env->value = my_strdup("/usr/lib64/ccache:/usr/sbin:/usr/bin:/sbin:/bin:/usr/school/sbin:/usr/school/bin:/usr/netsoul/sbin:/usr/netsoul/bin:/usr/kerberos/sbin:/usr/kerberos/bin:/usr/local/sbin:/usr/local/bin:/home/guiho_r/go/bin");
  env->next = NULL;
  env->prev = NULL;
  exec_redirection(ptr, env, flag);
}


int	check_redirection_pipe(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '>' || str[i] == '<')
	return (1);
      if (str[i] == '|')
	return (2);
      i++;
    }
  return (0);
}

int		test_multi_pipe()
{
  t_node	*cmd1;
  t_node	*cmd2;
  t_node	*cmd3;
  t_node	*cmd4;
  t_node	*pipe1;
  t_node	*pipe2;
  t_node	*pipe3;
  t_env		*env;

  /* ========== ENVIRONEMENT ====== */

  env = malloc(sizeof(*env));
  env->name = my_strdup("PATH");
  env->value = my_strdup("/usr/lib64/ccache:/usr/sbin:/usr/bin:/sbin:/bin:/usr/school/sbin:/usr/school/bin:/usr/netsoul/sbin:/usr/netsoul/bin:/usr/kerberos/sbin:/usr/kerberos/bin:/usr/local/sbin:/usr/local/bin:/home/guiho_r/go/bin");
  env->next = NULL;
  env->prev = NULL;

  /* ============================== */

  cmd1 = create_command("ls -la");
  cmd2 = create_command("grep s --color");
  cmd3 = create_command("grep r --color");
  cmd4 = create_command("grep src --color");
  pipe1 = malloc(sizeof(*pipe1));
  pipe1->id = PIPE;
  pipe2 = malloc(sizeof(*pipe2));
  pipe2->id = PIPE;
  pipe3 = malloc(sizeof(*pipe3));
  pipe3->id = PIPE;

  /* ================================= */

  t_child	*child1;
  t_child	*child2;

  child1 = malloc(sizeof(*child1));
  child2 = malloc(sizeof(*child2));
  child1->nd = cmd1;
  child1->next = child2;
  child2->next = NULL;
  child2->nd = pipe2;
  pipe1->child = child1;

  /* ================================= */

  t_child	*child3;
  t_child	*child4;

  child3 = malloc(sizeof(*child3));
  child4 = malloc(sizeof(*child4));
  child3->nd = cmd2;
  child3->next = child4;
  child4->next = NULL;
  child4->nd = pipe3;
  pipe2->child = child3;

  /* =============================== */

  t_child	*child5;
  t_child	*child6;

  child5 = malloc(sizeof(*child5));
  child6 = malloc(sizeof(*child6));
  child5->nd = cmd3;
  child5->next = child6;
  child6->nd = cmd4;
  child6->next = NULL;
  pipe3->child = child5;
  exec_pipe(pipe1, env);
}

/*int	main(int ac, char **av)
{
  test_multi_pipe();
  }*/

/*int	main(int ac, char **av)
{
  t_env		*env;
  t_node	*root;
  char		buffer[1024];

  env = malloc(sizeof(*env));
  env->name = my_strdup("PATH");
  env->value = my_strdup("/usr/lib64/ccache:/usr/sbin:/usr/bin:/sbin:/bin:/usr/school/sbin:/usr/school/bin:/usr/netsoul/sbin:/usr/netsoul/bin:/usr/kerberos/sbin:/usr/kerberos/bin:/usr/local/sbin:/usr/local/bin:/home/guiho_r/go/bin");
  env->next = NULL;
  env->prev = NULL;
  while (42)
    {
      buffer[read(0, buffer, 1024) - 1] = '\0';
      //root = parsing_main(buffer);
      exec_command(root, env);
    }
}*/

int		main(int ac, char **av)
{
  char		*cmd;
  t_env		*env;
  t_node	*root;

  env = malloc(sizeof(*env));
  env->name = my_strdup("PATH");
  env->value = my_strdup("/usr/lib64/ccache:/usr/sbin:/usr/bin:/sbin:/bin:/usr/school/sbin:/usr/school/bin:/usr/netsoul/sbin:/usr/netsoul/bin:/usr/kerberos/sbin:/usr/kerberos/bin:/usr/local/sbin:/usr/local/bin:/home/guiho_r/go/bin");
  env->next = NULL;
  env->prev = NULL;
  while (42)
    {
      cmd = get_next_line(0);
      root = parsing_func(cmd);
      printf("Command : %s\n", cmd);
      exec_course_tree(root, env);
      printf("End->course_tree\n");
      free(cmd);
    }
}


 /*int	main(int ac, char **av)
{
  char	*buffer;
  pid_t	pid;
  int	state;

  while (42)
    {
      my_putstr("$> ");
      buffer = malloc(sizeof(*buffer));
      buffer[read(0, buffer, 1024) - 1] = '\0';
      pid = fork();
      if (pid == 0)
	{
	  if (check_redirection_pipe(buffer) == 1)
	    test_redirection(buffer);
	  else if (check_redirection_pipe(buffer) == 2)
	    test_pipe(buffer);
	  else
	    test_execute(buffer);
	}
      else
	wait(&state);
      free(buffer);
    }
}
 */

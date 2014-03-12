/*
** corewar.h for corewar in /home/platel_k/projet/prog_elem/corewar/corewar
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Jan 24 14:51:20 2012 kevin platel
** Last update Sun Mar 25 22:48:42 2012 ronan guiho
*/

#ifndef __COREWAR__
#define __COREWAR__

#include "label.h"
#include "instruction.h"
#include "my.h"
#include "op.h"

#define	EXTEND	1
#define MAX	42

typedef union u_str_int
{
  int	value;
  char	str[3];
} t_str_int;

int     unknow_mnemo(op_t *mnemo, t_instruction *buff_instruct,
                     t_label *buffer);
int	asm_treatment(char *str);
int	check_file(char *str);
int     magic(int nbr);
header_t	*get_header(int *flag, int fd, int *l);
int	get_name(int fd, header_t *header, int *l);
int	get_comment(int fd, header_t *header, int *l);
int	get_extend(int *flag, int fd, int *l);
int	get_char_param(int fd, t_instruction *instruct);
int     find_errors(t_label *list);
int     unknow_mnemo(op_t *mnemo, t_instruction *buff_instruct,
                     t_label *buffer);
int	is_not_label(char *str, int fd);
int	create_file(char *name);
int	calc_dist(int dir, t_instruction *instruct, t_label *label, char *line);
int	get_direction_search(char *label, t_instruction *instruct);

t_instruction	*creat_list_instruct(int fd, t_label *label, int *l);
t_instruction	*creat_one_inst(char *s, t_instruction *inst,
				t_label *label, int l);
t_label	*creat_one_label(char *buffer, int fd, t_label *label, int *l);
t_label *creat_list_label(int fd, int *l);
t_label	*get_list_label(int fd, int *l);

void    print_error_message(char *message, char *label, char *mnemo, int l);

char	**get_name_label(char *buffer, int fd);
char	*int_to_str(int nbr);
char	*get_type_param(char *line);
char	*write_valu(t_instruction *instruct, char *line, char *param);
char	*get_addr_label(t_instruction *instruct, char *line, char *param);
char    *calcul_label(char *s, t_label *list, t_instruction *inst, char *p);
char	**get_param(char **line, t_instruction *instruct);
char	*get_type_param(char *line);
char	*modify_extension(char *name);
char    *cast_param(char id_mnemo, char *name, int position, int *len);
char	*write_int_in_str(int value, char *param);
char	get_hex_instruct(int fd, t_instruction *instruct);
char	*jump_comment(int fd, int *l);

int	write_file(t_label *list, char *name, header_t *header);
int	write_header(int fd, header_t *header, t_label *list);
int	write_instruction(int fd, t_label *list);
int	write_argument(int fd, t_instruction *instruct, char id_name);
int	octets_from_type(char type);
int	change_label_by_value(t_label *label, int flag);
int	octets_mnemo(int type, char arg_get, int id, int pos);
int     is_stop_condition(char c);
int     check_label_name(char *name, t_label *list);

#endif

/*
** corewar.h for corewar in /home/platel_k/projet/prog_elem/corewar/corewar
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Jan 24 14:51:20 2012 kevin platel
** Last update Sun Mar 25 21:28:23 2012 alexis leprovost
*/

#ifndef __COREWAR__
#define __COREWAR__

#include "sound.h"
#include "my.h"
#include "op.h"
#include "champ.h"
#include "data_champ.h"
#include "param.h"
#include "mem.h"
#include "vm.h"
#include "mnemos.h"
#include "ptr_func.h"

#define	EXTEND	1
#define MAX	42

typedef union u_str_int
{
  int	value;
  char	str[3];
} t_str_int;

void		key_battel_ground(t_vm *vm);
void		hello_sound(SDL_Event event, t_sound **sound_tab);
void		display_die(t_vm *vm);
void		*thread_projector(void *ptr);
int		filter_img(SDL_Surface *sc, int *op);
void		set_pixel(SDL_Surface *sc, int x, int y, Uint32 pixel);
Uint32		get_pixel(SDL_Surface *sc, int x, int y);
void		fill_filter_img(SDL_Surface *sc, int *value,
				Uint8 *color, int *op);
void		treatement_sound_project(t_vm *vm, int *op, FMOD_CHANNEL *ch);
float		average_float(float *p);
Uint8		add_value(Uint8 compo, int value);
int		is_number(char *str);
int		mem_dump(t_mem *mem);
int		display_msg(t_vm *vm);
void		display_credit(t_vm *vm);
void		display_card_all(t_vm *vm);
void		display_charact_left(t_vm *vm);
void		display_charact_center(t_vm *vm);
void		display_text(t_vm *vm);
int		disp_live_action(t_vm *vm);
void		*thread_projector(void *vm);
void		aff_mem(t_vm *vm);
t_sound		**init_sound();
int		disp_actif_mem(t_vm *vm, t_mem *ptr);
int		disp_write_mem(t_vm *vm, t_mem *ptr);
int		disp_read_mem(t_vm *vm, t_mem *ptr);
int		disp_live_mem(t_vm *vm, t_mem *ptr);
void		display_environ(t_vm *vm);
int		create_disp_mem(t_vm *vm);
int		display_decompt(t_vm *vm, TTF_Font *police);
void		display_all(t_vm *vm, int flag);
void		display_chair(t_vm *vm);
void		display_desk(t_vm *vm);
void		display_charact(t_vm *vm);
int		rendering(t_vm *vm);
t_image		**init_image();
int		display_animation(SDL_Surface *sc, t_image **image);
t_image		*init_image_el(char *path, int size);
int		display_menu(SDL_Surface *sc, t_image *image_tab,
			     t_sound **sound_tab);
void		sub_champ(t_champ **champ, int	nb_champ);
char		*my_strcpy(char *dest, char *src);
char		*my_strcat(char *dest, char *src);
char		*my_str_concat(char *dest, char *str);
t_sound		*init_sound_event(char *path);
t_sound		*init_sound_amb(char *path);
int		my_strlen(char *str);
char		*my_revstr(char *str);
char		*my_getstr(int nb, char *base);
t_data_champ	*treatment_data_champ(int ac, char **av, t_param *param);
t_champ		*treatment_champ(t_data_champ *data);
t_data_champ    *treatment_data_champ(int ac, char **av, t_param *param);
t_vm		*create_struct_vm(int ac, char **av);
int		create_list_data_champ(t_data_champ **list, char **av, int indice);
int		create_struct_param(char **av, int *indice, t_param *param);
int	        create_list_champ(t_champ **champ, t_data_champ *data);
int	create_list_mem(t_mem **begin, int flag, int indice);
int	create_struct_param(char **av, int *indice, t_param *param);
int	create_list_data_champ(t_data_champ **list, char **av, int indice);
int     fill_struct_champ(t_champ *champ, t_data_champ *data);
int     *dump_reg(t_param *param, int id);
int	*fill_data(t_data_champ *data_champ);
t_mem	*dump_mem(t_param *param);
void	sort_champ(t_champ **begin, int limit);
void	swap_champ(t_champ **champ, t_champ **begin);
int     get_rand_number(int max);
int     get_data_champ(t_data_champ *ptr, char **av, int indice);
int     get_bin(t_champ *champ, char *str);
int     get_size_bin(int fd, t_champ *champ);
int	get_id_available(t_champ *champ);
int	get_addr_available(t_champ *champ, int nb);
int	get_champ_number(t_champ *champ);
t_champ	*get_champ_min(t_champ *champ);
int     check_args(int ac, char **av);
int	check_value_champ(int value, t_champ *champ, int flag);
int	check_champ(t_champ *champ, t_param *param);
int	clean_game(t_champ *champ);
int	battle_ground(t_vm *vm, func *instruct);
t_champ	*search_champ(t_champ *champ, int nb_champ, int flag);
void	free_data_champ(t_data_champ *data);
void	free_vm(t_vm *vm);
void    mist_anim(t_image **anim, SDL_Surface *sc, t_image **image);
void    wawe_anim(t_image **anim, SDL_Surface *sc, t_image **image);
void    edge_anim(t_image **anim, SDL_Surface *sc, t_image **image);
int     pop_champ(t_champ *champ, t_mem *mem);
char    **get_instruct(char *bin);
void    spiral_anim(t_image **anim, SDL_Surface *sc, t_image **image);
int	engine(t_vm *vm, func *instruct);
int     *get_color(int nb);
t_champ	*add_champ(t_champ *champ, int pc);
int     get_size_param(int type);
void	live_win(t_champ *champ, t_vm *vm, to_int id);
int	decrease_color(t_mem *mem);
int	counter_live(t_champ *champ, int id);

#endif

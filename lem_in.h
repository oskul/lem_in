/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:28:32 by oskulska          #+#    #+#             */
/*   Updated: 2018/06/14 21:28:39 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/libft.h"
# include <fcntl.h>

typedef struct			s_lemin
{
	int					id;
	char				*name;
	int					end;
	int					start;
	int					y;
	int					x;
	int					pass;
	int					way;
	int					neighbor[500];
	int					number;
	struct s_lemin		*next;
}						t_lemin;

typedef struct			s_way
{
	int					*way;
	int					len;
	int					filter_way;
	struct s_way		*next;
}						t_way;

typedef struct			s_output
{
	int					lemin;
	int					room;

	struct s_output		*next;
}						t_output;

typedef struct			s_flag
{
	int					way;
	int					leaks;
	int					filter;
	int					total;
	int					error;
}						t_flag;

typedef struct			s_all
{
	int					ants;
	int					len;
	int					start;
	int					end;
	int					file_len;
	int					real_len;
	char				**file;
	char				**map;
	int					room_readed;
	int					last_move;
	t_flag				*flag;
	t_way				*way;
	t_output			*output;
	t_lemin				*lemin;
}						t_all;

void					read_to_file(t_all *param);
void					parce_map(t_all *param, char **str, char **map, int y);
void					main_check(char **str, t_all *param, char **map, int y);
t_output				*create_lemin_new_node(void);
t_lemin					*create_node(void);
t_way					*create_node_way(int i);
void					*init_struct();
void					find_all_way(char **map, t_all *all);
int						create_way_list(t_lemin *list, t_way **way);
int						ft_find_way(t_lemin *list,
						t_way *new_node, int i, int k);
void					filter_way(t_all *all, t_way *way);
char					**fill_map(char *line, char **con_map, t_lemin *list);
char					**reset_map(t_lemin *list, char **map, int len);
char					**create_map(char **con_map,
						t_lemin *list, t_all *param);
t_output				*create_lemin(t_all *param);
void					ft_fill_list(t_lemin *list,
						char *line, int start, int end);
void					add_id(t_lemin *list, t_all *param);
void					find_pass(t_all *all, int x, int len, int i);
void					check_end_start_con(char **map, t_all *param);
int						ft_check_cord(char *str, t_lemin *list);
int						conect(char *str);
void					output(t_all *all);
int						check_room_con(char *line, t_all *all);
int						create_way_list(t_lemin *list, t_way **way);
void					ft_clear(char **arr);
t_lemin					*ft_find_list(t_lemin *list, int id);
void					ft_dod_pr(t_lemin *list, int a, int id, t_all *all);
t_lemin					*ft_find_room(char *line,
						int start, int end, t_lemin *tmp);
t_lemin					*ft_find_start(t_lemin *list);
int						main_parce(char **str, int *y, t_all *param);
char					**create_map(char **con_map,
						t_lemin *list, t_all *param);
void					reset_pass(t_lemin *list);
int						is_neighbour(t_lemin *list, int neighbor_id);
void					find_neighbour(char **map, t_all *param);
void					is_start_end(char **map, t_lemin *list);
void					check_way(t_way *way, t_all *all);
void					fill_end_start(t_lemin *list,
						t_way *new_node, t_lemin *start);
void					print_way(t_all *all);
int						cln(char **arr, int a);
void					print_filter_way(t_all *all);
void					check_flag(t_all *param, char *str);
#endif

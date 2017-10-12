/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:44:08 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/10 11:35:26 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H_
# define FILLER_H_
//Just for dip in file check;
int			fd_g;
void		disp_tab_fd(char **tab);
//Just for dip in file check;

typedef struct	s_data_map
{
	int			last_pos[2];
	int			first_pos[2];
	int			pos_sch[2];
	int			save[2];
	int			ret[2];
	int			pos[2];
}				t_dm;

//Just for dip in file check;
void		disp_all(char **tab, char **piece, t_dm *dm);
//Just for dip in file check;

void			init_dm(t_dm *dm);

void			free_map_and_piece(char **map, char **piece);

int				fill_map_and_piece(char ***map, char *line, char ***piece);
int				fill_player(void);


int				brut_force_all(char **map, char **piece, int player, t_dm *dm);
int				rush(char **map, char **piece, int player, t_dm *dm);
int				go_algo(char **map, char **piece, int player, t_dm *dm);

void			put_pos(int pos[2], t_dm *dm);
void			find_first_pos(char **map, t_dm *dm, int player);

int				stick_piece_in_map(char **map, char **piece,
									int pos[2], int player);

int				find_pos_near(char **map, t_dm *dm, int player);

int				duplicate_new_line(char *line, char **free_that);
int				skip_nbr(char *line);
int				fill_nb(char *line, int nb_search);
int				push_line(char ***tab, char *line);
int				cpy_tab(int *dest, int *src);

int				trace_column_top(char **map, t_dm *dm, int near, char find);
int				trace_column_bot(char **map, t_dm *dm, int near, char find);
int				trace_line_right(char **map, t_dm *dm, int near, char find);
int				trace_line_left(char **map, t_dm *dm, int near, char find);

#endif

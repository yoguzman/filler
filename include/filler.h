/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:44:08 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/17 15:19:32 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

typedef struct	s_data_map
{
	int			last_pos[2];
	int			first_pos[2];
	int			c_ma_direction;
}				t_dm;

typedef struct	s_data_stick
{
	char		**map;
	char		**piece;
	int			player;
	int			count;
}				t_ds;

void			init_dm(t_dm *dm);

void			free_map_and_piece(char **map, char **piece);

int				fill_map_and_piece(char ***map, char *line, char ***piece);
int				fill_player(void);

int				brut_force_all(char **map, char **piece, int player, t_dm *dm);
int				rush(char **map, char **piece, int player, t_dm *dm);
int				go_algo(char **map, char **piece, int player, t_dm *dm);

void			put_pos(int pos[2], t_dm *dm);
int				find_first_pos(char **map, t_dm *dm, int player);

int				stick_piece_in_map(char **map, char **piece,
									int pos[2], int player);

int				duplicate_new_line(char *line, char **free_that);
int				skip_nbr(char *line);
int				fill_nb(char *line, int nb_search);
int				push_line(char ***tab, char *line);
int				cpy_tab(int *dest, int *src);

int				brut_force_up_left(char **map, char **piece,
									int player, t_dm *dm);
int				brut_force_up_right(char **map, char **piece,
									int player, t_dm *dm);
int				brut_force_down_left(char **map, char **piece,
								int player, t_dm *dm);
int				brut_force_down_right(char **map, char **piece,
								int player, t_dm *dm);

#endif

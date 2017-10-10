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
	int			last_posme[2];
	int			last_pos[2];
}				t_dm;

void			free_map_and_piece(char **map, char **piece);
int				fill_map_and_piece(char ***map, char *line, char ***piece);
int				fill_player(void);
int				go_algo(char **map, char **piece, int player, t_dm *dm);
int				skip_nbr(char *line);
int				fill_nb(char *line, int nb_search);
int				duplicate_new_line(char *line, char **free_that);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */ /*   Created: 2017/10/09 15:44:15 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/10 14:13:42 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
#include <stdlib.h>
//Just for dip in file check;
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void		disp_tab_fd(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putstr_fd(tab[i], fd_g);
		ft_putstr_fd("\n", fd_g);
		++i;
	} 
}

void		disp_all(char **map, char **piece, t_dm *dm)
{
	ft_putnbr_fd(dm->last_pos[0], fd_g);
	ft_putchar_fd(' ', fd_g);
	ft_putnbr_fd(dm->last_pos[1], fd_g);
	ft_putchar_fd('\n', fd_g);
	disp_tab_fd(map);
	disp_tab_fd(piece);
}
//Just for dip in file check;

void		init_dm(t_dm *dm)
{
	dm->last_pos[0] = -1;
	dm->last_pos[1] = -1;
	dm->first_pos[0] = -1;
	dm->first_pos[1] = -1;
}

int			loop_filler(int player)
{
	char	*line;
	char	**piece;
	char	**map;
	int		ret;
	t_dm	dm;

	map = NULL;
	line = NULL;
	piece = NULL;
	init_dm(&dm);
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if ((ret = fill_map_and_piece(&map, line, &piece)) == -1)
			return (-1);
		if (ret == 1)
			if (go_algo(map, piece, player, &dm) == 1)
				return (1);
	}
	if (ret == -1)
		return (-1);
	return (0);
}

int			main(void)
{
	int		player;

	//Just for dip in file check;
	if ((fd_g = open("check",O_RDWR | O_CREAT, S_IRWXU)) == -1)
		return (-1);
	//Just for dip in file check;
	if ((player = fill_player()) == -1)
		return (-1);
	if (loop_filler(player) == -1)
		return (-1);
	return (0);
}

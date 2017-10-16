/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 13:01:25 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/16 21:04:11 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

int			put_piece_dir(char **map, char **piece, t_dm *dm, int player)
{
	dm->end = 0;
	cpy_tab(dm->save, dm->pos);
	while (try_all_position(dm, piece) == 1)
		if (stick_piece_in_map(map, piece, dm->pos, player) == 0)
			return (1);
	return (0);
}

void		moove_angle(t_dm *dm, int i, char **map)
{
	if (i == 0)
	{
		dm->pos_go[0] = 0;
		dm->pos_go[1] = 0;
	}
	else if (i == 1)
	{
		dm->pos_go[0] = ft_tablen(map) - 1;
		dm->pos_go[1] = 0;
	}
	else if (i == 2)
	{
		dm->pos_go[0] = 0;
		dm->pos_go[1] = (int)ft_strlen(map[0]) - 1;
	}
	else
	{
		dm->pos_go[0] = ft_tablen(map) - 1;
		dm->pos_go[1] = (int)ft_strlen(map[0]) - 1;
	}
}

int			rush(char **map, char **piece, int player, t_dm *dm)
{
	int		i;

	i = 0;
	cpy_tab(dm->pos, dm->last_pos);
	cpy_tab(dm->pos_go, dm->first_pos);
	find_dir(map, player, dm);
	disp_tab_fd(map);
	disp_tab_fd(piece);
	ft_putnbr_fd(dm->pos[0], fd_g);
	ft_putchar_fd(' ', fd_g);
	ft_putnbr_fd(dm->pos[1], fd_g);
	ft_putchar_fd('\n', fd_g);
	ft_putnbr_fd(dm->pos_go[0], fd_g);
	ft_putchar_fd(' ', fd_g);
	ft_putnbr_fd(dm->pos_go[1], fd_g);
	ft_putchar_fd('\n', fd_g);
	ft_putnbr_fd(dm->last_pos[0], fd_g);
	ft_putchar_fd(' ', fd_g);
	ft_putnbr_fd(dm->last_pos[1], fd_g);
	ft_putchar_fd('\n', fd_g);
	while (i < 4)
	{
		if (put_piece_dir(map, piece, dm, player))
		{
			put_pos(dm->pos, dm, piece, '*');
			return (1);
		}
		moove_angle(dm, i, map);
		++i;
	}
	return (0);
}

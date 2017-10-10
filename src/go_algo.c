/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:44:18 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/10 14:21:23 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>

void		fill_pos(int pos[2], int x, int y)
{
	pos[0] = x;
	pos[1] = y;
}

int			stick_piece_in_map(char **map, char **piece,
								int pos[2], int player)
{
	int		i;
	int		j;
	int		xy[2];
	int		count;

	i = 0;
	count = 0;
	xy[0] = pos[0];
	while (piece[i])
	{
		if (map[xy[0]] == NULL)
			return (-1);
		j = 0;
		xy[1] = pos[1];
		while (piece[i][j])
		{
			if (((xy[0] < 0) || (xy[0] > (ft_tablen(map) - 1)) ||
				(xy[1] < 0) || (xy[1] > (int)(ft_strlen(map[0]) - 1)))
				&& piece[i][j] == '.')
				;
			else if (map[xy[0]][xy[1]] == 'X' && player == 2 &&
					piece[i][j] != '.')
				++count;
			else if (map[xy[0]][xy[1]] == 'O' && player == 1 &&
					piece[i][j] != '.')
				++count;
			else if (map[xy[0]][xy[1]] == 'X' && player == 1 &&
					piece[i][j] != '.')
				return (-1);
			else if (map[xy[0]][xy[1]] == 'O' && player == 2 &&
					piece[i][j] != '.')
				return (-1);
			if (count == 2)
			{
				ft_putstr_fd("c kc", fd_g);
				return (-1);
			}
			++xy[1];
			++j;
		}
		++xy[0];
		++i;
	}
	if (count == 0)
	{
		ft_putstr_fd("c kc", fd_g);
		return (-1);
	}
	return (0);
}

void		find_last_pos(char **map, t_dm *dm, int player, int maj)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == 'X' && player == 2 && maj == 1))
				fill_pos(dm->last_posme, i, j);
			else if ((map[i][j] == 'X' && player == 1 && maj == 1) ||
					(map[i][j] == 'x' && player == 1 && maj == 0))
				fill_pos(dm->last_pos, i, j);
			else if ((map[i][j] == 'O' && player == 1 && maj == 1))
				fill_pos(dm->last_posme, i, j);
			else if ((map[i][j] == 'O' && player == 2 && maj == 1) ||
					(map[i][j] == 'o' && player == 2 && maj == 0))
				fill_pos(dm->last_pos, i, j);
			++j;
		}
		++i;
	}
}

void		rush(char **map, char **piece, int player, t_dm *dm)
{
	int		savexy[2];
	int		pos[2];

	pos[0] = dm->last_posme[0];
	pos[1] = dm->last_posme[1];
	savexy[0] = pos[0];
	savexy[1] = pos[1];
	while (stick_piece_in_map(map, piece, pos, player) == -1)
	{
		if (pos[1] == (int)(savexy[1] - ft_strlen(piece[0]) - 1))
		{
			pos[1] = savexy[1];
			pos[0] += 1;
		}
		else
			pos[1] -= 1;
	}
	ft_putstr_fd("LOFODFSJISBJOSISO\n", 0);
	ft_putnbr(pos[0]);
	ft_putstr(" ");
	ft_putnbr(pos[1]);
	ft_putchar('\n');
	dm->last_posme[0] = pos[0];
	dm->last_posme[1] = pos[1];
}

int			go_algo(char **map, char **piece, int player, t_dm *dm)
{
	if (dm->last_posme[0] == -1)
		find_last_pos(map, dm, player, 1);
	else
		find_last_pos(map, dm, player, 0);
	ft_putnbr_fd(dm->last_posme[0], fd_g);
	ft_putchar_fd(' ', fd_g);
	ft_putnbr_fd(dm->last_posme[1], fd_g);
	ft_putchar_fd(' ', fd_g);
	ft_putnbr_fd(dm->last_pos[0], fd_g);
	ft_putchar_fd(' ', fd_g);
	ft_putnbr_fd(dm->last_pos[1], fd_g);
	ft_putchar_fd('\n', fd_g);
	disp_tab_fd(map);
	disp_tab_fd(piece);
	rush(map, piece, player, dm);
	return (0);
}

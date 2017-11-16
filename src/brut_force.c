/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brut_force.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 13:08:22 by yguzman           #+#    #+#             */
/*   Updated: 2017/11/16 15:59:56 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int			brut_force_down_right(char **map, char **piece, int player,
									t_dm *dm)
{
	int		pos[2];

	pos[0] = (int)ft_tablen(map) - 1;
	pos[1] = ft_strlen(map[0]) - 1;
	while (stick_piece_in_map(map, piece, pos, player) == -1)
	{
		if (pos[1] == 0 - (int)ft_strlen(piece[0]) - 1)
		{
			pos[1] = ft_strlen(map[0]) - 1;
			pos[0] -= 1;
		}
		else
			pos[1] -= 1;
		if (pos[0] < 0 - (int)ft_tablen(piece) - 1)
			return (1);
	}
	put_pos(pos, dm);
	return (0);
}

int			brut_force_down_left(char **map, char **piece, int player, t_dm *dm)
{
	int		pos[2];

	pos[0] = ft_tablen(map) - 1;
	pos[1] = 0 - (int)ft_strlen(piece[0]) - 1;
	while (stick_piece_in_map(map, piece, pos, player) == -1)
	{
		if (pos[1] == (int)(ft_strlen(map[0]) - 1))
		{
			pos[1] = 0 - (int)ft_strlen(piece[0]) - 1;
			pos[0] -= 1;
		}
		else
			pos[1] += 1;
		if (pos[0] < 0 - (int)ft_tablen(piece) - 1)
			return (1);
	}
	put_pos(pos, dm);
	return (0);
}

int			brut_force_up_right(char **map, char **piece, int player, t_dm *dm)
{
	int		pos[2];

	pos[0] = 0 - ft_tablen(piece);
	pos[1] = (int)ft_strlen(map[0]) - 1;
	while (stick_piece_in_map(map, piece, pos, player) == -1)
	{
		if (pos[1] == 0 - (int)ft_strlen(piece[0]) - 1)
		{
			pos[1] = (int)ft_strlen(map[0]) - 1;
			pos[0] += 1;
		}
		else
			pos[1] -= 1;
		if (pos[0] > ft_tablen(map) - 1)
			return (1);
	}
	put_pos(pos, dm);
	return (0);
}

int			brut_force_up_left(char **map, char **piece, int player, t_dm *dm)
{
	int		pos[2];

	pos[0] = 0 - (int)ft_tablen(piece) - 1;
	pos[1] = 0 - ft_strlen(piece[0]) - 1;
	while (stick_piece_in_map(map, piece, pos, player) == -1)
	{
		if (pos[1] == (int)(ft_strlen(map[0]) - 1))
		{
			pos[1] = 0 - (int)ft_strlen(piece[0]) - 1;
			pos[0] += 1;
		}
		else
			pos[1] += 1;
		if (pos[0] > ft_tablen(map) - 1)
			return (1);
	}
	put_pos(pos, dm);
	return (0);
}

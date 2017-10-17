/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stick_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 14:32:20 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/17 15:23:56 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int			check_piece(t_ds *ds, int i, int j, int pos[2])
{
	if (((pos[0] + i < 0) || (pos[0] + i > (ft_tablen(ds->map) - 1)) ||
				(pos[1] + j < 0) ||
				(pos[1] + j > (int)(ft_strlen(ds->map[0]) - 1)))
			&& ds->piece[i][j] != '.')
		return (-1);
	if (((pos[0] + i < 0) || (pos[0] + i > (ft_tablen(ds->map) - 1)) ||
				(pos[1] + j < 0) ||
				(pos[1] + j > (int)(ft_strlen(ds->map[0]) - 1)))
			&& ds->piece[i][j] == '.')
		;
	else if ((ds->map[pos[0] + i][pos[1] + j] == 'X' && ds->player == 2 &&
				ds->piece[i][j] != '.') ||
			(ds->map[pos[0] + i][pos[1] + j] == 'O' &&
			ds->player == 1 && ds->piece[i][j] != '.'))
		++ds->count;
	else if ((ds->map[pos[0] + i][pos[1] + j] == 'X' && ds->player == 1 &&
				ds->piece[i][j] != '.') ||
			(ds->map[pos[0] + i][pos[1] + j] == 'O' && ds->player == 2 &&
			ds->piece[i][j] != '.'))
		return (-1);
	if (ds->count == 2)
		return (-1);
	return (0);
}

void		init_ds(t_ds *ds, char **map, char **piece, int player)
{
	ds->map = map;
	ds->piece = piece;
	ds->player = player;
	ds->count = 0;
}

int			stick_piece_in_map(char **map, char **piece,
		int pos[2], int player)
{
	int		i;
	int		j;
	t_ds	ds;

	j = 0;
	i = 0;
	init_ds(&ds, map, piece, player);
	if (pos[0] + i > (ft_tablen(map) - 1) ||
			pos[1] + j > ((int)ft_strlen(map[0]) - 1))
		return (-1);
	while (piece[i])
	{
		j = 0;
		while (piece[i][j])
		{
			if (check_piece(&ds, i, j, pos) == -1)
				return (-1);
			++j;
		}
		++i;
	}
	return (ds.count == 0 ? -1 : 0);
}

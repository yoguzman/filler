/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 14:32:13 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/17 14:32:14 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

void		fill_pos(int pos[2], int x, int y)
{
	pos[0] = x;
	pos[1] = y;
}

int			find_first_pos(char **map, t_dm *dm, int player)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'X' && player == 2)
				fill_pos(dm->last_pos, i, j);
			else if (map[i][j] == 'O' && player == 1)
				fill_pos(dm->last_pos, i, j);
			else if (map[i][j] == 'X' && player == 1)
				fill_pos(dm->first_pos, i, j);
			else if (map[i][j] == 'O' && player == 2)
				fill_pos(dm->first_pos, i, j);
			++j;
		}
		++i;
	}
	return (dm->first_pos[0] < dm->last_pos[0] ? 1 : 0);
}

void		put_pos(int pos[2], t_dm *dm)
{
	ft_putnbr(pos[0]);
	ft_putchar(' ');
	ft_putnbr(pos[1]);
	ft_putchar('\n');
	if (dm->c_ma_direction == 0)
		dm->c_ma_direction = 2;
	else if (dm->c_ma_direction == 1)
		dm->c_ma_direction = 3;
	else if (dm->c_ma_direction == 2)
		dm->c_ma_direction = 0;
	else if (dm->c_ma_direction == 3)
		dm->c_ma_direction = 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:44:18 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/17 14:28:04 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>

int			go_algo(char **map, char **piece, int player, t_dm *dm)
{
	int		ret;

	if (dm->last_pos[0] == -1)
		dm->c_ma_direction = find_first_pos(map, dm, player);
	ret = 0;
	if (dm->c_ma_direction == 1)
		ret = brut_force_down_right(map, piece, player, dm);
	else if (dm->c_ma_direction == 0)
		ret = brut_force_up_left(map, piece, player, dm);
	else if (dm->c_ma_direction == 3)
		ret = brut_force_up_left(map, piece, player, dm);
	else if (dm->c_ma_direction == 2)
		ret = brut_force_down_right(map, piece, player, dm);
	free_map_and_piece(map, piece);
	if (ret == 1)
		return (1);
	return (0);
}

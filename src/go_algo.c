/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:44:18 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/13 16:47:34 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>

int			go_algo(char **map, char **piece, int player, t_dm *dm)
{
	if (dm->last_pos[0] == -1)
		find_first_pos(map, dm, player);
	if (rush(map, piece, player, dm) != 0)
		;
//	else if (brut_force_all(map, piece, player, dm) == 1)
//	{
//		free_map_and_piece(map, piece);
//		return (1);
//	}
	free_map_and_piece(map, piece);
	return (0);
}

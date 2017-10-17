/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 14:29:47 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/17 14:29:48 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
#include <stdlib.h>

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

	if ((player = fill_player()) == -1)
		return (-1);
	if (loop_filler(player) == -1)
		return (-1);
	return (0);
}

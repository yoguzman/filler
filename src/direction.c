/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 16:48:08 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/16 21:08:42 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

void		check_other_bot_right(t_dm *dm, char **map, int player, char ** piece)
{
	char	find;
	int		ret;

	find = (player == 1 ? 'X' : 'O');
	ret = line_left(map, dm, find, piece);
	if (ret == 0)
		ret = column_top(map, dm, find, piece);
	if (ret == 1)
	{
		dm->pos_go[0] = ft_tablen(map) - 1;
		dm->pos_go[1] = 0;
		cpy_tab(dm->save, dm->pos);
//		find_better_pos(map, dm->save, dm, player == 1 ? 'O' : 'X');
	}
	else if (ret == 2)
	{
		dm->pos_go[0] = 0;
		dm->pos_go[1] = (int)ft_strlen(map[0]) - 1;
		cpy_tab(dm->save, dm->pos);
//		find_better_pos(map, dm->save, dm, player == 1 ? 'O' : 'X');
	}
//	if (ret != 0)
//	{
//		dm->pos[0] = dm->save[0] - dm->pos[0];
//		dm->pos[1] = dm->save[1] - dm->pos[1];
//	}
}

void		check_other_bot_left(t_dm *dm, char **map, int player, char ** piece)
{
	char	find;
	int		ret;

	find = (player == 1 ? 'X' : 'O');
	ret = line_right(map, dm, find, piece);
	if (ret == 0)
		ret = column_top(map, dm, find, piece);
	if (ret == 1)
	{
		dm->pos_go[0] = ft_tablen(map) - 1;
		dm->pos_go[1] = (int)ft_strlen(map[0]) - 1;
		cpy_tab(dm->save, dm->pos);
//		find_better_pos(map, dm->save, dm, player == 1 ? 'O' : 'X');
	}
	else if (ret == 2)
	{
		dm->pos_go[0] = 0;
		dm->pos_go[1] = 0;
		cpy_tab(dm->save, dm->pos);
//		find_better_pos(map, dm->save, dm, player == 1 ? 'O' : 'X');
	}
//	if (ret != 0)
//	{
//		dm->pos[0] = dm->save[0] - dm->pos[0];
//		dm->pos[1] = dm->save[1] - dm->pos[1];
//	}
}

void		check_other_top_left(t_dm *dm, char **map, int player, char ** piece)
{
	char	find;
	int		ret;

	find = (player == 1 ? 'X' : 'O');
	ret = line_right(map, dm, find, piece);
	if (ret == 0)
		ret = column_bot(map, dm, find, piece);
	if (ret == 1)
	{
		dm->pos_go[0] = 0;
		dm->pos_go[1] = (int)ft_strlen(map[0]) - 1;
		cpy_tab(dm->save, dm->pos);
//		find_better_pos(map, dm->save, dm, player == 1 ? 'O' : 'X');
	}
	else if (ret == 2)
	{
		dm->pos_go[0] = ft_tablen(map) - 1;
		dm->pos_go[1] = 0;
		cpy_tab(dm->save, dm->pos);
//		find_better_pos(map, dm->save, dm, player == 1 ? 'O' : 'X');
	}
//	if (ret != 0)
//	{
//		dm->pos[0] = dm->save[0] - dm->pos[0];
//		dm->pos[1] = dm->save[1] - dm->pos[1];
//	}
}

void		check_other_top_right(t_dm *dm, char **map, int player, char ** piece)
{
	char	find;
	int		ret;

	find = (player == 1 ? 'X' : 'O');
	ret = line_left(map, dm, find, piece);
	if (ret == 0)
		ret = column_bot(map, dm, find, piece);
	if (ret == 1)
	{
		dm->pos_go[0] = 0;
		dm->pos_go[1] = 0;
		cpy_tab(dm->save, dm->pos);
//		find_better_pos(map, dm->save, dm, player == 1 ? 'O' : 'X');
	}
	else if (ret == 2)
	{
		dm->pos_go[0] =  ft_tablen(map) - 1;
		dm->pos_go[1] = (int)ft_strlen(map[0]) - 1;
		cpy_tab(dm->save, dm->pos);
//		find_better_pos(map, dm->save, dm, player == 1 ? 'O' : 'X');
	}
//	if (ret != 0)
//	{
//		dm->pos[0] = dm->save[0] - dm->pos[0];
//		dm->pos[1] = dm->save[1] - dm->pos[1];
//	}
}

int			find_dir(char **map, int player, t_dm *dm, char **piece)
{
	if (dm->pos[0] >= dm->pos_go[0] && dm->pos[1] >= dm->pos_go[1])
		check_other_bot_right(dm, map, player, piece);
	else if (dm->pos[0] > dm->pos_go[0] && dm->pos[1] < dm->pos_go[1])
		check_other_bot_left(dm, map, player, piece);
	else if (dm->pos[0] <= dm->pos_go[0] && dm->pos[1] >= dm->pos_go[1])
		check_other_top_right(dm, map, player, piece);
	else
		check_other_top_left(dm, map, player, piece);
	return (0);
}

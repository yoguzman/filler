/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_all_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 13:01:30 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/16 16:33:41 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

int			try_top_left(t_dm *dm, char **piece)
{
	if (dm->pos[0] == dm->save[0] && dm->pos[1] == dm->save[1] && dm->end == 0)
		++dm->end;
	else if (dm->pos[0] == (dm->save[0] - ft_tablen(piece) + 1) &&
			dm->pos[1] == (dm->save[1] - (int)ft_strlen(piece[0]) + 1))
		++dm->end;
	else if (dm->pos[1] == (dm->save[1] - ((int)ft_strlen(piece[0])) + 1))
	{
		dm->pos[1] = dm->save[1];
		--dm->pos[0];
	}
	else
		--dm->pos[1];
	if (dm->end == 2)
		return (0);
	return (1);
}

int			try_top_right(t_dm *dm, char **piece)
{
	if (dm->pos[0] == dm->save[0] && dm->pos[1] == dm->save[1] && dm->end == 0)
	{
		++dm->end;
		dm->pos[1] -= ((int)ft_strlen(piece[0]));
		dm->pos[1] += 1;
	}
	else if (dm->pos[0] == (dm->save[0] - ft_tablen(piece) + 1) &&
			dm->pos[1] == dm->save[1])
		++dm->end;
	else if (dm->pos[1] == dm->save[1])
	{
		dm->pos[1] -= ((int)ft_strlen(piece[0]));
		dm->pos[1] += 1;
		--dm->pos[0];
	}
	else
		++dm->pos[1];
	if (dm->end == 2)
		return (0);
	return (1);
}

int			try_bot_left(t_dm *dm, char **piece)
{
	if (dm->pos[0] == dm->save[0] && dm->pos[1] == dm->save[1] && dm->end == 0)
	{
		++dm->end;
		dm->pos[0] -= (ft_tablen(piece));
		dm->pos[0] += 1;
	}
	else if (dm->pos[1] == dm->save[1] - ((int)ft_strlen(piece[0]) - 1) &&
			dm->pos[0] == dm->save[0])
		++dm->end;
	else if (dm->pos[1] == dm->save[1] - ((int)ft_strlen(piece[0]) - 1))
	{
		dm->pos[1] = dm->save[1];
		++dm->pos[0];
	}
	else
		--dm->pos[1];
	if (dm->end == 2)
		return (0);
	return (1);
}

int			try_bot_right(t_dm *dm, char **piece)
{
	if (dm->pos[0] == dm->save[0] && dm->pos[1] == dm->save[1])
	{
		++dm->end;
		dm->pos[1] -= ((int)ft_strlen(piece[0]));
		dm->pos[1] += 1;
		dm->pos[0] -= (ft_tablen(piece));
		dm->pos[0] += 1;
	}
	else if (dm->pos[1] >= dm->save[1])
	{
		dm->pos[1] -= ((int)ft_strlen(piece[0]));
		++dm->pos[0];
	}
	else
		++dm->pos[1];
	if (dm->end == 2)
		return (0);
	return (1);
}

int			try_all_position(t_dm *dm, char **piece)
{
	int		ret;

	ret = 0;
	if (dm->save[0] >= dm->pos_go[0] && dm->save[1] >= dm->pos_go[1])
		ret = try_bot_right(dm, piece);
	else if (dm->save[0] > dm->pos_go[0] && dm->save[1] < dm->pos_go[1])
		ret = try_bot_left(dm, piece);
	else if (dm->save[0] <= dm->pos_go[0] && dm->save[1] >= dm->pos_go[1])
		ret = try_top_right(dm, piece);
	else
		ret = try_top_left(dm, piece);
	return (ret);
}

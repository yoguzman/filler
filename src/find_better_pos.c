/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_better_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 13:03:28 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/16 19:05:24 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

void			find_bot_right(int pos[2], char **piece, char find)
{
	int			i;
	int			j;
	int			possv[2];
	int			nb;

	i = 0;
	nb = -1;
	while (piece[i])
	{
		j = 0;
		while (piece[i][j])
		{
			if (piece[i][j] == find && (nb == -1 || nb > i + j))
			{
				nb = i + j;
				possv[0] = i;
				possv[1] = j;
			}
			++j;
		}
		++i;
	}
	pos[0] += possv[0];
	pos[1] += possv[1];
}
void			find_bot_left(int pos[2], char **piece, char find)
{
	int			i;
	int			j;
	int			possv[2];
	int			nb;

	i = ft_tablen(piece) - 1;
	nb = -1;
	while (i >= 0)
	{
		j = 0;
		while (piece[i][j])
		{
			if (piece[i][j] == find &&
				(nb == -1 || nb <= (j + (ft_tablen(piece) - 1 - i))))
			{
				nb = (j + (ft_tablen(piece) - 1 - i));
				possv[0] = i;
				possv[1] = j;
			}
			++j;
		}
		--i;
	}
	pos[0] += possv[0];
	pos[1] += possv[1];
}
void			find_top_right(int pos[2], char **piece, char find)
{
	int			i;
	int			j;
	int			possv[2];
	int			nb;

	i = (ft_tablen(piece) - 1);
	nb = -1;
	while (i >= 0)
	{
		j = 0;
		while (piece[i][j])
		{
			if (piece[i][j] == find &&
					(nb == -1 || nb >= (j + (ft_tablen(piece) - 1 - i))))
			{
				nb = (j + (ft_tablen(piece) - 1 - i));
				possv[0] = i;
				possv[1] = j;
			}
			++j;
		}
		--i;
	}
	pos[0] += possv[0];
	pos[1] += possv[1];
}

void			find_top_left(int pos[2], char **piece, char find)
{
	int			i;
	int			j;
	int			possv[2];
	int			nb;

	i = 0;
	nb = -1;
	while (piece[i])
	{ j = 0;
		while (piece[i][j])
		{
			if (piece[i][j] == find && (nb == -1 || nb < i + j))
			{
				nb = i + j;
				possv[0] = i;
				possv[1] = j;
			}
			++j;
		}
		++i;
	}
	pos[0] += possv[0];
	pos[1] += possv[1];
}

void			find_better_pos(char **piece, int pos[2], t_dm *dm, char find)
{
	if (pos[0] >= dm->pos_go[0] && pos[1] >= dm->pos_go[1])
		find_bot_right(pos, piece, find);
	else if (pos[0] > dm->pos_go[0] && pos[1] < dm->pos_go[1])
		find_bot_left(pos, piece, find);
	else if (pos[0] <= dm->pos_go[0] && pos[1] >= dm->pos_go[1])
		find_top_right(pos, piece, find);
	else
		find_top_left(pos, piece, find);
}

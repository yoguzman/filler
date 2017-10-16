/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 16:44:23 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/16 21:13:38 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

int			line_left(char **map, t_dm *dm, char find, char **piece)
{
	int		i;
	int		j;

	i = dm->pos[0];
	j = dm->pos[1];
	while (j >= 0 && dm->pos[1] - j < (int)ft_strlen(piece[0]) - 1)
	{
		if (map[i][j] == find)
			return (2);
		--j;
	}
	return (0);
}

int			line_right(char **map, t_dm *dm, char find, char **piece)
{
	int		i;
	int		j;

	i = dm->pos[0];
	j = dm->pos[1];
	while (map[i][j])
	{
		if (map[i][j] == find)
			return (2);
		++j;
	}
	return (0);
}

int			column_top(char **map, t_dm *dm, char find, char **piece)
{
	int		i;
	int		j;

	i = dm->pos[0];
	j = dm->pos[1];
	while (i >= 0)
	{
		if (map[i][j] == find)
			return (1);
		--i;
	}
	return (0);
}

int			column_bot(char **map, t_dm *dm, char find, char **piece)
{
	int		i;
	int		j;

	i = dm->pos[0];
	j = dm->pos[1];
	while (map[i])
	{
		if (map[i][j] == find)
			return (1);
		++i;
	}
	return (0);
}

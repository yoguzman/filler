/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_and_piece.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:44:40 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/17 14:34:21 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
#include <stdlib.h>

int			modif_line(char **line)
{
	if (ft_isdigit((*line)[0]))
	{
		if (duplicate_new_line(*line + skip_nbr(*line), line) == -1)
			return (-1);
		return (1);
	}
	else
	{
		if (duplicate_new_line(*line, line) == -1)
			return (-1);
		return (2);
	}
	return (0);
}

int			malloc_map_or_piece(char ***tab, int line_x,
								int column_y, char *line)
{
	int		i;

	if ((*tab = malloc(sizeof(char *) * (line_x + 1))) == NULL)
		return (-1);
	(*tab)[line_x] = NULL;
	i = 0;
	while (i < line_x)
	{
		if (((*tab)[i] = malloc(sizeof(char) * (column_y + 1))) == NULL)
			return (-1);
		ft_memset((*tab)[i], 0, column_y);
		++i;
	}
	free(line);
	return (0);
}

int			pars_and_fill_line(char **line, char ***map, char ***piece)
{
	if (ft_strncmp(*line, "Plateau", 7) == 0)
		return (malloc_map_or_piece(map, fill_nb(*line, 1),
									fill_nb(*line, 2), *line));
	else if (ft_strncmp(*line, "Piece", 5) == 0)
		return (malloc_map_or_piece(piece, fill_nb(*line, 1),
									fill_nb(*line, 2), *line));
	else if ((*line)[0] == ' ')
		free(*line);
	else
		return (modif_line(line));
	return (0);
}

int			fill_map_and_piece(char ***map, char *line, char ***piece)
{
	int		ret;

	if ((ret = pars_and_fill_line(&line, map, piece)) == -1)
		return (-1);
	if (ret == 1)
		push_line(map, line);
	else if (ret == 2)
		return (push_line(piece, line));
	return (0);
}

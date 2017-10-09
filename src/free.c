/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:44:29 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/09 15:44:30 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void			free_map_and_piece(char **map, char **piece)
{
	int			i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		++i;
	}
	free(map);
	i = 0;
	while (piece[i])
	{
		free(piece[i]);
		++i;
	}
	free(piece);
}

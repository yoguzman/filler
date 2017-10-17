/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:44:23 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/17 14:30:17 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int			cpy_tab(int *dest, int *src)
{
	dest[0] = src[0];
	dest[1] = src[1];
	return (1);
}

int			push_line(char ***tab, char *line)
{
	int		i;

	i = 0;
	while ((*tab)[i] && (*tab)[i][0] != 0)
		++i;
	(*tab)[i] = line;
	if ((*tab)[i + 1] == NULL)
		return (1);
	return (0);
}

int			duplicate_new_line(char *line, char **free_that)
{
	char	*buff;

	if ((buff = ft_strdup(line)) == NULL)
		return (-1);
	free(*free_that);
	*free_that = buff;
	return (0);
}

int			fill_nb(char *line, int nb_search)
{
	int		j;
	char	cpy;
	int		nb;

	j = 0;
	while (j != nb_search)
	{
		while (*line && !ft_isdigit(*line))
			++line;
		++j;
		if (j == nb_search)
			break ;
		while (*line && ft_isdigit(*line))
			++line;
	}
	j = 0;
	while (line[j] && ft_isdigit(line[j]))
		++j;
	cpy = line[j];
	line[j] = 0;
	nb = ft_atoi(line);
	line[j] = cpy;
	return (nb);
}

int			skip_nbr(char *line)
{
	int		i;

	i = 0;
	while (line[i] && ft_isdigit(line[i]))
		++i;
	return (i + 1);
}

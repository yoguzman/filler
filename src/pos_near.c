#include <stdlib.h>
#include "filler.h"

int			*trace_line_left(char **map, int *pos, int near, char find)
{
	int		i;

	pos[0] -= near;
	i = 0;
	while (i < near && (pos[1]) >= 0)
	{
		if (map[pos[0]][pos[1]] == find)
			return (pos);
		++i;
		--pos[1];
	}
	return (NULL);
}

int			*trace_column_top(char **map, int *pos, int near, char find)
{
	int		i;

	pos[1] -= near;
	i = 0;
	while (i < near && (pos[0]) >= 0)
	{
		if (map[pos[0]][pos[1]] == find)
			return (pos);
		++i;
		--pos[0];
	}
	return (NULL);
}

int			scan_top_right(char **map, int *pos, char find)
{
}

int			scan_top_left(char **map, int *pos, char find)
{
	int		*save;
	int		*ret;
	int		near;

	if ((save = malloc(sizeof(int) * 2)) == NULL)
		return (-1);
	if ((ret = malloc(sizeof(int) * 2)) == NULL)
		return (-1);
	near = 1;
	while (near <= pos[1] || near <= pos[0])
	{
		save[0] = pos[0];
		save[1] = pos[1];
		if ((ret = trace_line_left(map, save, near, find)) != NULL)
		{
			pos[0] = ret[0];
			pos[1] = ret[1];
			return (1);
		} 
		save[0] = pos[0];
		save[1] = pos[1];
		if ((ret = trace_column_top(map, save, near, find)) != NULL)
		{
			pos[0] = ret[0];
			pos[1] = ret[1];
			return (1);
		}
		++near;
	}
	return (0);
}

int			scan_bot_right(char **map, int *pos, char find)
{

}

int			scan_bot_left(char **map, int *pos, char find)
{

}

int			find_pos_near(char **map, t_dm *dm, int player, int *pos)
{
	char	find;

	if (player == 1)
		find = 'X';
	else
		find = 'O';
	if (dm->first_pos[0] <= pos[1] && dm->first_pos[1] <= pos[1])
		scan_top_left(map, pos, find);
	else if (dm->first_pos[0] <= pos[1] && dm->first_pos[1] >= pos[1])
		scan_top_right(map, pos, find);
	else if (dm->first_pos[0] >= pos[1] && dm->first_pos[1] <= pos[1])
		scan_bot_left(map, pos, find);
	else if (dm->first_pos[0] >= pos[1] && dm->first_pos[1] >= pos[1])
		scan_bot_right(map, pos, find);
	return (0);
}

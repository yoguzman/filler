#include <stdlib.h>
#include "filler.h"
#include "libft.h"

int			scan_top_right(char **map, char find, t_dm *dm)
{
	int		near;
	int		ret;
   
	near = 1;
	while (dm->pos[0] - near >= 0  || dm->pos[1] + near < (int)ft_strlen(map[0]))
	{
		cpy_tab(dm->save, dm->pos);
		if ((ret = trace_line_right(map, dm, near, find)) != 0)
		{
			cpy_tab(dm->pos, dm->ret);
			return (ret);
		}
		cpy_tab(dm->save, dm->pos);
		if ((ret = trace_column_top(map, dm, near, find)) != 0)
		{
			cpy_tab(dm->pos, dm->ret);
			return (ret);
		}
		if (map[dm->pos[0] - near >= 0 ? dm->pos[0] - near : 0][dm->pos[1] + near < (int)ft_strlen(map[0]) ?  dm->pos[1] + near : ft_strlen(map[0]) - 1] == find)
		{
			dm->pos[0] -= near;
			if (dm->pos[0] < 0)
				dm->pos[0] = 0;
			dm->pos[1] += near;
			if (dm->pos[1] >= (int)ft_strlen(map[0]))
				dm->pos[1] = (int)ft_strlen(map[0]) - 1;
			return (ret);
		}
		++near;
	}
	return (0);
}

int			scan_top_left(char **map, char find, t_dm *dm)
{
	int		near;
	int		ret;

	near = 1;
	while (dm->pos[0] - near >= 0  || dm->pos[1] - near >= 0)
	{
		cpy_tab(dm->save, dm->pos);
		if ((ret = trace_line_left(map, dm, near, find)) != 0)
		{
			cpy_tab(dm->pos, dm->ret);
			return (ret);
		}
		cpy_tab(dm->save, dm->pos);
		if ((ret = trace_column_top(map, dm, near, find)) != 0)
		{
			cpy_tab(dm->pos, dm->ret);
			return (ret);
		}
		if (map[dm->pos[0] - near >= 0 ? dm->pos[0] - near : 0][dm->pos[1] - near >= 0 ? dm->pos[1] - near : 0] == find)
		{
			dm->pos[0] -= near;
			if (dm->pos[0] < 0)
				dm->pos[0] = 0;
			dm->pos[1] -= near;
			if (dm->pos[1] < 0)
				dm->pos[1] = 0;
			return (ret);
		}
		++near;
	}
	return (0);
}

int			scan_bot_right(char **map, char find, t_dm *dm)
{
	int		near;
	int		ret;

	near = 1;
	while (dm->pos[0] + near < ft_tablen(map)  || dm->pos[1] + near < (int)ft_strlen(map[0]))
	{
		cpy_tab(dm->save, dm->pos);
		if ((ret = trace_line_right(map, dm, near, find)) != 0)
		{
			cpy_tab(dm->pos, dm->ret);
			return (ret);
		}
		cpy_tab(dm->save, dm->pos);
		if ((ret = trace_column_bot(map, dm, near, find)) != 0)
		{
			cpy_tab(dm->pos, dm->ret);
			return (ret);
		}
		if (map[dm->pos[0] + near < ft_tablen(map) ? dm->pos[0] + near : ft_tablen(map) - 1][dm->pos[1] + near < (int)ft_strlen(map[0]) ? dm->pos[1] + near : ft_strlen(map[0]) - 1] == find)
		{
			dm->pos[0] += near;
			if (dm->pos[0] >= ft_tablen(map))
				dm->pos[0] = ft_tablen(map) - 1;
			dm->pos[1] += near;
			if (dm->pos[1] >= (int)ft_strlen(map[0]))
				dm->pos[1] = (int)ft_strlen(map[0]) - 1;
			return (ret);
		}
		++near;
	}
	return (0);
}

int			scan_bot_left(char **map, char find, t_dm *dm)
{
	int		near;
	int		ret;

	near = 1;
	while (dm->pos[0] + near < ft_tablen(map) || dm->pos[1] - near >= 0)
	{
		cpy_tab(dm->save, dm->pos);
		if ((ret = trace_line_left(map, dm, near, find)) != 0)
		{
			cpy_tab(dm->pos, dm->ret);
			return (ret);
		}
		cpy_tab(dm->save, dm->pos);
		if ((ret = trace_column_bot(map, dm, near, find)) != 0)
		{
			cpy_tab(dm->pos, dm->ret);
			return (ret);
		}
		if (map[dm->pos[0] + near < ft_tablen(map) ? dm->pos[0] + near : ft_tablen(map) - 1][dm->pos[1] - near >= 0 ? dm->pos[1] - near : 0] == find)
		{
			dm->pos[0] += near;
			if (dm->pos[0] >= ft_tablen(map))
				dm->pos[0] = ft_tablen(map) - 1;
			dm->pos[1] -= near;
			if (dm->pos[1] < 0)
				dm->pos[1] = 0;
			return (ret);
		}
		++near;
	}
	return (0);
}

int			find_pos_near(char **map, t_dm *dm, int player)
{
	char	find;

	if (player == 1)
		find = 'X';
	else
		find = 'O';
	if (dm->pos_sch[0] <= dm->pos[1] && dm->pos_sch[1] <= dm->pos[1])
		return (scan_top_left(map, find, dm));
	else if (dm->pos_sch[0] <= dm->pos[1] && dm->pos_sch[1] >= dm->pos[1])
		return (scan_top_right(map, find, dm));
	else if (dm->pos_sch[0] >= dm->pos[1] && dm->pos_sch[1] <= dm->pos[1])
		return (scan_bot_left(map, find, dm));
	else if (dm->pos_sch[0] >= dm->pos[1] && dm->pos_sch[1] >= dm->pos[1])
		return (scan_bot_right(map, find, dm));
	return (0);
}

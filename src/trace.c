#include "filler.h"
#include "libft.h"

int			trace_line_right(char **map, t_dm *dm, int near, char find)
{
	int		i;

	dm->save[0] += near;
	i = 0;
	while (i < near && (dm->save[1]) < (int)ft_strlen(map[0]) && dm->save[0] < ft_tablen(map))
	{
		if (map[dm->save[0]][dm->save[1]] == find && near == 1)
			return(-1);
		if (map[dm->save[0]][dm->save[1]] == find)
			return (cpy_tab(dm->ret, dm->save));
		++i;
		++dm->save[1];
	}
	return (0);
}

int			trace_line_left(char **map, t_dm *dm, int near, char find)
{
	int		i;

	dm->save[0] -= near;
	i = 0;
	while (i < near && (dm->save[1]) >= 0 && dm->save[0] >= 0)
	{
		if (map[dm->save[0]][dm->save[1]] == find && near == 1)
			return(-1);
		if (map[dm->save[0]][dm->save[1]] == find)
			return (cpy_tab(dm->ret, dm->save));
		++i;
		--dm->save[1];
	}
	return (0);
}

int			trace_column_bot(char **map, t_dm *dm, int near, char find)
{
	int		i;

	dm->save[1] += near;
	i = 0;
	while (i < near && (dm->save[0]) < ft_tablen(map) && dm->save[1] < (int)ft_strlen(map[0]))
	{
		if (map[dm->save[0]][dm->save[1]] == find && near == 1)
			return(-1);
		if (map[dm->save[0]][dm->save[1]] == find)
			return (cpy_tab(dm->ret, dm->save));
		++i;
		++dm->save[0];
	}
	return (0);
}

int			trace_column_top(char **map, t_dm *dm, int near, char find)
{
	int		i;

	dm->save[1] -= near;
	i = 0;
	while (i < near && (dm->save[0]) >= 0 && dm->save[1] >= 0)
	{
		if (map[dm->save[0]][dm->save[1]] == find && near == 1)
			return(-1);
		if (map[dm->save[0]][dm->save[1]] == find)
			return (cpy_tab(dm->ret, dm->save));
		++i;
		--dm->save[0];
	}
	return (0);
}

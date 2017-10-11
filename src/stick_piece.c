#include "libft.h"

int			stick_piece_in_map(char **map, char **piece,
								int pos[2], int player)
{
	int		i;
	int		j;
	int		xy[2];
	int		count;

	i = 0;
	count = 0;
	xy[0] = pos[0];
	while (piece[i])
	{
		if (map[xy[0]] == NULL)
			return (-1);
		j = 0;
		xy[1] = pos[1];
		while (piece[i][j])
		{
			if (((xy[0] < 0) || (xy[0] > (ft_tablen(map) - 1)) ||
				(xy[1] < 0) || (xy[1] > (int)(ft_strlen(map[0]) - 1)))
				&& piece[i][j] != '.')
				return (-1);
			if (((xy[0] < 0) || (xy[0] > (ft_tablen(map) - 1)) ||
				(xy[1] < 0) || (xy[1] > (int)(ft_strlen(map[0]) - 1)))
				&& piece[i][j] == '.')
				;
			else if (map[xy[0]][xy[1]] == 'X' && player == 2 &&
					piece[i][j] != '.')
				++count;
			else if (map[xy[0]][xy[1]] == 'O' && player == 1 &&
					piece[i][j] != '.')
				++count;
			else if (map[xy[0]][xy[1]] == 'X' && player == 1 &&
					piece[i][j] != '.')
				return (-1);
			else if (map[xy[0]][xy[1]] == 'O' && player == 2 &&
					piece[i][j] != '.')
				return (-1);
			if (count == 2)
				return (-1);
			++xy[1];
			++j;
		}
		++xy[0];
		++i;
	}
	if (count == 0)
		return (-1);
	return (0);
}

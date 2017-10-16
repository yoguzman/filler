#include "filler.h"
#include "libft.h"

void		fill_pos(int pos[2], int x, int y)
{
	pos[0] = x;
	pos[1] = y;
}

void		find_first_pos(char **map, t_dm *dm, int player)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'X' && player == 2)
				fill_pos(dm->last_pos, i, j);
			else if (map[i][j] == 'O' && player == 1)
				fill_pos(dm->last_pos, i, j);
			else if (map[i][j] == 'X' && player == 1)
				fill_pos(dm->first_pos, i, j);
			else if (map[i][j] == 'O' && player == 2)
				fill_pos(dm->first_pos, i, j);
			++j;
		}
		++i;
	}
}

void		put_pos(int pos[2], t_dm *dm, char **piece, char find)
{
	ft_putnbr(pos[0]);
	ft_putchar(' ');
	ft_putnbr(pos[1]);
	ft_putchar('\n');
	find_better_pos(piece, pos, dm, find);
	dm->last_pos[0] = pos[0];
	dm->last_pos[1] = pos[1];
}

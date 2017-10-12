#include <stdlib.h>
#include "filler.h"

int			try_top_left(int pos[2], t_dm *dm, int near)
{
	return (1);
}

int			try_top_right(int pos[2], t_dm *dm, int near)
{
	return (1);
}

int			try_bot_left(int pos[2], t_dm *dm, int near)
{
	return (1);
}

int			try_bot_right(int pos[2], t_dm *dm, int near)
{
	return (1);
}

int			try_all_position(int pos[2], t_dm *dm, int near)
{
	int		ret;

	ret = 0;
	if (dm->pos[0] > pos[0] && dm->pos[1] > pos[1])
		ret = try_bot_right(pos, dm, near);
	else if (dm->pos[0] > pos[0] && dm->pos[1] < pos[1])
		ret = try_bot_left(pos, dm, near);
	else if (dm->pos[0] < pos[0] && dm->pos[1] > pos[1])
		ret = try_top_right(pos, dm, near);
	else
		ret = try_bot_left(pos, dm, near);
	return (ret);
}

int			rush(char **map, char **piece, int player, t_dm *dm)
{
	int		pos[2];
	int		near;
	int		ret;
	
	cpy_tab(dm->pos, dm->last_pos);
	cpy_tab(dm->pos_sch, dm->first_pos);
	if (find_pos_near(map, dm, player) == -1)
		return (0);
	pos[0] = dm->pos[0];
	pos[1] = dm->pos[1];
	cpy_tab(dm->pos_sch, dm->last_pos);
	if (find_pos_near(map, dm, (player == 1 ? 2 : 1)) == -1)
		return (0);
	near = 0;
	while (stick_piece_in_map(map, piece, pos, player) == -1)
		if ((ret = try_all_position(map, pos, dm, ++near)) != 1)
			break ;
	if (ret == 0)
		return (0);
	put_pos(dm->pos, dm);
	return (1);
}

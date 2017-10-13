#include <stdlib.h>
#include "filler.h"
#include "libft.h"

int			try_top_left(t_dm *dm, char **piece)
{
	ft_putnbr_fd(dm->pos[0], fd_g);
	ft_putstr_fd(" ", fd_g);
	ft_putnbr_fd(dm->pos[1], fd_g);
	ft_putstr_fd("\n", fd_g);
	if (dm->pos[0] == dm->save[0] && dm->pos[1] == dm->save[1] && dm->end == 0)
		++dm->end;
	else if (dm->pos[0] == (dm->save[0] - ft_tablen(piece) - 1) && dm->pos[1] == (dm->save[1] - (int)ft_strlen(piece[0]) + 1))
		++dm->end;
	else if (dm->pos[1] == (dm->save[1] - ((int)ft_strlen(piece[0])) + 1))
	{
		dm->pos[1] = dm->save[1];
		--dm->pos[0];
	}
	else
		--dm->pos[1];
	if (dm->end == 2)
	{
		ft_putstr_fd("fini", fd_g);
		return (0);
	}
	ft_putnbr_fd(dm->pos[0], fd_g);
	ft_putstr_fd(" ", fd_g);
	ft_putnbr_fd(dm->pos[1], fd_g);
	ft_putstr_fd("\n", fd_g);
	ft_putstr_fd("\n", fd_g);
	return (1);
}

int			try_top_right(t_dm *dm, char **piece)
{
	ft_putnbr_fd(dm->pos[0], fd_g);
	ft_putstr_fd(" ", fd_g);
	ft_putnbr_fd(dm->pos[1], fd_g);
	ft_putstr_fd("\n", fd_g);
	if (dm->pos[0] == dm->save[0] && dm->pos[1] == dm->save[1])
	{
		++dm->end;
		dm->pos[0] += (ft_tablen(piece));
		dm->pos[0] -= 1;
		dm->pos[1] -= ((int)ft_strlen(piece[0]));
		dm->pos[1] += 1;
	}
	else if (dm->pos[1] == dm->save[1])
	{
		dm->pos[1] -= ((int)ft_strlen(piece[0]));
		dm->pos[1] += 1;
		--dm->pos[0];
	}
	else
		++dm->pos[1];
	if (dm->end == 2)
	{
		ft_putstr_fd("fini", fd_g);
		return (0);
	}
	ft_putnbr_fd(dm->pos[0], fd_g);
	ft_putstr_fd(" ", fd_g);
	ft_putnbr_fd(dm->pos[1], fd_g);
	ft_putstr_fd("\n", fd_g);
	ft_putstr_fd("\n", fd_g);
	return (1);
}

int			try_bot_left(t_dm *dm, char **piece)
{
	ft_putnbr_fd(dm->pos[0], fd_g);
	ft_putstr_fd(" ", fd_g);
	ft_putnbr_fd(dm->pos[1], fd_g);
	ft_putstr_fd("\n", fd_g);
	if (dm->pos[0] == dm->save[0] && dm->pos[1] == dm->save[1])
	{
		++dm->end;
		dm->pos[1] += ((int)ft_strlen(piece[0]));
		dm->pos[1] -= 1;
		dm->pos[0] -= (ft_tablen(piece));
		dm->pos[0] += 1;
	}
	else if (dm->pos[1] == dm->save[1])
	{
		dm->pos[1] += ((int)ft_strlen(piece[0]));
		dm->pos[1] -= 1;
		++dm->pos[0];
	}
	else
		--dm->pos[1];
	if (dm->end == 2)
	{
		ft_putstr_fd("fini", fd_g);
		return (0);
	}
	ft_putnbr_fd(dm->pos[0], fd_g);
	ft_putstr_fd(" ", fd_g);
	ft_putnbr_fd(dm->pos[1], fd_g);
	ft_putstr_fd("\n", fd_g);
	ft_putstr_fd("\n", fd_g);
	return (1);
}

int			try_bot_right(t_dm *dm, char **piece)
{
	ft_putnbr_fd(dm->pos[0], fd_g);
	ft_putstr_fd(" ", fd_g);
	ft_putnbr_fd(dm->pos[1], fd_g);
	ft_putstr_fd("\n", fd_g);
	if (dm->pos[0] == dm->save[0] && dm->pos[1] == dm->save[1])
	{
		++dm->end;
		dm->pos[1] -= ((int)ft_strlen(piece[0]));
		dm->pos[1] += 1;
		dm->pos[0] -= (ft_tablen(piece));
		dm->pos[0] += 1;
	}
	else if (dm->pos[1] >= dm->save[1])
	{
		dm->pos[1] -= ((int)ft_strlen(piece[0]));
		++dm->pos[0];
	}
	else
		++dm->pos[1];
	if (dm->end == 2)
	{
	ft_putstr_fd("fini", fd_g);
		return (0);
	}
	ft_putnbr_fd(dm->pos[0], fd_g);
	ft_putstr_fd(" ", fd_g);
	ft_putnbr_fd(dm->pos[1], fd_g);
	ft_putstr_fd("\n", fd_g);
	ft_putstr_fd("\n", fd_g);
	return (1);
}

int			try_all_position(t_dm *dm, char **piece)
{
	int		ret;

	ret = 0;
	if (dm->save[0] >= dm->pos_go[0] && dm->save[1] >= dm->pos_go[1])
		ret = try_bot_right(dm, piece);
	else if (dm->save[0] > dm->pos_go[0] && dm->save[1] < dm->pos_go[1])
		ret = try_bot_left(dm, piece);
	else if (dm->save[0] <= dm->pos_go[0] && dm->save[1] >= dm->pos_go[1])
		ret = try_top_right(dm, piece);
	else
		ret = try_top_left(dm, piece);
	return (ret);
}

int			put_piece_dir(char **map, char **piece, t_dm *dm, int player)
{
	dm->end = 0;
	cpy_tab(dm->save, dm->pos);
	ft_putstr_fd("start_putpiece\n", fd_g);
	ft_putnbr_fd(dm->pos[0], fd_g);
	ft_putstr_fd(" ", fd_g);
	ft_putnbr_fd(dm->pos[1], fd_g);
	ft_putstr_fd("\n", fd_g);
	ft_putnbr_fd(dm->pos_go[0], fd_g);
	ft_putstr_fd(" ", fd_g);
	ft_putnbr_fd(dm->pos_go[1], fd_g);
	ft_putstr_fd("\n", fd_g);
	disp_tab_fd(map);
	disp_tab_fd(piece);
	while (try_all_position(dm, piece) == 1)
		if (stick_piece_in_map(map, piece, dm->pos, player) == 0)
		{
			ft_putstr_fd("stick", fd_g);
			return (1);
		}
	ft_putstr_fd("end_putpiece\n", fd_g);
	return (0);
}

int			rush(char **map, char **piece, int player, t_dm *dm)
{
	cpy_tab(dm->pos, dm->last_pos);

	//test toutes les directions j ai trouve des beug

	dm->pos_go[0] = ft_tablen(map);
	dm->pos_go[1] = (int)(ft_strlen(map[0]) - 1);
	//	find_pos_near(map, dm->pos);
	//	find_dir(map, dm->pos_go);

	if (put_piece_dir(map, piece, dm, player))
		put_pos(dm->pos, dm);
	else
		return (0);
	return (1);
}

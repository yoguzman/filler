#include <stdlib.h>
#include "filler.h"

int			rush(char **map, char **piece, int player, t_dm *dm)
{
	int		*pos;

	if ((pos = malloc(sizeof(int) * 2)) == NULL)
		return (-1);
	pos[0] = dm->last_pos[0];
	pos[1] = dm->last_pos[1];
	find_pos_near(map, dm, player, pos);
		ft_putnbr_fd(pos[0], fd_g);
		ft_putstr_fd(" ", fd_g);
		ft_putnbr_fd(pos[1], fd_g);
		ft_putstr_fd("\n", fd_g);
	dm->last_pos[0] = pos[0];
	dm->last_pos[1] = pos[1];
	disp_tab_fd(map);
	free(pos);
	return (0);
}

#include "libft.h"
#include "filler.h"
#include <stdlib.h>

int			fill_player(void)
{
	char	*line;
	int		nb;

	line = NULL;
	if (get_next_line(0, &line) == -1)
		return (-1);
	nb = fill_nb(line, 1);
	free(line);
	return (nb);
}

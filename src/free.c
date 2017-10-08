#include <stdlib.h>

void			free_map_and_piece(char **map, char **piece)
{
	int			i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		++i;
	}
	free(map);
	i = 0;
	while (piece[i])
	{
		free(piece[i]);
		++i;
	}
	free(piece);
}

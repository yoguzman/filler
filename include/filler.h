#ifndef FILLER_H_
# define FILLER_H_
//Just for dip in file check;
int			fd_g;
void		disp_tab_fd(char **tab)
//Just for dip in file check;

void			free_map_and_piece(char **map, char **piece);
int				fill_map_and_piece(char ***map, char *line, char ***piece);
int				fill_player(void);
int				skip_nbr(char *line);
int				fill_nb(char *line, int nb_search);
int				duplicate_new_line(char *line, char **free_that);

#endif

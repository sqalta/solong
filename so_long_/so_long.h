#ifndef SO_LONG_H
# define SO_LONG_H


# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "Libft/libft.h"
# include "./gnl/get_next_line.h"
# define I_0 "image/deneme.xpm"
# define I_P "image/man.xpm"
# define I_C "image/sarı.xpm"
# define I_W "image/siyah.xpm"


typedef	struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img1;
	void	*img2;
	int		*w_len;
	int		*w_hei;
}t_mlx;


typedef struct s_location{
	int	x;
	int	y;

}t_location;


typedef struct	s_data{
	t_location	*p_location;
	t_mlx		*d_mlx;
	char		**dMap;
	char		**dMapCp;
	char		*lineMap;
	int	lenght;
	int	height;
	int	player;	
	int	collectible;
	int	exit;
	int empty;
	int	wall;
}				t_data;


void	get_map(char *pathMap, t_data *data);
void	r_map(char *pathMap, t_data *data);
void	data_map(t_data *data);
char	components(t_data *data, char s, int i, int j);
void	first_line(t_data *data, int i);
void	middle_line(t_data *data, int i);
void	cntrl_components(t_data *data, int i);
void	valid_path(t_data *data, int i, int j);
int		val_map_cntrl(t_data *data);
void 	print_exit();
#endif
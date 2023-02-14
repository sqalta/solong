#ifndef SO_LONG_H
# define SO_LONG_H


# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "Libft/libft.h"
# include "./gnl/get_next_line.h"
# define I_0 "image/beyaz.xpm"
# define I_P "image/player.xpm"
# define I_C "image/sarı.xpm"
# define I_W "image/siyah.xpm"
# define I_E "image/exit.xpm"
# define I_K "image/kirmizi.xpm"
# define I_DF1 "image/frame1.xpm"
# define I_DF2 "image/frame2.xpm"
# define I_DF3 "image/frame3.xpm"
# define I_DF4 "image/frame4.xpm"
# define I_DF5 "image/frame5.xpm"
# define I_DF6 "image/frame6.xpm"
# define I_DF7 "image/frame7.xpm"
# define I_DF8 "image/frame8.xpm"



# define IMG_L 64 //size image
# define IMG_H 64 //size image
# define W 13
# define D 2
# define A 0
# define S 1
# define ESC 53

typedef	struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*p_img;
	void	*w_img;
	void	*c_img;
	void	*o_img;
	void	*e_img;
	void	*k_img;
	void	*d_frm[8];

	int		img_len;
	int		img_hei;
	int		w_len;
	int		w_hei;
}t_mlx;


typedef struct s_components{
	int	x;
	int	y;
	int	len;
	int hei;
}t_cmp;

typedef struct	s_data{
	t_mlx		*d_mlx;
	t_cmp		*d_player;
	char		**d_map;
	char		*lineMap;
	int	lenght;
	int	height;
	int	player;	
	int	collectible;
	int	exit;
	int empty;
	int enemy;
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
void 	size_map(t_data *data);
void	put_components(t_data *data, char s, int x, int y);
void	put_background(t_data *data);
void	create_window(t_data *data);
int		cntrl_free(int x, int y, t_data *data);
int 	k_down(int keycode, t_data *data);
void 	put_animation(int c, int flag, t_data *data);
void 	print_exit();
#endif
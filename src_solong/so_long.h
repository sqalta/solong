/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:40:29 by spalta            #+#    #+#             */
/*   Updated: 2023/02/24 15:03:22 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../Libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../printf/ft_printf.h"
# define I_0 "image/beyaz.xpm"
# define I_P "image/player.xpm"
# define I_C "image/sarı.xpm"
# define I_W "image/wall.xpm"
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
# define I_EF1 "image/c_frame1.xpm"
# define I_EF2 "image/c_frame2.xpm"
# define I_EF3 "image/c_frame3.xpm"
# define I_EF4 "image/c_frame4.xpm"
# define I_EF5 "image/c_frame5.xpm"
# define I_EF6 "image/c_frame6.xpm"
# define I_EF7 "image/c_frame7.xpm"
# define I_EF8 "image/c_frame8.xpm"
# define I_PR "image/right_p.xpm"
# define I_PL "image/left_p.xpm"
# define I_PB "image/back_p.xpm"
# define I_PF "image/front_p.xpm"
# define L 64 //size image
# define H 64 //size image
# define W 13
# define D 2
# define A 0
# define S 1
# define ESC 53

typedef struct s_loc{
	int	x;
	int	y;
	int	flag;
}t_loc;

typedef struct s_mlx
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
	void	*e_frm[4];
	void	*c_frm[8];

	int		img_len;
	int		img_hei;
	int		w_len;
	int		w_hei;
}t_mlx;

typedef struct s_components
{
	int	x;
	int	y;
	int	x_loc;
	int	y_loc;
	int	len;
	int	hei;
}t_cmp;

typedef struct s_data{
	t_mlx	*d_mlx;
	t_cmp	d_p;
	t_loc	*c_loc;
	t_loc	*e_loc;
	char	**d_map;
	char	*line_map;
	int		flag_c;
	int		lenght;
	int		height;
	int		player;	
	int		collectible;
	int		cpy_collectible;
	int		exit;
	int		empty;
	int		enemy;
	int		wall;
}				t_data;

void	get_map(char *pathMap, t_data *data);
void	r_map(char *pathMap, t_data *data);
void	data_map(t_data *data);
void	components(t_data *data, char s, int i, int j);
void	first_line(t_data *data, int i);
void	middle_line(t_data *data, int i);
void	cntrl_components(t_data *data, int i);
void	valid_path(t_data *data, int i, int j);
int		val_map_cntrl(t_data *data);
void	size_map(t_data *data);
void	put_components(t_data *data, char s, int x, int y);
void	put_background(t_data *data);
void	create_window(t_data *data);
int		cntrl_free(int x, int y, t_data *data);
int		k_down(int keycode, t_data *data);
void	put_animation(int c, int flag, t_data *data);
int		move_x(t_data *data);
int		move(t_data *data);
void	enemy_move(t_data *d);
void	print_exit(int i);
void	cntrl_extansion(char *s);
t_loc	*find_c(t_data *data, char s, int nbr);
int		val_map_cntrl(t_data *data);
void	load_image(t_data *data);
void	load_frame(t_data *data);
void	load_frame2(t_data *data);
int		cntrl_free(int x, int y, t_data *d);
void	put_player2(int c, t_data *d);
void	put_player1(int c, int flag, t_data *d);
int		k_down(int keycode, t_data *d);
void	load_p_image(int c, t_data *data);
void	put_string(t_data *d, int i);
char	*ft_strjoin_gnl(char *s1, char *s2);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:24:36 by spalta            #+#    #+#             */
/*   Updated: 2023/02/19 22:14:36 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cntrl_free(int x, int y, t_data *data) //gidilebilir mi
{
	int i = 0;
	if (data->d_map[x][y] == '1')
		return (0);
	else if (data->d_map[x][y] == 'C')
	{
		while (i < data->cpy_collectible)
		{
			if ((data->col_loc[i].x == y) && (data->col_loc[i].y == x)) //Collectible sayısını azaltacaksın başka bir değişkenle.
			{
				data->col_loc[i].flag = 0;
				data->collectible -= 1;
			}
			i++;
		}
		return (1);
	}
	return (1);
}

void put_animation(int c, int flag, t_data *data)
{
	if (flag == 1)
	{
		mlx_put_image_to_window(data->d_mlx->mlx, data->d_mlx->win, data->d_mlx->p_img, (data->d_player->x) * IMG_L, (data->d_player->y + c) * IMG_H);
		mlx_put_image_to_window(data->d_mlx->mlx, data->d_mlx->win, data->d_mlx->o_img, (data->d_player->x) * IMG_L, (data->d_player->y) * IMG_H);
		if (data->d_map[data->d_player->y][data->d_player->x] == 'E')
			mlx_put_image_to_window(data->d_mlx->mlx, data->d_mlx->win, data->d_mlx->e_img, (data->d_player->x) * IMG_L, (data->d_player->y) * IMG_H);
		data->d_player->y += c;
	}
	if (flag == 0)
	{
		mlx_put_image_to_window(data->d_mlx->mlx, data->d_mlx->win, data->d_mlx->p_img, (data->d_player->x + c) * IMG_L, (data->d_player->y) * IMG_H);
		mlx_put_image_to_window(data->d_mlx->mlx, data->d_mlx->win, data->d_mlx->o_img, (data->d_player->x) * IMG_L, (data->d_player->y) * IMG_H);
		if (data->d_map[data->d_player->y][data->d_player->x] == 'E')
			mlx_put_image_to_window(data->d_mlx->mlx, data->d_mlx->win, data->d_mlx->e_img, (data->d_player->x) * IMG_L, (data->d_player->y) * IMG_H);	
		data->d_player->x += c;
	}
	if (data->d_map[data->d_player->y][data->d_player->x] == 'E' && !data->collectible)
		exit(0);
	if (data->d_map[data->d_player->y][data->d_player->x] == 'C')
		data->d_map[data->d_player->y][data->d_player->x] = '0';
}

int k_down(int keycode, t_data *data)
{
	static	int i;
	if (keycode == ESC)
		print_exit();
	if (keycode == W) //alttaki if koşulu üste alınacak. Line sayısı için
		if (cntrl_free(data->d_player->y - 1, data->d_player->x, data))
			put_animation(-1, 1, data);
	if (keycode == S)
		if (cntrl_free(data->d_player->y + 1, data->d_player->x, data))
			put_animation(1, 1, data);
	if (keycode == A)
		if (cntrl_free(data->d_player->y, data->d_player->x - 1, data))
			put_animation(-1, 0, data);
	if (keycode == D)
		if (cntrl_free(data->d_player->y, data->d_player->x + 1, data))
			put_animation(1, 0, data);
	i++;
	ft_printf("%s%d\n","Step->", i);
	return (0);
}

void collectible_move(t_data *data)
{
	static int z;
	static int j;
	static int k;
	if (j < data->cpy_collectible)
	{
		if (data->col_loc[j].flag)
			mlx_put_image_to_window(data->d_mlx->mlx, data->d_mlx->win, data->d_mlx->d_frm[z], data->col_loc[j].x * IMG_L, data->col_loc[j].y * IMG_H);
		k++;
		j++;
	}
	if (k == data->cpy_collectible)
	{
		usleep(30000);
		j = 0;
		k = 0;
		z++;
	}
	if (z == 7)
		z = 0;
}

int enemy_move(t_data *data)
{
	static int i;
	static int loc;
	usleep(70000);
	if (i <= 3)
	{
		mlx_put_image_to_window(data->d_mlx->mlx, data->d_mlx->win, data->d_mlx->o_img, data->enemy_loc[0].x * IMG_L + loc, data->enemy_loc[0].y * IMG_H);
		loc = loc + 16;
		mlx_put_image_to_window(data->d_mlx->mlx, data->d_mlx->win, data->d_mlx->d_frm[i], data->enemy_loc[0].x * IMG_L + loc, data->enemy_loc[0].y * IMG_H);
		i++;
		return (0);
	}
	if (loc == 64)
	{
		data->enemy_loc[0].x += 1;
		loc = 0;
	}
	if (i > 3 && i <= 7)
	{
		mlx_put_image_to_window(data->d_mlx->mlx, data->d_mlx->win, data->d_mlx->o_img, data->enemy_loc[0].x * IMG_L + loc, data->enemy_loc[0].y * IMG_H);
		loc -= 16;
		mlx_put_image_to_window(data->d_mlx->mlx, data->d_mlx->win, data->d_mlx->d_frm[i], data->enemy_loc[0].x * IMG_L + loc, data->enemy_loc[0].y * IMG_H);
		i++;
		return (0);
	}
	if (i == 8)
	{
		data->enemy_loc[0].x -= 1;
		i = 0;
		loc = 0;
	}
}

int move(t_data *data)
{
	if (data->collectible)
		collectible_move(data);
	if (data->enemy)
		enemy_move(data);
	if (data->d_player->y == data->enemy_loc[0].y && data->d_player->x == data->enemy_loc[0].x) // enemy player kontrolü
		exit (0);
}
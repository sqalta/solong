/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:24:36 by spalta            #+#    #+#             */
/*   Updated: 2023/02/16 20:04:14 by spalta           ###   ########.fr       */
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
		while (i < data->collectible)
		{
			if ((data->col_loc[i].x == x) && (data->col_loc[i].y == y))
			{
				data->col_loc[i].flag = 0;
			}
			i++;
		}
		data->collectible -= 1;
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
	if (data->d_map[data->d_player->y][data->d_player->x] == 'K')
		exit (0);
	if (data->d_map[data->d_player->y][data->d_player->x] == 'C')
		data->d_map[data->d_player->y][data->d_player->x] = '0';
}

int k_down(int keycode, t_data *data)
{
	if (keycode == W) //alttaki if koşulu üste alınacak. Line sayısı için
	{
		if (cntrl_free(data->d_player->y - 1, data->d_player->x, data))
		{
			put_animation(-1, 1, data);
		}
	}
	else if (keycode == S)
	{
		if (cntrl_free(data->d_player->y + 1, data->d_player->x, data))
		{
			put_animation(1, 1, data);
		}
	}
	else if (keycode == A)
	{
		if (cntrl_free(data->d_player->y, data->d_player->x - 1, data))
		{
			put_animation(-1, 0, data);
		}
	}
	else if (keycode == D)
	{
		if (cntrl_free(data->d_player->y, data->d_player->x + 1, data))
		{
			put_animation(1, 0, data);
		}
	}
	return (0);
}

int move(t_data *data)
{
	static int z;
	static int j;
	static int k = 0;

	if (j < data->collectible)
	{
		if (data->col_loc[j].flag)
			mlx_put_image_to_window(data->d_mlx->mlx, data->d_mlx->win, data->d_mlx->d_frm[z], data->col_loc[j].y * IMG_L, data->col_loc[j].x * IMG_H);
		k++;
	}
	if (k == data->col_loc)
	{
		z++;
		j++;
		k = 1;
	}
	if (z == 8)
		z = 0;
}
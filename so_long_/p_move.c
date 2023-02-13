/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:24:36 by spalta            #+#    #+#             */
/*   Updated: 2023/02/13 21:12:15 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cntrl_free(int x, int y, t_data *data) //gidilebilir mi
{
	if (data->d_map[x][y] == '1')
		return (0);
	else if (data->d_map[x][y] == 'C')
	{
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
			put_animation(-1, 1, data);
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
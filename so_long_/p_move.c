/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:24:36 by spalta            #+#    #+#             */
/*   Updated: 2023/02/15 19:01:37 by spalta           ###   ########.fr       */
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
	data->ind = 0;
	if (keycode == W) //alttaki if koşulu üste alınacak. Line sayısı için
	{
		if (cntrl_free(data->d_player->y - 1, data->d_player->x, data))
		{
			
		}
	}
	else if (keycode == S)
	{
		if (cntrl_free(data->d_player->y + 1, data->d_player->x, data))
		{
			
		}
	}
	else if (keycode == A)
	{
		if (cntrl_free(data->d_player->y, data->d_player->x - 1, data))
		{
			data->ind = 8;
			data->m_right = -1;
		}
	}
	else if (keycode == D)
	{
		if (cntrl_free(data->d_player->y, data->d_player->x + 1, data))
		{
			data->ind = 8;
			data->m_right = 1;
		}
	}
	return (0);
}

int	move_x(t_data *data)
{
	static int loc;
	static int z;

	if (data->ind <= 8 && data->ind > 0)
	{
		data->d_player->x_loc = (data->d_player->x * 64) + loc;
		mlx_put_image_to_window(data->d_mlx->mlx, data->d_mlx->win, data->d_mlx->o_img, data->d_player->x_loc, data->d_player->y * IMG_H);
		ft_printf ("loc->%d\n", loc);
		ft_printf ("xloc->%d", data->d_player->x_loc);
		mlx_put_image_to_window(data->d_mlx->mlx, data->d_mlx->win, data->d_mlx->d_frm[8 - data->ind], data->d_player->x_loc, data->d_player->y * IMG_H);
		loc = (IMG_L / 8) * (9 - data->ind) * data->m_right;
		z++;
		data->ind--;
		usleep(50000);
	}
	if (data->ind == 0)
	{
		data->d_player->x += data->m_right;
		ft_printf("-->d_x%d\n", data->d_player->x);
		ft_printf("-->m_rig%d", data->m_right);
		data->ind = 22;
		data->m_right = 0;
		loc = 0;
	}
}


/*int k_down(int keycode, t_data *data)
{
	if (keycode == A)
	{
		if (cntrl_free(data->d_player->y, data->d_player->x + 1, data))
		{
			move_x(-1, data);
		}
	}
	if (keycode == D)
	{
		if (cntrl_free(data->d_player->y, data->d_player->x + 1, data))
		{
			move_x(1, data);
		}
	}
	return (0);
}*/
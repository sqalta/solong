/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:27:43 by spalta            #+#    #+#             */
/*   Updated: 2023/02/23 21:17:35 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cntrl_free(int x, int y, t_data *d)
{
	int	i;

	i = 0;
	if (d->d_map[x][y] == '1')
		return (0);
	else if (d->d_map[x][y] == 'C')
	{
		while (i < d->cpy_collectible)
		{
			if ((d->c_loc[i].x == y) && (d->c_loc[i].y == x))
			{
				d->c_loc[i].flag = 0;
				d->collectible -= 1;
			}
			i++;
		}
		return (1);
	}
	return (1);
}

void	put_player2(int c, t_data *d)
{
	mlx_put_image_to_window(d->d_mlx->mlx, d->d_mlx->win, d->d_mlx
		->p_img, (d->d_p.x + c) * L, (d->d_p.y) * H);
	mlx_put_image_to_window(d->d_mlx->mlx, d->d_mlx->win, d->d_mlx
		->o_img, (d->d_p.x) * L, (d->d_p.y) * H);
	if (d->d_map[d->d_p.y][d->d_p.x] == 'E')
		mlx_put_image_to_window(d->d_mlx->mlx, d->d_mlx->win, d->d_mlx
			->e_img, (d->d_p.x) * L, (d->d_p.y) * H);
	d->d_p.x += c;
}

void	put_player1(int c, int flag, t_data *d)
{
	static int	i;

	if (flag == 1)
	{
		mlx_put_image_to_window(d->d_mlx->mlx, d->d_mlx->win, d->d_mlx
			->p_img, (d->d_p.x) * L, (d->d_p.y + c) * H);
		mlx_put_image_to_window(d->d_mlx->mlx, d->d_mlx->win, d->d_mlx
			->o_img, (d->d_p.x) * L, (d->d_p.y) * H);
		if (d->d_map[d->d_p.y][d->d_p.x] == 'E')
			mlx_put_image_to_window(d->d_mlx->mlx, d->d_mlx->win, d->d_mlx
				->e_img, (d->d_p.x) * L, (d->d_p.y) * H);
		d->d_p.y += c;
	}
	if (flag == 0)
		put_player2(c, d);
	if (d->d_map[d->d_p.y][d->d_p.x] == 'E' && !d->collectible)
		print_exit(i);
	if (d->d_map[d->d_p.y][d->d_p.x] == 'C')
		d->d_map[d->d_p.y][d->d_p.x] = '0';
	put_string(d, ++i);
}

int	k_down2(int keycode, t_data *d)
{
	if (keycode == A)
	{
		if (cntrl_free(d->d_p.y, d->d_p.x - 1, d))
		{
			load_p_image(3, d);
			put_player1(-1, 0, d);
		}
	}
	if (keycode == D)
	{
		if (cntrl_free(d->d_p.y, d->d_p.x + 1, d))
		{
			load_p_image(4, d);
			put_player1(1, 0, d);
		}
	}
	return (0);
}

int	k_down(int keycode, t_data *d)
{
	if (keycode == ESC)
		print_exit(6);
	if (keycode == W)
	{
		if (cntrl_free(d->d_p.y - 1, d->d_p.x, d))
		{
			load_p_image(1, d);
			put_player1(-1, 1, d);
		}
	}
	if (keycode == S)
	{
		if (cntrl_free(d->d_p.y + 1, d->d_p.x, d))
		{
			load_p_image(2, d);
			put_player1(1, 1, d);
		}
	}
	if (keycode == A || keycode == D)
		k_down2(keycode, d);
	return (0);
}

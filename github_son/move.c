/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:24:36 by spalta            #+#    #+#             */
/*   Updated: 2023/02/22 21:43:01 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void collectible_move(t_data *d)
{
	static int z;
	static int j;
	static int k;
	if (j < d->cpy_collectible)
	{
		if (d->c_loc[j].flag)
		{
			mlx_put_image_to_window(d->d_mlx->mlx, d->d_mlx->win, d->d_mlx->o_img, d->c_loc[j].x * L, d->c_loc[j].y * H);
			mlx_put_image_to_window(d->d_mlx->mlx, d->d_mlx->win, d->d_mlx->c_frm[z], d->c_loc[j].x * L, d->c_loc[j].y * H);
		}
		k++;
		j++;
	}
	if (k == d->cpy_collectible)
	{
		j = 0;
		k = 0;
		z++;
	}
	if (z == 7)
		z = 0;
}

int	enemy_move2(t_data *d, int loc, int i)
{
	mlx_put_image_to_window(d->d_mlx->mlx, d->d_mlx->win, d->d_mlx
		->o_img, d->e_loc[0].x * L + loc, d->e_loc[0].y * H);
	loc -= 16;
	mlx_put_image_to_window(d->d_mlx->mlx, d->d_mlx->win, d->d_mlx
		->d_frm[i], d->e_loc[0].x * L + loc, d->e_loc[0].y * H);
	return (loc);
}

void enemy_move(t_data *d)
{
	usleep(50000);
	static int i;
	static int loc;
	if (i <= 3)
	{
		mlx_put_image_to_window(d->d_mlx->mlx, d->d_mlx->win, d->d_mlx->o_img, 
			d->e_loc[0].x * L + loc, d->e_loc[0].y * H);
		loc = loc + 16;
		mlx_put_image_to_window(d->d_mlx->mlx, d->d_mlx->win, d->d_mlx
			->d_frm[i], d->e_loc[0].x * L + loc, d->e_loc[0].y * H);
	}
	if (loc == 64)
	{
		d->e_loc[0].x += 1;
		loc = 0;
	}
	if (i > 3 && i <= 7)
		loc = enemy_move2(d, loc, i);
	i++;
	if (i == 8)
	{
		d->e_loc[0].x -= 1;
		i = 0;
		loc = 0;
	}
}

int move(t_data *d)
{
	if (d->enemy)
		enemy_move(d);
	if (d->collectible)
		collectible_move(d);
	if (d->d_p.y == d->e_loc[0].y && d->d_p.x == d->e_loc[0].x)
		print_exit(4);
	return(0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:24:36 by spalta            #+#    #+#             */
/*   Updated: 2023/02/12 20:21:15 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cntrl_free(char	s) //gidilebilir mi
{
	if (s == '1')
		return (0);
	if (s == 'K') //ekstra fonksiyon yazılacak. Düşman için !;
		return (0);
	return (1);
}

int k_down(int keycode, t_data *data)
{
	if (keycode == W)
	{
		if (cntrl_free(data->d_map[data->d_player->x][data->d_player->y - 1]))
			mlx_put_image_to_window(data->d_mlx->mlx, data->d_mlx->win, data->d_mlx->p_img, (data->d_player->x)* 64, (data->d_player->y - 1) * 64);
	}
	return (0);
}
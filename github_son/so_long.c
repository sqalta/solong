/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:58:11 by spalta            #+#    #+#             */
/*   Updated: 2023/02/23 15:59:30 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void size_map(t_data *data)
{
	data->d_mlx->img_len = L;
	data->d_mlx->img_hei = H;
	data->d_mlx->w_len = (data->lenght * L);
	data->d_mlx->w_hei = (data->height * H);  
}

void	put_components(t_data *data, char s, int x, int y)
{
	if (s == '1')
		mlx_put_image_to_window(data->d_mlx->mlx, data->d_mlx->win, data->d_mlx->w_img, x, y);
	else
	{
		mlx_put_image_to_window(data->d_mlx->mlx, data->d_mlx->win, data->d_mlx->o_img, x, y);
		if (s == 'P')
			mlx_put_image_to_window(data->d_mlx->mlx, data->d_mlx->win, data->d_mlx->p_img, x, y);
		else if (s == 'E')
			mlx_put_image_to_window(data->d_mlx->mlx, data->d_mlx->win, data->d_mlx->e_img, x, y);
		else if (s == 'C')
			mlx_put_image_to_window(data->d_mlx->mlx, data->d_mlx->win, data->d_mlx->o_img, x, y);
		else if (s == 'K')
			mlx_put_image_to_window(data->d_mlx->mlx, data->d_mlx->win, data->d_mlx->o_img, x, y);
	}
}

void	put_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->d_map[i])
	{
		j = 0;
		while (data->d_map[i][j])
		{
			put_components(data, data->d_map[i][j], (j * L), (i * H));
			j++;
		}
		i++;
	}
}

void	create_window(t_data *data)
{
	size_map(data);
	data->d_mlx->mlx = mlx_init();
	data->d_mlx->win = mlx_new_window(data->d_mlx->mlx, data->d_mlx->w_len, data->d_mlx->w_hei, "yamyam");
	load_image(data);
	load_frame(data);
	load_frame2(data);
	put_background(data);
	mlx_hook(data->d_mlx->win, 2, 1L<<0, k_down, data);
	mlx_loop_hook(data->d_mlx->mlx, move, data);
	mlx_loop(data->d_mlx->mlx);
}

int main(int ac, char **av)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	data->d_mlx = ft_calloc(sizeof(t_mlx), 1);
	if (ac == 2)
	{
		get_map(av[1],data);
		create_window(data);
	}
	ft_printf("%s", "Harita Gönderilmedi!!"); // Argüman eksikse !!;
}
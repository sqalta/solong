/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:58:11 by spalta            #+#    #+#             */
/*   Updated: 2023/02/11 17:47:15 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_exit()
{
	printf("%s", "exit");
	exit(0);
}

int main(int ac, char **av)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	data->p_location = ft_calloc(sizeof(t_location), 1);
	data->d_mlx = ft_calloc(sizeof(t_mlx), 1);
	int i = 64;
	if (ac == 2)
	{
		get_map(av[1],data);
		data->d_mlx->mlx = mlx_init();
		data->d_mlx->w_len = data->lenght * i;
		data->d_mlx->w_hei = data->height * i;
		data->d_mlx->win = mlx_new_window(data->d_mlx->mlx, data->d_mlx->w_len, data->d_mlx->w_hei, "First Try");
		data->d_mlx->img1 = mlx_xpm_file_to_image(data->d_mlx->mlx, &I_C, &i,&i);
		data->d_mlx->img2 = mlx_xpm_file_to_image(data->d_mlx->mlx, &I_0, &i,&i);
		mlx_put_image_to_window(data->d_mlx->mlx, data->d_mlx->win, data->d_mlx->img1, 0,0);
		mlx_put_image_to_window(data->d_mlx->mlx, data->d_mlx->win, data->d_mlx->img2, 0,0);
		mlx_loop(data->d_mlx->mlx);
	}
}
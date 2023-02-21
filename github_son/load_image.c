/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:10:48 by spalta            #+#    #+#             */
/*   Updated: 2023/02/21 20:14:54 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_image(t_data *data)
{
	data->d_mlx->p_img = mlx_xpm_file_to_image(data->d_mlx->mlx, I_P, 
		&data->d_mlx->img_len, &data->d_mlx->img_hei);
	data->d_mlx->e_img = mlx_xpm_file_to_image(data->d_mlx->mlx, I_E, 
		&data->d_mlx->img_len, &data->d_mlx->img_hei);
	data->d_mlx->w_img = mlx_xpm_file_to_image(data->d_mlx->mlx, I_W, 
		&data->d_mlx->img_len, &data->d_mlx->img_hei);
	data->d_mlx->o_img = mlx_xpm_file_to_image(data->d_mlx->mlx, I_0, 
		&data->d_mlx->img_len, &data->d_mlx->img_hei);
	data->d_mlx->c_img = mlx_xpm_file_to_image(data->d_mlx->mlx, I_C, 
		&data->d_mlx->img_len, &data->d_mlx->img_hei);
	data->d_mlx->k_img = mlx_xpm_file_to_image(data->d_mlx->mlx, I_K, 
		&data->d_mlx->img_len, &data->d_mlx->img_hei);
}

void	load_frame(t_data *data)
{
	data->d_mlx->d_frm[0] = mlx_xpm_file_to_image(data->d_mlx->mlx, 
		I_DF1, &data->d_mlx->img_len, &data->d_mlx->img_hei);
	data->d_mlx->d_frm[1] = mlx_xpm_file_to_image(data->d_mlx->mlx, 
		I_DF2, &data->d_mlx->img_len, &data->d_mlx->img_hei);
	data->d_mlx->d_frm[2] = mlx_xpm_file_to_image(data->d_mlx->mlx, 
		I_DF3, &data->d_mlx->img_len, &data->d_mlx->img_hei);
	data->d_mlx->d_frm[3] = mlx_xpm_file_to_image(data->d_mlx->mlx, 
		I_DF4, &data->d_mlx->img_len, &data->d_mlx->img_hei);
	data->d_mlx->d_frm[4] = mlx_xpm_file_to_image(data->d_mlx->mlx, 
		I_DF5, &data->d_mlx->img_len, &data->d_mlx->img_hei);
	data->d_mlx->d_frm[5] = mlx_xpm_file_to_image(data->d_mlx->mlx, 
		I_DF6, &data->d_mlx->img_len, &data->d_mlx->img_hei);
	data->d_mlx->d_frm[6] = mlx_xpm_file_to_image(data->d_mlx->mlx, 
		I_DF7, &data->d_mlx->img_len, &data->d_mlx->img_hei);
	data->d_mlx->d_frm[7] = mlx_xpm_file_to_image(data->d_mlx->mlx, 
		I_DF8, &data->d_mlx->img_len, &data->d_mlx->img_hei);
	data->d_mlx->e_frm[0] = mlx_xpm_file_to_image(data->d_mlx->mlx, 
		I_EF1, &data->d_mlx->img_len, &data->d_mlx->img_hei);
	data->d_mlx->e_frm[1] = mlx_xpm_file_to_image(data->d_mlx->mlx, 
		I_EF2, &data->d_mlx->img_len, &data->d_mlx->img_hei);
	data->d_mlx->e_frm[2] = mlx_xpm_file_to_image(data->d_mlx->mlx, 
		I_EF1, &data->d_mlx->img_len, &data->d_mlx->img_hei);
	data->d_mlx->e_frm[3] = mlx_xpm_file_to_image(data->d_mlx->mlx, 
		I_EF4, &data->d_mlx->img_len, &data->d_mlx->img_hei);
}


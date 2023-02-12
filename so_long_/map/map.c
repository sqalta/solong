/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:40:45 by spalta            #+#    #+#             */
/*   Updated: 2023/02/12 18:50:33 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	data_map(t_data *data)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (data->d_map[i])
		i++;
	data->height = i;
	while (data->d_map[0][k])
		k++;
	data->lenght = k;
}

void	cntrl_map(t_data *data)
{
	int	i;

	i = 0;
	data_map(data);
	while (i < data->height)
	{
		if (i == 0 || (i == data->height - 1))
			first_line(data, i);
		else
			middle_line(data, i);
		i++;
	}
}

void	cntrl_components(t_data *data, int i)
{
	if (i)
	{
		if (data->exit != 1)
			print_exit();
		else if (!(data->collectible > 0))
			print_exit();
		else if (data->player != 1)
			print_exit();
	}
	else
	{
		if (!val_map_cntrl(data))
		{
			printf("%s", "EXİTE ULAŞILAMIYOR");
			print_exit();
		}
		//haritayı eski haline döndürme.
		free(data->d_map);
		data->d_map = ft_split(data->lineMap, '\n');
	}
}

void	r_map(char *pathMap, t_data *data)
{
	int		rd;
	char	*buff;
	int		fd;

	fd = open (pathMap, O_RDONLY);
	buff = malloc(sizeof(char) * 3);
	if (!buff)
		print_exit();
	rd = 1;
	while (rd != 0)
	{
		rd = read(fd, buff, 2);
		if (rd == -1)
		{
			free(data->lineMap);
			free(buff);
			print_exit();
		}
		*(buff + rd) = '\0';
		data->lineMap = ft_strjoin_gnl(data->lineMap, buff);
	}
	data->d_map = ft_split(data->lineMap, '\n');
	free(buff);
}

void	get_map(char *pathMap, t_data *data)
{
	data->d_player = ft_calloc(sizeof(t_cmp), 1);
	r_map(pathMap, data);
	cntrl_map(data);
	cntrl_components(data, 1); // 1->başlangıç kontrolleri
	valid_path(data, data->d_player->y, data->d_player->x);
	cntrl_components(data, 0); // 2->valid kontrolleri
}
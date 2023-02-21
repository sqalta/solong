/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:40:45 by spalta            #+#    #+#             */
/*   Updated: 2023/02/21 19:38:38 by spalta           ###   ########.fr       */
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
	if (data->lineMap[i] != '1')
		print_exit(1);
	while (data->lineMap[i])
	{
		if (data->lineMap[i] == '\n')
			if (data->lineMap[i + 1] == '\n' || !data->lineMap[i + 1])
				print_exit(1);
		i++;
	}
	data_map(data);
	i = 0;
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
			print_exit(1);
		else if (!(data->collectible > 0))
			print_exit(1);
		else if (data->player != 1)
			print_exit(1);
	}
	else
	{
		if (!val_map_cntrl(data))
			print_exit(2);
		free(data->d_map);
		data->d_map = ft_split(data->lineMap, '\n');
		data->c_loc = find_c(data, 'C', data->collectible);
		data->cpy_collectible = data->collectible;
		data->e_loc = find_c(data, 'K', data->enemy);
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
		print_exit(1);
	rd = 1;
	while (rd != 0)
	{
		rd = read(fd, buff, 2);
		if (rd == -1)
		{
			free(data->lineMap);
			free(buff);
			print_exit(1);
		}
		*(buff + rd) = '\0';
		data->lineMap = ft_strjoin_gnl(data->lineMap, buff);
	}
	free(buff);
}

void	get_map(char *pathMap, t_data *data)
{
	cntrl_extansion(pathMap);
	r_map(pathMap, data);
	if (!*data->lineMap)
		print_exit(1);
	data->d_map = ft_split(data->lineMap, '\n');
	cntrl_map(data);
	cntrl_components(data, 1);
	valid_path(data, data->d_p.y, data->d_p.x);
	cntrl_components(data, 0);
}

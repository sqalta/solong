/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:40:45 by spalta            #+#    #+#             */
/*   Updated: 2023/02/19 22:09:33 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void print_exit()
{
	printf("%s", "exit");
	exit(0);
}

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
	while (data->lineMap[i])
	{
		if (data->lineMap[i] == '\n')
			if(data->lineMap[i + 1] == '\n' || !data->lineMap[i + 1])
				print_exit();
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
void find_c(t_data *data, char s, int nbr) //collectible ve enemy için ayn fonksiyon, extra char s alsın. s = 'E' GİBİSİNDEN.
{
	t_loc *loc;
	int	i;
	int y;
	int x;

	loc = malloc(sizeof(t_loc) * nbr);
	i = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (data->d_map[y][x])
		{
			if (data->d_map[y][x] == s)
			{
				loc[i].flag = 1; //animasyon flag;
				loc[i].x = x; //
				loc[i].y = y; //
				i++;
			}
			x++;
		}
		y++;
	}
	if (s == 'C')
		data->col_loc = loc;
	else if (s == 'K')
		data->enemy_loc = loc;
	
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
		find_c(data, 'C', data->collectible);
		data->cpy_collectible = data->collectible;  //exit noktasında collectible sayısını kontrol etmek için gerekli !;
		find_c(data, 'K', data->enemy);
		ft_printf("%d", data->enemy);
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
	if (!*data->lineMap)
		print_exit();
	data->d_map = ft_split(data->lineMap, '\n');
	free(buff);
}
void	cntrl_extansion(char *s)
{
	char	*tmp;
	int	i;
	
	if (!*s)
		print_exit();
	i = 0;
	tmp = ft_strchr(s, '.');
	if (!(*(tmp + 1) == 'b' && *(tmp + 2) == 'e' && *(tmp + 3) == 'r'))
		print_exit();
}

void	get_map(char *pathMap, t_data *data)
{
	cntrl_extansion(pathMap);
	data->d_player = ft_calloc(sizeof(t_cmp), 1);
	r_map(pathMap, data);
	cntrl_map(data);
	cntrl_components(data, 1); // 1->başlangıç kontrolleri
	valid_path(data, data->d_player->y, data->d_player->x);
	cntrl_components(data, 0); // 2->valid kontrolleri
}

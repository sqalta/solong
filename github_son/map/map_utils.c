/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:27:41 by spalta            #+#    #+#             */
/*   Updated: 2023/02/21 19:37:52 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	cntrl_dat(t_data *data, int i, int j)
{
	if (data->d_map[i][j] != '1' && data->d_map[i][j] != '.'
		&& data->d_map[i][j] != 'x')
		return (1);
	else
		return (0);
}

void	valid_path(t_data *data, int i, int j)
{
	data->d_map[i][j] = 'x';
	if (cntrl_dat(data, i + 1, j))
		data->d_map[i + 1][j] = '.';
	else if (cntrl_dat(data, i - 1, j))
		data->d_map[i - 1][j] = '.';
	else if (cntrl_dat(data, i, j + 1))
		data->d_map[i][j + 1] = '.';
	else if (cntrl_dat(data, i, j - 1))
		data->d_map[i][j - 1] = '.';
	else
	{
		if (data->d_map[i + 1][j] == '.')
			valid_path(data, i + 1, j);
		else if (data->d_map[i - 1][j] == '.')
			valid_path(data, i - 1, j);
		else if (data->d_map[i][j + 1] == '.')
			valid_path(data, i, j + 1);
		else if (data->d_map[i][j - 1] == '.')
			valid_path(data, i, j - 1);
		else
			return ;
	}
	valid_path(data, i, j);
}

void	first_line(t_data *data, int i)
{
	int	j;

	j = 0;
	if (data->lenght == (int)(ft_strlen(data->d_map[i])))
	{
		while (data->d_map[i][j])
		{
			if (data->d_map[i][j] != '1')
				print_exit(1);
			components(data, data->d_map[i][j], i, j);
			j++;
		}
	}
	else
		print_exit(1);
}

void	middle_line(t_data *data, int i)
{
	int	j;
	int	line_len;

	line_len = ft_strlen(data->d_map[i]);
	j = 0;
	if (data->lenght == line_len)
	{
		if (data->d_map[i][0] != '1' || data->d_map[i][line_len - 1] != '1')
			print_exit(1);
		while (data->d_map[i][j])
		{
			components(data, data->d_map[i][j], i, j);
			j++;
		}
	}
	else
		print_exit(1);
}

void	components(t_data *data, char s, int i, int j)
{
	if (s == '1')
		data->wall += 1;
	else if (s == 'P')
	{
		data->player += 1;
		data->d_p.x = j;
		data->d_p.y = i;
	}
	else if (s == 'E')
		data->exit += 1;
	else if (s == 'C')
		data->collectible += 1;
	else if (s == '0')
		data->empty += 1;
	else if (s == 'K')
		data->enemy += 1;
	else
		print_exit(1);
}

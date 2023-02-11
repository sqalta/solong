/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:27:41 by spalta            #+#    #+#             */
/*   Updated: 2023/02/11 14:05:11 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	val_map_cntrl(t_data *data)
{
	int	i;
	int	j;
	
	i = 0;
	while (data->dMap[i])
	{
		j = 0;
		while (data->dMap[i][j])
		{
			if (data->dMap[i][j] == 'E' || data->dMap[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	valid_path(t_data *data, int i, int j)
{
	/*getchar();
	int f = 0;
	while (data->dMap[f])
	{
		printf ("%s\n", data->dMap[f]);
		f++;
	}
	printf("\n->i%d->j%d", i,j);*/
	data->dMap[i][j] = 'x';
	if (data->dMap[i + 1][j] != '1' && data->dMap[i + 1][j] != '.' && data->dMap[i + 1][j] != 'x')
		data->dMap[i + 1][j] = '.';
	else if (data->dMap[i - 1][j] != '1' && data->dMap[i - 1][j] != '.' && data->dMap[i - 1][j] != 'x')
		data->dMap[i - 1][j] = '.';
	else if (data->dMap[i][j + 1] != '1' && data->dMap[i][j + 1] != '.' && data->dMap[i][j + 1] != 'x')
		data->dMap[i][j + 1] = '.';
	else if (data->dMap[i][j - 1] != '1' && data->dMap[i][j - 1] != '.' && data->dMap[i][j - 1] != 'x')
		data->dMap[i][j - 1] = '.';
	else
	{
		if (data->dMap[i + 1][j] == '.')
			valid_path(data, i + 1, j);
		else if (data->dMap[i - 1][j] == '.')
			valid_path(data, i - 1, j);
		else if (data->dMap[i][j + 1] == '.')
			valid_path(data, i, j + 1);
		else if (data->dMap[i][j - 1] == '.')
			valid_path(data, i, j - 1);
		else
			return;
	}
	valid_path(data, i, j);
}

void	first_line(t_data *data, int i)
{
	int	j;

	j = 0;
	if (data->lenght == (int)(ft_strlen(data->dMap[i])))
	{
 		while (data->dMap[i][j])
		{
			if (data->dMap[i][j] != '1')
				print_exit();
			components(data, data->dMap[i][j], i, j);
			j++;
		}
	}
	else
		print_exit();
}

void	middle_line(t_data *data, int i)
{
	int	j;
	int	lineLen;

	lineLen = ft_strlen(data->dMap[i]);
	j = 0;
	if (data->lenght == lineLen)
	{
		if (data->dMap[i][0] != '1' || data->dMap[i][lineLen - 1] != '1')
			print_exit();
 		while (data->dMap[i][j])
		{
			components(data, data->dMap[i][j], i, j);
			j++;
		}
	}
	else
		print_exit();
}

char	components(t_data *data, char s, int i, int j)
{
	if (s == '1')
		data->wall += 1;
	else if (s == 'P')
	{
		data->player += 1;
		data->p_location->x = j;
		data->p_location->y = i;
		return ('P');
	}
	else if (s == 'E')
	{
		data->exit += 1;
		return ('E');		
	}
	else if (s == 'C')
	{
		data->collectible += 1;
		return ('C');
	}
	else if (s == '0')
		data->empty += 1;
	else
		exit(0);
}
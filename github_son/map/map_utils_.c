/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:06:51 by spalta            #+#    #+#             */
/*   Updated: 2023/02/21 22:15:49 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_exit(int i)
{
	if (i == 1)
		ft_printf("Hatalı Map");
	else if (i == 2)
		ft_printf("%s", "EXİTE ULAŞILAMIYOR");
	else if (i == 3)
		ft_printf("%s", "Hatalı Dosya Uzantisi");
	else if (i == 4)
		ft_printf("%s", "Yakalandıns");
	else
	{
		ft_printf("%s%d\n", "Step->", ++i);
		ft_printf("%s", "Exit'e Ulaşıldı. Tebriks");
	}
	exit(0);
}

void	cntrl_extansion(char *s)
{
	char	*tmp;
	int		i;

	if (!*s)
		print_exit(3);
	i = 0;
	tmp = ft_strchr(s, '.');
	if (!tmp)
		exit(0);
	if (!(*(tmp + 1) == 'b' && *(tmp + 2) == 'e' && *(tmp + 3) == 'r'))
		print_exit(3);
}

t_loc	*find_c(t_data *data, char s, int nbr)
{
	t_loc	*loc;
	int		i;
	int		y;
	int		x;

	loc = malloc(sizeof(t_loc) * nbr);
	i = 0;
	y = -1;
	while (++y < data->height)
	{
		x = 0;
		while (data->d_map[y][x++])
		{
			if (data->d_map[y][x] == s)
			{
				loc[i].flag = 1;
				loc[i].x = x;
				loc[i++].y = y;
			}
		}
	}
	return (loc);
}

int	val_map_cntrl(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->d_map[i])
	{
		j = 0;
		while (data->d_map[i][j])
		{
			if (data->d_map[i][j] == 'E' || data->d_map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

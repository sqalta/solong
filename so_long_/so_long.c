/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:58:11 by spalta            #+#    #+#             */
/*   Updated: 2023/02/10 17:59:34 by spalta           ###   ########.fr       */
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
	if (ac == 2)
	{
		get_map(av[1],data);
	}

}
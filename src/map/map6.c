/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavas <osavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:36:09 by ebilici           #+#    #+#             */
/*   Updated: 2023/07/25 16:36:11 by osavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_int_array(int **array, int map_size)
{
	int		i;

	i = -1;
	while (++i < map_size)
		free(array[i]);
	free(array);
}

int	recursive_check(int **array, int size, int y, int x)
{
	if (y == size || y == -1 || x == size || x == -1)
		return (0);
	else if (array[y][x] != 9 && array[y][x] != 1)
	{
		array[y][x] = 9;
		if (!recursive_check(array, size, y + 1, x))
			return (0);
		else if (!recursive_check(array, size, y - 1, x))
			return (0);
		else if (!recursive_check(array, size, y, x + 1))
			return (0);
		else if (!recursive_check(array, size, y, x - 1))
			return (0);
	}
	return (1);
}

int	check_map5_helper(int **new_array, t_data *data, int i, int j)
{
	if (!recursive_check(new_array, data->map_size, i, j))
	{
		ft_free_helper(data);
		free_int_array(new_array, data->map_size);
		return (print_error("Map is not closed.\n"));
	}
	free_int_array(new_array, data->map_size);
	return (0);
}

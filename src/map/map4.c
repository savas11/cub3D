/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavas <osavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:35:57 by ebilici           #+#    #+#             */
/*   Updated: 2023/07/25 16:35:59 by osavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	setup_int_map3(t_data *data)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	x = 0;
	y = 0;
	while (data->map2[++i])
	{
		if (data->map2[i] == '\n')
		{
			x = -1;
			y++;
		}
		else if (data->map2[i] != '\t' && data->map2[i] != ' ')
			int_map_helper(data, i, x, y);
		x++;
	}
}

void	setup_int_map2(t_data *data, int map_width, int map_height)
{
	int		i;
	int		j;

	i = -1;
	data->map3 = (int **)malloc(sizeof(int *) * map_width);
	while (++i < map_width)
		data->map3[i] = (int *)malloc(sizeof(int) * map_height);
	i = -1;
	while (++i < map_width)
	{
		j = -1;
		while (++j < map_height)
			data->map3[i][j] = 0;
	}
	setup_int_map3(data);
}

int	ft_strlen_mod(char *array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		if (array[i] == '\t')
			i += TAB_SIZE;
		else
			i++;
	}
	return (i);
}

int	check_max_number(char **array, int number, int skip)
{
	int		i;

	i = -1;
	while (array[++i])
		if (number < (int)ft_strlen_mod(array[i]) && i != skip)
			return (-1);
	return (1);
}

int	setup_int_map(t_data *data)
{
	char	**array;
	int		i;
	int		map_width;
	int		map_height;

	array = ft_split(data->map2, '\n');
	i = -1;
	while (array[++i])
		if (check_max_number(array, ft_strlen_mod(array[i]), i) == 1)
			break ;
	map_width = ft_strlen_mod(array[i]);
	i = -1;
	map_height = 0;
	while (data->map2[++i])
		if (data->map2[i] == '\n')
			map_height++;
	if (map_width < map_height)
		map_width = map_height;
	else
		map_height = map_width;
	data->map_size = map_height;
	free_char_array(array);
	setup_int_map2(data, map_width, map_height);
	return (check_map5(data));
}

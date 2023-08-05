/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavas <osavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:34:58 by ebilici           #+#    #+#             */
/*   Updated: 2023/07/25 16:34:59 by osavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_free_map(t_data *data)
{
	if (data->map)
		free(data->map);
	if (data->no_bool == 1)
		free(data->imgs[0]);
	if (data->so_bool == 1)
		free(data->imgs[1]);
	if (data->we_bool == 1)
		free(data->imgs[2]);
	if (data->ea_bool == 1)
		free(data->imgs[3]);
	if (data->f_bool == 1)
		free(data->imgs[4]);
	if (data->c_bool == 1)
		free(data->imgs[5]);
	if (data->map2_bool == 1)
		free(data->map2);
	if (data->imgs)
		free(data->imgs);
	return (0);
}

int	**copy_int_array(int **array, int size)
{
	int	i;
	int	j;
	int	**new_arr;

	new_arr = malloc(sizeof(int *) * size);
	i = -1;
	while (++i < size)
	{
		new_arr[i] = malloc(sizeof(int) * size);
		j = -1;
		while (++j < size)
			new_arr[i][j] = array[i][j];
	}
	return (new_arr);
}

void	free_char_array(char **array)
{
	int		i;

	if (array)
	{
		i = -1;
		while (array[++i])
			free(array[i]);
		free(array);
	}
}

int	print_error(char *str)
{
	ft_putstr_fd("Error!\n", 2);
	ft_putstr_fd(str, 2);
	return (1);
}

int	check_arg(char *str)
{
	int		last_index;
	last_index = ft_strlen(str) - 1;
	if (str[last_index] != 'b')
		return (1);
	else if (str[last_index - 1] != 'u')
		return (1);
	else if (str[last_index - 2] != 'c')
		return (1);
	else if (str[last_index - 3] != '.')
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavas <osavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:35:06 by ebilici           #+#    #+#             */
/*   Updated: 2023/07/25 16:35:08 by osavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free_helper(t_data *data)
{
	free(data->f_rgb);
	free(data->c_rgb);
	free_int_array(data->map3, data->map_size);
}

int	rbg_to_int(int r, int g, int b)
{
	return (((r & 0x0ff) << 16) | ((g & 0x0ff) << 8) | (b & 0x0ff));
}

void	ft_exit(t_data *data)
{
	ft_free_helper(data);
	ft_free_map(data);
	exit(EXIT_SUCCESS);
}

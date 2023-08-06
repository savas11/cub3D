/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavas <osavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:34:13 by osavas            #+#    #+#             */
/*   Updated: 2023/07/25 16:34:17 by osavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//ust zemine renk basmak icin

void	print_c_rgb(t_data *data)
{
	int		x;
	int		y;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		y = -1;
		while (++y < WIN_HEIGHT / 2)
			data->screen_img_data[y * WIN_WIDTH + x] = \
				rbg_to_int(data->c_rgb[0], data->c_rgb[1], \
					data->c_rgb[2]);
	}
}
//alt zemin basmak icin

void	print_f_rgb(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = WIN_HEIGHT / 2;
	while (x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		data->screen_img_data[y * WIN_WIDTH + x] = \
			rbg_to_int(data->f_rgb[0], data->f_rgb[1], \
				data->f_rgb[2]);
		x++;
		if (x == WIN_WIDTH)
		{
			y++;
			x = 0;
		}
	}
}

int	put_image(t_data *data)
{
	int		i;
	void	*img_ptr;

	data->imgs_data = (int **)malloc(sizeof(int *) * 4);
	i = -1;
	while (++i < 4)
	{
		img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, data->imgs[i], \
		&data->img_x, &data->img_y);
		if (img_ptr == NULL)
			return (print_error("xpm file path is invalid."));
		data->imgs_data[i] = (int *)mlx_get_data_addr(img_ptr, \
			&data->bits_per_pixel, &data->size_line, &data->endian);
	}
	return (0);
}

int	key_press(int key, t_data *data)
{
	if (key == BACK)
		data->keys.key_s = true;
	if (key == UP)
		data->keys.key_w = true;
	if (key == RIGHT)
		data->keys.key_a = true;
	if (key == LEFT)
		data->keys.key_d = true;
	if (key == CAMERA_LEFT)
		data->keys.larrow = true;
	if (key == CAMERA_RIGHT)
		data->keys.rarrow = true;
	if (key == ESC)
		ft_exit(data);
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == BACK)
		data->keys.key_s = false;
	if (key == UP)
		data->keys.key_w = false;
	if (key == RIGHT)
		data->keys.key_a = false;
	if (key == LEFT)
		data->keys.key_d = false;
	if (key == CAMERA_LEFT)
		data->keys.larrow = false;
	if (key == CAMERA_RIGHT)
		data->keys.rarrow = false;
	return (0);
}

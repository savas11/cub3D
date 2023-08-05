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

int	update(t_data *data)
{
	if (data->keys.key_a == false && data->keys.key_w == false
		&& data->keys.key_d == false && data->keys.key_s == false
		&& data->keys.rarrow == false && data->keys.larrow == false)
	{
		return (1);
	}
	key_press_helper(data);
	key_press_helper2(data);
	key_press_helper3(data);
	print_c_rgb(data);
	print_f_rgb(data);
	print_map(data);
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

int	start_game(t_data *data)
{
	data->move_speed = 0.1;
	data->rot_speed = 0.04;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, \
	WIN_HEIGHT, "Cub3D");
	data->screen_img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data->screen_img_data = (int *)mlx_get_data_addr(data->screen_img, \
	&data->bits_per_pixel, &data->size_line, &data->endian);
	if (put_image(data))
	{
		ft_free_helper(data);
		return (1);
	}
	print_c_rgb(data);
	print_f_rgb(data);
	print_map(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, &key_press, data);
	mlx_hook(data->win_ptr, 3, 1L << 0, &key_release, data);
	mlx_loop_hook(data->mlx_ptr, &update, data);
	mlx_hook(data->win_ptr, 17, 0, (void *)ft_exit, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavas <osavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:34:41 by ebilici           #+#    #+#             */
/*   Updated: 2023/07/25 16:34:43 by osavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	main(int argc, char **argv)
{
	int		fd;
	t_data	data;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || fd < 3 || check_arg(argv[1]))
		return (print_error("Something wrong with arguments.\n"));
	if (before_start_game(fd, &data))
		return (ft_free_map(&data));
	if (start_game(&data))
		return (ft_free_map(&data));
	return (0);
}

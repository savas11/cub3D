/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavas <osavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:33:57 by ebilici           #+#    #+#             */
/*   Updated: 2023/07/25 16:33:58 by osavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//Bu fonksiyon, birinci adımda x değerini kamera koordinatlarına dönüştürerek, 
//ikinci ve üçüncü adımda ışınların yönünü hesaplayarak, dördüncü ve beşinci 
//adımda oyuncunun konumunu harita koordinatlarına dönüştürerek, altıncı ve 
//yedinci adımda ışın adımlarının uzunluklarını hesaplayarak 
//ve son adımda da çarpışma bayrağını sıfırlayarak, 
//raycasting işlemi için gerekli verileri hazırlar.
//!!!fabs mutlak deger fonksiyonudur o fonsiyonda egimi buluruz
// camera_x gelen x degerine gore -1 ile +1 arasinda deger verir
void	set_data_rc(t_data *data, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIN_WIDTH -1;
	data->raydir_x = data->dir_x + data->plane_x * camera_x;
	data->raydir_y = data->dir_y + data->plane_y * camera_x;
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	data->delta_dist_x = fabs(1 / data->raydir_x);
	data->delta_dist_y = fabs(1 / data->raydir_y);
	data->hit = 0;
}

void	key_press_helper3(t_data *data)
{
	if (data->keys.key_a == true)
	{
		if (data->map3[(int)data->pos_x][(int)(data->pos_y \
			- (data->dir_x * data->move_speed))] != 1)
			data->pos_y -= data->dir_x * data->move_speed;
		if (data->map3[(int)(data->pos_x + (data->dir_y \
			* data->move_speed))][(int)data->pos_y] != 1)
			data->pos_x += data->dir_y * data->move_speed;
	}
	if (data->keys.key_d == true)
	{
		if (data->map3[(int)(data->pos_x)][(int)(data->pos_y \
			+ (data->dir_x * data->move_speed))] != 1)
			data->pos_y += data->dir_x * data->move_speed;
		if (data->map3[(int)(data->pos_x - (data->dir_y \
			* data->move_speed))][(int)(data->pos_y)] != 1)
			data->pos_x -= data->dir_y * data->move_speed;
	}
}

void	key_press_helper2(t_data *data)
{
	double	olddir_x;
	double	oldplane_x;

	if (data->keys.key_w == true)
	{
		if (data->map3[(int)(data->pos_x + data->dir_x \
			* data->move_speed)][(int)(data->pos_y)] != 1)
			data->pos_x += data->dir_x * data->move_speed;
		if (data->map3[(int)(data->pos_x)][(int)(data->pos_y \
			+ data->dir_y * data->move_speed)] != 1)
			data->pos_y += data->dir_y * data->move_speed;
	}
	if (data->keys.rarrow == true)
	{
		olddir_x = data->dir_x;
		data->dir_x = data->dir_x * cos(-data->rot_speed) \
			- data->dir_y * sin(-data->rot_speed);
		data->dir_y = olddir_x * sin(-data->rot_speed) \
			+ data->dir_y * cos(-data->rot_speed);
		oldplane_x = data->plane_x;
		data->plane_x = data->plane_x * cos(-data->rot_speed) \
			- data->plane_y * sin(-data->rot_speed);
		data->plane_y = oldplane_x * sin(-data->rot_speed) \
			+ data->plane_y * cos(-data->rot_speed);
	}
}

void	key_press_helper(t_data *data)
{
	double	olddir_x;
	double	oldplane_x;

	if (data->keys.key_s == true)
	{
		if (data->map3[(int)(data->pos_x - data->dir_x \
			* data->move_speed)][(int)(data->pos_y)] != 1)
			data->pos_x -= data->dir_x * data->move_speed;
		if (data->map3[(int)(data->pos_x)][(int)(data->pos_y \
			- data->dir_y * data->move_speed)] != 1)
			data->pos_y -= data->dir_y * data->move_speed;
	}
	if (data->keys.larrow == true)
	{
		olddir_x = data->dir_x;
		data->dir_x = data->dir_x * cos(data->rot_speed) \
			- data->dir_y * sin(data->rot_speed);
		data->dir_y = olddir_x * sin(data->rot_speed) \
			+ data->dir_y * cos(data->rot_speed);
		oldplane_x = data->plane_x;
		data->plane_x = data->plane_x * cos(data->rot_speed) \
			- data->plane_y * sin(data->rot_speed);
		data->plane_y = oldplane_x * sin(data->rot_speed) \
			+ data->plane_y * cos(data->rot_speed);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavas <osavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:34:35 by ebilici           #+#    #+#             */
/*   Updated: 2023/07/25 16:34:38 by osavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../inc/libft/libft.h"
//# include "../inc/minilibx_linux/mlx.h"
# include "../inc/minilibx_macos/mlx.h"
# include <stdbool.h>

# define WIN_WIDTH 1500
# define WIN_HEIGHT 850
# define IMG_WIDTH 64
# define IMG_HEIGHT 64
# define TAB_SIZE 8
# define UP 13		// w tuşu: 13 - 119
# define BACK 1	// s tuşu: 1 - 115
# define RIGHT 0	// a tuşu: 0 - 97
# define LEFT 2	// d tuşu: 2 - 100
# define CAMERA_RIGHT 123	//Macos: 123 - 65361
# define CAMERA_LEFT 124	//Macos: 124 - 65363
# define ESC 53		//Macos: 53 - 65307

typedef struct s_keys
{
	bool	key_w;
	bool	key_a;
	bool	key_s;
	bool	key_d;
	bool	rarrow;
	bool	larrow;
}	t_keys;

typedef struct t_data
{
	char	**imgs;
	char	*map;
	char	*map2;
	int		**map3;
	int		**imgs_data;
	int		*f_rgb;
	int		*c_rgb;
	int		*screen_img_data;
	int		img_x;
	int		img_y;
	int		map_size;
	int		map2_bool;
	int		no_bool;
	int		so_bool;
	int		we_bool;
	int		ea_bool;
	int		f_bool;
	int		c_bool;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		map_x;
	int		map_y;
	int		hit;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_y;
	int		side;
	int		line_height;
	int		step_x;
	int		step_y;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*screen_img;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	rot_speed;
	double	move_speed;
	double	raydir_x;
	double	raydir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	tex_pos;
	double	step;
	double	perp_wall_dist;
	double	wall_x;
	double	side_dist_x;
	double	side_dist_y;
	t_keys	keys;
}	t_data;

int		**copy_int_array(int **array, int size);
int		before_start_game(int fd, t_data *data);
int		print_error(char *str);
int		check_arg(char *str);
int		check_double_data(t_data *data, int data_key_code);
int		check_map2(t_data *data);
int		check_map4(t_data *data);
int		setup_int_map(t_data *data);
int		check_map5(t_data *data);
int		check_map5_helper(int **new_array, t_data *data, int i, int j);
int		recursive_check(int **array, int size, int y, int x);
int		ft_free_map(t_data *data);
int		start_game(t_data *data);
int		rbg_to_int(int r, int g, int b);
int		print_map(t_data *data);
char	*get_data_value(t_data *data, int index, int mode);
void	setup_imgs(t_data *data, int index, int data_key_code);
void	free_char_array(char **array);
void	int_map_helper(t_data *data, int i, int x, int y);
void	ft_free_helper(t_data *data);
void	free_int_array(int **array, int map_size);
void	set_data_rc(t_data *data, int x);
int		key_release(int key, t_data *data);
int		key_press(int key, t_data *data);
void	key_press_helper(t_data *data);
void	key_press_helper2(t_data *data);
void	key_press_helper3(t_data *data);
int		update(t_data *data);
void	ft_exit(t_data *data);

#endif
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

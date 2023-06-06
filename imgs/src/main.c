/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:26:30 by maclara-          #+#    #+#             */
/*   Updated: 2023/05/24 14:01:56 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load_texture(t_img *texture, t_data *data)
{
	int	ignore;

	texture->img_ptr = mlx_xpm_file_to_image(data->mlx->mlx, texture->name, \
	&ignore, &ignore);
	if (!texture->img_ptr)
		return (0);
	texture->addr = mlx_get_data_addr(texture->img_ptr, \
	&texture->bpp, &texture->size_line, &texture->endian);
	if (!texture->addr)
		return (0);
	return (1);
}

static int	check_load_texture(t_data *data)
{
	if (!load_texture(data->tex->north, data))
	{
		printf("Error\nFailed to initialize texture.\n");
		free_game(data);
	}
	if (!load_texture(data->tex->south, data))
	{
		printf("Error\nFailed to initialize texture.\n");
		free_game(data);
	}
	if (!load_texture(data->tex->east, data))
	{
		printf("Error\nFailed to initialize texture.\n");
		free_game(data);
	}
	if (!load_texture(data->tex->west, data))
	{
		printf("Error\nFailed to initialize texture.\n");
		free_game(data);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	valid_init_game(argc, argv, &data);
	data.mlx->mlx = mlx_init();
	if (!data.mlx->mlx)
	{
		printf("Error\nFailed to initialize window.\n");
		free_game(&data);
	}
	data.mlx->window = mlx_new_window(data.mlx->mlx, \
	SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	if (!data.mlx->window)
	{
		printf("Error\nFailed to initialize window.\n");
		free_game(&data);
	}
	init_images(&data);
	check_load_texture(&data);
	mlx_loop_hook(data.mlx->mlx, make_image, &data);
	mlx_hook(data.mlx->window, KeyPress, KeyPressMask, press_keys, &data);
	mlx_hook(data.mlx->window, KeyRelease, KeyReleaseMask, depress_keys, &data);
	mlx_hook(data.mlx->window, 17, 0L, kill_game, &data);
	mlx_loop(data.mlx->mlx);
	return (0);
}

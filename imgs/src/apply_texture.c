/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:47:59 by maclara-          #+#    #+#             */
/*   Updated: 2023/05/19 20:17:35 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	vertical_mirror(int texture, t_data *data)
{
	if (data->rc->touch_side == 0 && data->rc->ray_dir.x < 0)
		texture = 64 - texture - 1;
	if (data->rc->touch_side == 1 && data->rc->ray_dir.y > 0)
		texture = 64 - texture - 1;
	return (texture);
}

static int	set_texture(t_data *data)
{
	int		texture;
	double	wall;

	if (data->rc->touch_side == 0)
	{
		if (data->rc->ray_dir.x > 0)
			wall = fabs(data->player.y + data->rc->perpendicular_wall_dist * \
			data->rc->ray_dir.y);
		else
			wall = fabs(data->player.y - data->rc->perpendicular_wall_dist * \
			data->rc->ray_dir.y);
	}
	else
	{
		if (data->rc->ray_dir.y > 0)
			wall = fabs(data->player.x + data->rc->perpendicular_wall_dist * \
			data->rc->ray_dir.x);
		else
			wall = fabs(data->player.x - data->rc->perpendicular_wall_dist * \
			data->rc->ray_dir.x);
	}
	wall -= floor(wall);
	texture = (int)(wall * (double)SIZE_IMG);
	texture = vertical_mirror(texture, data);
	return (texture);
}

static void	render_wall(t_data *data)
{
	int	line;
	int	colour;

	line = data->rc->init_draw;
	while (line < data->rc->finish_draw)
	{
		data->rc->texture_y = (int)data->rc->texture_pos & (64 - 1);
		data->rc->texture_pos += data->rc->step;
		colour = put_texture(data->rc->tex, (t_vector) \
		{.y = data->rc->texture_y, .x = data->rc->texture_x});
		put_pixel(&data->paint_img, (t_vector){.x = data->rc->ray, \
		.y = line}, colour);
		line++;
	}
}

void	render_with_texture(t_data *data)
{
	data->rc->texture_x = set_texture(data);
	data->rc->step = 1.0 * 64 / data->rc->line_height;
	data->rc->texture_pos = (data->rc->init_draw - SCREEN_HEIGHT / 2 + \
	data->rc->line_height / 2) * data->rc->step;
	data->rc->tex = get_texture(data);
	render_wall(data);
}

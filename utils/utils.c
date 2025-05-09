/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:18:09 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/09 20:35:31 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	swap_line(t_line *line)
{
	t_point	tmp;

	tmp = line->p0;
	line->p0 = line->p1;
	line->p1 = tmp;
}

t_point	get_isometric(t_data *data, int x, int y, int z)
{
	t_point	pos;

	pos.x = ((x - y) * cos(0.523599)) * data->zoom + data->position_x;
	pos.y = ((x + y) * sin(0.523599) - z) * data->zoom + data->position_y;
	pos.color = data->colors[y][x];
	return (pos);
}
float	get_line_ratio(t_line *line)
{
	float	ratio;

	ratio = 0;
	if (abs(line->dx) > abs(line->dy))
	{
		if (line->p0.x != line->p1.x)
			ratio = (float)(line->m.x - line->p0.x) / (float)(line->p1.x
					- line->p0.x);
	}
	else
	{
		if (line->p0.y != line->p1.y)
			ratio = (float)(line->m.y - line->p0.y) / (float)(line->p1.y
					- line->p0.y);
	}
	return (ratio);
}

int	get_color(t_line *line)
{
	float	ratio;
	t_rgb	rgb0;
	t_rgb	rgb1;
	t_rgb	rgb_result;

	ratio = get_line_ratio(line);
	rgb0.red = (line->p0.color >> 16) & 0xFF;
	rgb0.green = (line->p0.color >> 8) & 0xFF;
	rgb0.blue = line->p0.color & 0xFF;
	rgb1.red = (line->p1.color >> 16) & 0xFF;
	rgb1.green = (line->p1.color >> 8) & 0xFF;
	rgb1.blue = line->p1.color & 0xFF;
	rgb_result.red = (int)(rgb0.red + (rgb1.red - rgb0.red) * ratio);
	rgb_result.green = (int)(rgb0.green + (rgb1.green - rgb0.green) * ratio);
	rgb_result.blue = (int)(rgb0.blue + (rgb1.blue - rgb0.blue) * ratio);
	line->m.color = (rgb_result.red << 16) | (rgb_result.green << 8) | rgb_result.blue;
	return (line->m.color);
}

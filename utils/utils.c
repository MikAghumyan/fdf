/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:18:09 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/14 10:15:32 by maghumya         ###   ########.fr       */
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

t_point	get_center_point(t_data *data)
{
	t_point	center;

	center.x = ((data->row_len - 1) / 2) * data->zoom;
	center.y = ((data->col_len - 1) / 2) * data->zoom;
	center.z = ((data->z_max + data->z_min) / 2) * data->zoom;
	return (center);
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
	t_rgb	result;

	ratio = get_line_ratio(line);
	rgb0.red = (line->p0.color >> 16) & 0xFF;
	rgb0.green = (line->p0.color >> 8) & 0xFF;
	rgb0.blue = line->p0.color & 0xFF;
	rgb1.red = (line->p1.color >> 16) & 0xFF;
	rgb1.green = (line->p1.color >> 8) & 0xFF;
	rgb1.blue = line->p1.color & 0xFF;
	result.red = (int)(rgb0.red + (rgb1.red - rgb0.red) * ratio);
	result.green = (int)(rgb0.green + (rgb1.green - rgb0.green) * ratio);
	result.blue = (int)(rgb0.blue + (rgb1.blue - rgb0.blue) * ratio);
	line->m.color = (result.red << 16) | (result.green << 8) | result.blue;
	return (line->m.color);
}

int	get_random_int(void)
{
	int	fd;
	int	value;

	fd = open("/dev/urandom", O_RDONLY);
	value = 0;
	if (fd < 0)
		return (0);
	read(fd, &value, sizeof(value));
	close(fd);
	return (value);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:58:52 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/14 13:20:33 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_isometric(t_data *data)
{
	int		i;
	int		j;
	t_line	line;

	i = -1;
	while (data->matrix[++i])
	{
		j = -1;
		while (++j < data->row_len)
		{
			line.p0 = get_isometric(data, j, i, data->matrix[i][j]);
			if (j + 1 < data->row_len)
			{
				line.p1 = get_isometric(data, j + 1, i, data->matrix[i][j + 1]);
				draw_line(data, line);
			}
			if (i + 1 < data->col_len)
			{
				line.p1 = get_isometric(data, j, i + 1, data->matrix[i + 1][j]);
				draw_line(data, line);
			}
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

t_point	get_isometric(t_data *data, int x, int y, int z)
{
	t_point	pos;
	t_point	center;

	pos.color = data->colors[y][x];
	x *= data->zoom;
	y *= data->zoom;
	z *= data->zoom;
	center = get_center_point(data);
	rotate_x(data, &y, &z, center);
	rotate_y(data, &x, &z, center);
	rotate_z(data, &x, &y, center);
	rotate_x(data, &center.y, &center.z, center);
	rotate_y(data, &center.x, &center.z, center);
	rotate_z(data, &center.x, &center.y, center);
	x -= center.x;
	y -= center.y;
	z -= center.z;
	pos.x = ((x - y) * cos(0.523599)) + data->position_x;
	pos.y = ((x + y) * sin(0.523599) - z) + data->position_y;
	return (pos);
}

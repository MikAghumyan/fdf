/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orthographic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:37:59 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/12 17:29:06 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	get_orthographic(t_data *data, int x, int y, int z)
{
	t_point	pos;

	if (data->ortho == 1)
	{
		pos.x = x * data->zoom + data->position_x;
		pos.y = y * data->zoom + data->position_y;
	}
	else if (data->ortho == 2)
	{
		pos.x = x * data->zoom + data->position_x;
		pos.y = -z * data->zoom + data->position_y;
	}
	else if (data->ortho == 3)
	{
		pos.x = y * data->zoom + data->position_x;
		pos.y = -z * data->zoom + data->position_y;
	}
	pos.color = data->colors[y][x];
	return (pos);
}

void	draw_orthographic(t_data *data)
{
	int i;
	int j;
	t_line line;

	i = -1;
	while (data->matrix[++i])
	{
		j = -1;
		while (++j < data->row_len)
		{
			line.p0 = get_orthographic(data, j, i, data->matrix[i][j]);
			if (j + 1 < data->row_len)
			{
				line.p1 = get_orthographic(data, j + 1, i, data->matrix[i][j
						+ 1]);
				draw_line(data, line);
			}
			if (i + 1 < data->col_len)
			{
				line.p1 = get_orthographic(data, j, i + 1, data->matrix[i
						+ 1][j]);
				draw_line(data, line);
			}
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
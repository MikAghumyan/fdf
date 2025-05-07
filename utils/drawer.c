/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:00:58 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/07 19:52:48 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	pixel_put_image(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > WINDOW_X || y < 0 || y > WINDOW_Y)
		return ;
	dst = data->img_addr + (y * data->line_length + x * (data->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}

static void	draw_line_h(t_data *data, t_coordinate_2d p0, t_line line)
{
	int	i;
	int	dir;

	if (line.dy < 0)
		dir = -1;
	else
		dir = 1;
	line.dy *= dir;
	if (line.dx)
	{
		line.t = p0.y;
		i = 0;
		line.p = 2 * line.dy - line.dx;
		while (i <= line.dx)
		{
			pixel_put_image(data, p0.x + i++, line.t, p0.color);
			if (line.p >= 0)
			{
				line.t += dir;
				line.p -= 2 * line.dx;
			}
			line.p += 2 * line.dy;
		}
	}
}

static void	draw_line_v(t_data *data, t_coordinate_2d p0, t_line line)
{
	int	i;
	int	dir;

	if (line.dx < 0)
		dir = -1;
	else
		dir = 1;
	line.dx *= dir;
	if (line.dy)
	{
		line.t = p0.x;
		i = 0;
		line.p = 2 * line.dx - line.dy;
		while (i <= line.dy)
		{
			pixel_put_image(data, line.t, p0.y + i++, p0.color);
			if (line.p >= 0)
			{
				line.t += dir;
				line.p -= 2 * line.dy;
			}
			line.p += 2 * line.dx;
		}
	}
}

void	draw_line(t_data *data, t_coordinate_2d p0, t_coordinate_2d p1)
{
	t_line	line;

	if (abs(p1.x - p0.x) > abs(p1.y - p0.y))
	{
		if (p0.x > p1.x)
		{
			swap_nums(&p0.x, &p1.x);
			swap_nums(&p0.y, &p1.y);
		}
		line.dx = p1.x - p0.x;
		line.dy = p1.y - p0.y;
		draw_line_h(data, p0, line);
	}
	else
	{
		if (p0.y > p1.y)
		{
			swap_nums(&p0.x, &p1.x);
			swap_nums(&p0.y, &p1.y);
		}
		line.dx = p1.x - p0.x;
		line.dy = p1.y - p0.y;
		draw_line_v(data, p0, line);
	}
}

void	draw_mesh(t_data *data)
{
	int				i;
	int				j;
	t_coordinate_2d	pos1;

	i = 0;
	while (data->matrix[i])
	{
		j = 0;
		while (j < data->row_len)
		{
			pos1 = get_isometric(data, j, i, data->matrix[i][j]);
			if (j + 1 < data->row_len)
				draw_line(data, pos1, get_isometric(data, j + 1, i,
						data->matrix[i][j + 1]));
			if (i + 1 < data->col_len)
				draw_line(data, pos1, get_isometric(data, j, i + 1,
						data->matrix[i + 1][j]));
			j++;
		}
		printf("\n");
		i++;
	}
}

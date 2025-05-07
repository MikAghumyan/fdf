/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:00:58 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/07 12:56:58 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	pixel_put_image(t_data *data, int x, int y, int color)
{
	char	*dst;

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
			pixel_put_image(data, p0.x + i++, line.t, 0xffffff);
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
			pixel_put_image(data, line.t, p0.y + i++, 0xffffff);
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
	t_coordinate_2d	pos;

	i = 0;
	while (data->matrix[i])
	{
		j = 0;
		while (j < data->row_len)
		{
			pos = get_isometric(j, i, data->matrix[i][j]);
			printf("%d %d\t", pos.x, pos.y);
			j++;
		}
		printf("\n");
		i++;
	}
}

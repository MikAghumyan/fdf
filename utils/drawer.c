/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:00:58 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/09 19:22:57 by maghumya         ###   ########.fr       */
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

static void	draw_line_h(t_data *data, t_line *line)
{
	int	i;

	if (line->dx)
	{
		line->m.y = line->p0.y;
		line->m.x = line->p0.x;
		i = -1;
		line->p = 2 * line->dy - line->dx;
		while (++i <= line->dx)
		{
			line->m.color = get_color(line);
			pixel_put_image(data, line->m.x, line->m.y, line->m.color);
			if (line->p >= 0)
			{
				line->m.y += line->dir;
				line->p -= 2 * line->dx;
			}
			line->p += 2 * line->dy;
			line->m.x++;
		}
	}
}

static void	draw_line_v(t_data *data, t_line *line)
{
	int	i;

	if (line->dy)
	{
		line->m.x = line->p0.x;
		line->m.y = line->p0.y;
		i = -1;
		line->p = 2 * line->dx - line->dy;
		while (++i <= line->dy)
		{
			line->m.color = get_color(line);
			pixel_put_image(data, line->m.x, line->m.y, line->m.color);
			if (line->p >= 0)
			{
				line->m.x += line->dir;
				line->p -= 2 * line->dy;
			}
			line->p += 2 * line->dx;
			line->m.y++;
		}
	}
}

void	draw_line(t_data *data, t_line line)
{
	if (abs(line.p1.x - line.p0.x) > abs(line.p1.y - line.p0.y))
	{
		if (line.p0.x > line.p1.x)
			swap_line(&line);
		line.dx = line.p1.x - line.p0.x;
		line.dy = line.p1.y - line.p0.y;
		line.dir = (line.dy >> 31) | 1;
		line.dy *= line.dir;
		draw_line_h(data, &line);
	}
	else
	{
		if (line.p0.y > line.p1.y)
			swap_line(&line);
		line.dx = line.p1.x - line.p0.x;
		line.dy = line.p1.y - line.p0.y;
		line.dir = (line.dx >> 31) | 1;
		line.dx *= line.dir;
		draw_line_v(data, &line);
	}
}

void	draw_mesh(t_data *data)
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

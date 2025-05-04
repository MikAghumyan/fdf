/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:00:58 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/04 19:47:20 by maghumya         ###   ########.fr       */
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

void	draw_line(t_data *data, t_coordinate p0, t_coordinate p1)
{
	int		dx;
	int		dy;
	double	p;
	int		y;
	int		i;

	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	if (dx)
	{
		y = p0.y;
		i = 0;
		p = 2 * dy - dx;
		while (i < dx + 1)
		{
			pixel_put_image(data, p0.x + i++, y, 0xffffff);
			if (p >= 0)
			{
				y += 1;
				p -= 2 * dx;
			}
			p += 2 * dy;
		}
	}
}

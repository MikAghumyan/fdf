/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:18:09 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/09 17:38:55 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	swap_line(t_line *line)
{
	t_coordinate_2d	tmp;

	tmp = line->p0;
	line->p0 = line->p1;
	line->p1 = tmp;
}

t_coordinate_2d	get_isometric(t_data *data, int x, int y, int z)
{
	t_coordinate_2d	pos;

	pos.x = ((x - y) * cos(0.523599)) * data->zoom + WINDOW_X / 2;
	pos.y = ((x + y) * sin(0.523599) - z) * data->zoom + WINDOW_Y / 2;
	pos.color = data->colors[y][x];
	return (pos);
}

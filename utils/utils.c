/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:18:09 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/08 20:39:32 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	swap_nums(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

t_coordinate_2d	get_isometric(t_data *data, int x, int y, int z)
{
	t_coordinate_2d	pos;

	pos.x = ((x - y) * cos(0.523599)) * data->zoom + WINDOW_X / 2;
	pos.y = ((x + y) * sin(0.523599) - z) * data->zoom + WINDOW_Y / 2;
	pos.color = data->colors[y][x];
	return (pos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:14:15 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/14 10:22:03 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_z(t_data *data, int *x, int *y, t_point center)
{
	t_point	tmp;
	t_point	rotated;

	tmp.x = *x - center.x;
	tmp.y = *y - center.y;
	rotated.x = tmp.x * cos(data->gamma) - tmp.y * sin(data->gamma);
	rotated.y = tmp.x * sin(data->gamma) + tmp.y * cos(data->gamma);
	*x = rotated.x + center.x;
	*y = rotated.y + center.y;
}

void	rotate_y(t_data *data, int *x, int *z, t_point center)
{
	t_point	tmp;
	t_point	rotated;

	tmp.x = *x - center.x;
	tmp.z = *z - center.z;
	rotated.x = tmp.x * cos(data->tetha) + tmp.z * sin(data->tetha);
	rotated.z = tmp.z * cos(data->tetha) - tmp.x * sin(data->tetha);
	*x = rotated.x + center.x;
	*z = rotated.z + center.z;
}

void	rotate_x(t_data *data, int *y, int *z, t_point center)
{
	t_point	tmp;
	t_point	rotated;

	tmp.y = *y - center.y;
	tmp.z = *z - center.z;
	rotated.y = tmp.y * cos(data->alpha) - tmp.z * sin(data->alpha);
	rotated.z = tmp.y * sin(data->alpha) + tmp.z * cos(data->alpha);
	*y = rotated.y + center.y;
	*z = rotated.z + center.z;
}

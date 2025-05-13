/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:14:15 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/14 00:35:40 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_z(t_data *data, int *x, int *y)
{
	int	tmp_x;
	int	tmp_y;
	int	rotated_x;
	int	rotated_y;
	int	center_x;
	int	center_y;

	center_x = ((data->row_len - 1) / 2) * data->zoom;
	center_y = ((data->col_len - 1) / 2) * data->zoom;
	tmp_x = *x - center_x;
	tmp_y = *y - center_y;
	rotated_x = tmp_x * cos(data->gamma) - tmp_y * sin(data->gamma);
	rotated_y = tmp_x * sin(data->gamma) + tmp_y * cos(data->gamma);
	*x = rotated_x + center_x;
	*y = rotated_y + center_y;
}

void	rotate_y(t_data *data, int *x, int *z)
{
	int	tmp_x;
	int	tmp_z;
	int	rotated_x;
	int	rotated_z;
	int	center_x;
	int	center_z;

	center_x = ((data->row_len - 1) / 2) * data->zoom;
	center_z = ((data->z_max + data->z_min) / 2) * data->zoom;
	tmp_x = *x - center_x;
	tmp_z = *z - center_z;
	rotated_x = tmp_x * cos(data->tetha) + tmp_z * sin(data->tetha);
	rotated_z = tmp_z * cos(data->tetha) - tmp_x * sin(data->tetha);
	*x = rotated_x + center_x;
	*z = rotated_z + center_z;
}

void	rotate_x(t_data *data, int *y, int *z)
{
	int tmp_y;
	int tmp_z;
	int rotated_y;
	int rotated_z;
	int center_y;
	int center_z;

	center_y = ((data->col_len - 1) / 2) * data->zoom;
	center_z = ((data->z_max + data->z_min) / 2) * data->zoom;
	tmp_y = *y - center_y;
	tmp_z = *z - center_z;
	rotated_y = tmp_y * cos(data->alpha) - tmp_z * sin(data->alpha);
	rotated_z = tmp_y * sin(data->alpha) + tmp_z * cos(data->alpha);
	*y = rotated_y + center_y;
	*z = rotated_z + center_z;
}
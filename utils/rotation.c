/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:14:15 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/13 14:25:06 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_z(t_data *data, int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = tmp * cos(data->gamma) - *y * sin(data->gamma);
	*y = tmp * sin(data->gamma) + *y * cos(data->gamma);
}

void	rotate_y(t_data *data, int *x, int *z)
{
	int	tmp;

	tmp = *x;
	*x = tmp * cos(data->tetha) + *z * sin(data->tetha);
	*z = *z * cos(data->tetha) - tmp * sin(data->tetha);
}

void	rotate_x(t_data *data, int *y, int *z)
{
	int tmp;

	tmp = *y;
	*y = tmp * cos(data->alpha) - *z * sin(data->alpha);
	*z = tmp * sin(data->alpha) + *z * cos(data->alpha);
}
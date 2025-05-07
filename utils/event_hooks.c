/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:15:06 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/07 20:09:28 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, t_data *data)
{
	printf("%d pressed\n", keycode);
	if (keycode == ESC_KEY)
		handle_exit(data, -1);
	if (keycode == PLUS_KEY)
	{
		data->zoom += 5;
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, WINDOW_X, WINDOW_Y);
		if (!data->img)
			handle_error("image creation failed", data, -1);
		data->img_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		draw_mesh(data);
	}
	if (keycode == MINUS_KEY)
	{
		data->zoom -= 5;
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, WINDOW_X, WINDOW_Y);
		if (!data->img)
			handle_error("image creation failed", data, -1);
		data->img_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		draw_mesh(data);
	}
	return (0);
}

int	win_close_hook(t_data *data)
{
	handle_exit(data, -1);
	return (0);
}
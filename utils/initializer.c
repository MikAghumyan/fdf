/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:50:21 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/14 10:01:29 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	initialize_data(t_data *data)
{
	data->matrix = NULL;
	data->colors = NULL;
	data->def_color = get_random_int();
	data->ortho = 0;
	data->col_len = 0;
	data->row_len = 0;
	data->alpha = 0;
	data->tetha = 0;
	data->gamma = 0;
	data->z_max = 0;
	data->z_min = 0;
	data->zoom = SCALE;
	data->position_x = WINDOW_X / 2;
	data->position_y = WINDOW_Y / 2;
	data->img = NULL;
	data->img_addr = NULL;
	data->win = NULL;
	data->mlx = NULL;
}

void	initialize_image(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WINDOW_X, WINDOW_Y);
	if (!data->img)
		handle_error("image creation failed", data, -1);
	data->img_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (data->ortho > 0 && data->ortho < 4)
		draw_orthographic(data);
	else
		draw_isometric(data);
}

void	initialize_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		handle_error("mlx initializion failed", data, -1);
	data->win = mlx_new_window(data->mlx, WINDOW_X, WINDOW_Y, "fdf");
	if (!data->mlx)
		handle_error("window creation failed", data, -1);
	mlx_hook(data->win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, win_close_hook,
		data);
	initialize_image(data);
}

void	free_window(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	data->img = NULL;
	data->win = NULL;
	data->mlx = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:50:21 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/03 20:40:37 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	initialize_data(t_data *data)
{
	data->matrix = NULL;
	data->col_len = 0;
	data->row_len = 0;
	data->img = NULL;
	data->img_addr = NULL;
	data->win = NULL;
	data->mlx = NULL;
}

void	initialize_window(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WINDOW_X, WINDOW_Y, "fdf");
	mlx_key_hook(data->win, key_hook, data);
	data->img = mlx_new_image(data->mlx, WINDOW_X, WINDOW_Y);
	data->img_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_loop(data->mlx);
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
	ft_printf("free mlx: %p %p %p\n", data->img, data->win, data->mlx);
}
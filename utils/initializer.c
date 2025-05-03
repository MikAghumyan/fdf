/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:50:21 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/03 20:30:46 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	initialize_data(t_data *data)
{
	data->matrix = NULL;
	data->col_len = 0;
	data->row_len = 0;
}

void	initialize_window(t_data *data, t_image_data *img)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WINDOW_X, WINDOW_Y, "fdf");
	mlx_key_hook(data->win, key_hook, data);
	img->img = mlx_new_image(data->mlx, WINDOW_X, WINDOW_Y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
	mlx_loop(data->mlx);
}

void	free_window(t_data *data, t_image_data *img)
{
	if (img->img)
		mlx_destroy_image(data->mlx, img->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	ft_printf("free mlx: %p %p %p\n", img->img, data->win, data->mlx);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:04:34 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/09 20:17:22 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	handle_move(int keycode, t_data *data)
{
	if (keycode == PLUS_KEY)
		data->zoom += 5;
	else if (keycode == MINUS_KEY)
		data->zoom -= 5;
	else if (keycode == ARROW_UP_KEY)
		data->position_y -= 5;
	else if (keycode == ARROW_DOWN_KEY)
		data->position_y += 5;
	else if (keycode == ARROW_LEFT_KEY)
		data->position_x -= 5;
	else if (keycode == ARROW_RIGHT_KEY)
		data->position_x += 5;
	initialize_image(data);
}

void	handle_error(char *err_msg, t_data *data, int fd)
{
	if (data)
	{
		free_matrix((void **)data->matrix);
		free_matrix((void **)data->colors);
		free_window(data);
	}
	if (fd >= 0)
		close(fd);
	ft_putstr_fd("fdf: ", 2);
	ft_putstr_fd(err_msg, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	exit(1);
}

void	handle_exit(t_data *data, int fd)
{
	if (data)
	{
		free_matrix((void **)data->matrix);
		free_matrix((void **)data->colors);
		free_window(data);
	}
	if (fd >= 0)
		close(fd);
	ft_putendl_fd("fdf: program exited successfully", 1);
	exit(0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:04:34 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/13 17:21:52 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	handle_move(int keycode, t_data *data)
{
	int	handled;

	handled = 1;
	if (keycode == PLUS_KEY)
		data->zoom += TRANSLATE;
	else if (keycode == MINUS_KEY)
		data->zoom -= TRANSLATE;
	else if (keycode == ARROW_UP_KEY)
		data->position_y -= TRANSLATE;
	else if (keycode == ARROW_DOWN_KEY)
		data->position_y += TRANSLATE;
	else if (keycode == ARROW_LEFT_KEY)
		data->position_x -= TRANSLATE;
	else if (keycode == ARROW_RIGHT_KEY)
		data->position_x += TRANSLATE;
	else
		handled = 0;
	if (handled)
		initialize_image(data);
}

void	handle_view(int keycode, t_data *data)
{
	int	handled;

	handled = 1;
	if (keycode == KEY_2)
		data->ortho = 1;
	else if (keycode == KEY_3)
		data->ortho = 2;
	else if (keycode == KEY_4)
		data->ortho = 3;
	else if (keycode == KEY_1)
		data->ortho = 0;
	else
		handled = 0;
	if (handled)
		initialize_image(data);
}

void	handle_rotation(int keycode, t_data *data)
{
	int	handled;

	handled = 1;
	if (keycode == A_KEY)
		data->gamma += 0.02;
	else if (keycode == D_KEY)
		data->gamma -= 0.02;
	else if (keycode == W_KEY)
		data->alpha += 0.02;
	else if (keycode == S_KEY)
		data->alpha -= 0.02;
	else if (keycode == Q_KEY)
		data->tetha -= 0.02;
	else if (keycode == E_KEY)
		data->tetha += 0.02;
	else
		handled = 0;
	if (handled)
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

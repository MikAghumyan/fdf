/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:15:06 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/14 16:02:08 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		handle_exit(data, -1);
	handle_move(keycode, data);
	handle_view(keycode, data);
	handle_rotation(keycode, data);
	handle_transform(keycode, data);
	return (0);
}

int	win_close_hook(t_data *data)
{
	handle_exit(data, -1);
	return (0);
}

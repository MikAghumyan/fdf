/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:15:06 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/12 16:32:38 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, t_data *data)
{
	printf("%d pressed\n", keycode);
	if (keycode == ESC_KEY)
		handle_exit(data, -1);
	handle_move(keycode, data);
	handle_view(keycode, data);
	return (0);
}

int	win_close_hook(t_data *data)
{
	handle_exit(data, -1);
	return (0);
}

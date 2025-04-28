/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:04:34 by maghumya          #+#    #+#             */
/*   Updated: 2025/04/28 20:29:54 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	handle_error(char *err_msg, t_data *data)
{
	if (data)
	{
		ft_putendl_fd("data", 2);
	}
	ft_putstr_fd("fdf: ", 2);
	ft_putstr_fd(err_msg, 2);
	ft_putendl_fd(strerror(errno), 2);
	exit(1);
}
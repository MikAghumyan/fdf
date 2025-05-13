/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:19:37 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/13 13:56:33 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd("fdf: invalid arguments \nUsage: ./fdf <file_path.fdf>\n",
			2);
		return (1);
	}
	initialize_data(&data);
	if (validate_file(&data, argv[1]) <= 0)
		return (ft_putstr_fd("fdf: invalid map \n", 2), 1);
	make_matrix(&data, argv[1]);
	initialize_window(&data);
	mlx_loop(data.mlx);
	handle_exit(&data, -1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:19:37 by maghumya          #+#    #+#             */
/*   Updated: 2025/04/29 15:41:28 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
	{
		ft_putstr_fd("fdf: invalid arguments \nUsage: ./fdf <file_path.fdf>\n",
			2);
		return (1);
	}
	printf("col_len: %zd\n", validate_file(&data, argv[1]));
	return (0);
}
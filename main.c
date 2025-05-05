/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:19:37 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/05 16:28:35 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	main(int argc, char **argv)
{
	t_data			data;
	t_coordinate	p0;
	t_coordinate	p1;
	int				i;
	int				j;

	if (argc != 2)
	{
		ft_putstr_fd("fdf: invalid arguments \nUsage: ./fdf <file_path.fdf>\n",
			2);
		return (1);
	}
	initialize_data(&data);
	if (validate_file(&data, argv[1]) <= 0)
		return (ft_putstr_fd("fdf: invalid map \n", 2), 1);
	printf("row_len: %zd \n", data.row_len);
	printf("col_len: %zd \n", data.col_len);
	make_matrix(&data, argv[1]);
	i = 0;
	while (data.matrix[i])
	{
		j = 0;
		while (j < data.row_len)
			printf("%d ", data.matrix[i][j++]);
		printf("\n");
		i++;
	}
	initialize_window(&data);
	p0.x = 500;
	p0.y = 500;
	p1.x = 100;
	p1.y = 100;
	draw_line(&data, p0, p1);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
	free_matrix((void **)data.matrix);
	return (0);
}

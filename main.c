/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:19:37 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/03 18:30:07 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;
	int		j;
	void	*mlx;
	void	*win;

	if (argc != 2)
	{
		ft_putstr_fd("fdf: invalid arguments \nUsage: ./fdf <file_path.fdf>\n",
			2);
		return (1);
	}
	data.matrix = NULL;
	data.col_len = 0;
	data.row_len = 0;
	if (validate_file(&data, argv[1]) <= 0)
	{
		ft_putstr_fd("fdf: invalid map \n", 2);
		return (1);
	}
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
	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "FDF Test");
	mlx_loop(mlx);
	free_matrix((void **)data.matrix);
	return (0);
}

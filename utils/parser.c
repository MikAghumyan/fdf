/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:47:37 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/14 16:02:16 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_matrix(void **matrix)
{
	size_t	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
	matrix = NULL;
}

static ssize_t	fill_point(t_data *data, int row_i, int col_i, char **nbr_strs)
{
	char	**point_data;

	point_data = ft_split(nbr_strs[col_i], ',');
	if (!point_data)
		return (-1);
	data->matrix[row_i][col_i] = ft_atoi(point_data[0]);
	if (data->matrix[row_i][col_i] < data->z_min)
		data->z_min = data->matrix[row_i][col_i];
	else if (data->matrix[row_i][col_i] > data->z_max)
		data->z_max = data->matrix[row_i][col_i];
	if (point_data[1])
	{
		data->colors[row_i][col_i] = ft_atoi_base(point_data[1] + 2, 16);
	}
	else
		data->colors[row_i][col_i] = data->def_color
			+ data->matrix[row_i][col_i] * 500;
	free_matrix((void **)point_data);
	return (0);
}

ssize_t	fill_line(t_data *data, int fd, int row_i)
{
	char	*line;
	char	**nbr_strs;
	ssize_t	i;

	line = get_next_line(fd);
	if (!line)
		return (-1);
	nbr_strs = ft_split(line, ' ');
	if (!nbr_strs)
		return (free(line), -1);
	i = 0;
	while (i < data->row_len && nbr_strs[i])
	{
		if (fill_point(data, row_i, i++, nbr_strs))
			return (free_matrix((void **)nbr_strs), -1);
	}
	return (free(line), free_matrix((void **)nbr_strs), 0);
}

void	make_matrix(t_data *data, char *file_path)
{
	ssize_t	i;
	int		fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		handle_error("error opening file", data, -1);
	data->matrix = (int **)ft_calloc(sizeof(int *), data->col_len + 1);
	data->colors = (int **)ft_calloc(sizeof(int *), data->col_len + 1);
	if (!data->matrix || !data->colors)
		handle_error("memory allocation error", data, fd);
	i = 0;
	while (i < data->col_len)
	{
		data->matrix[i] = (int *)ft_calloc(sizeof(int), data->row_len);
		data->colors[i] = (int *)ft_calloc(sizeof(int), data->row_len);
		if (!data->colors || !data->matrix[i])
			handle_error("memory allocation error", data, fd);
		if (fill_line(data, fd, i))
			handle_error("memory allocation error", data, fd);
		i++;
	}
	close(fd);
}

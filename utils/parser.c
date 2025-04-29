/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:47:37 by maghumya          #+#    #+#             */
/*   Updated: 2025/04/29 19:16:03 by maghumya         ###   ########.fr       */
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

ssize_t	fill_line(t_data *data, int fd, int *row)
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
		row[i] = ft_atoi(nbr_strs[i]);
		i++;
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
	if (!data->matrix)
		handle_error("memory allocation error", data, fd);
	i = 0;
	while (i < data->col_len)
	{
		data->matrix[i] = (int *)ft_calloc(sizeof(int), data->row_len);
		if (!data->matrix[i])
			handle_error("memory allocation error", data, fd);
		if (fill_line(data, fd, data->matrix[i]))
			handle_error("memory allocation error", data, fd);
		i++;
	}
	close(fd);
}

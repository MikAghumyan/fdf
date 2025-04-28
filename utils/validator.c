/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:41:53 by maghumya          #+#    #+#             */
/*   Updated: 2025/04/28 20:50:27 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	validate_file(t_data *data, char *file_path)
{
	int fd;
	char *line;
	int row_len_tmp;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		handle_error("error opening file", NULL);
	data->col_len = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	data->row_len = ft_strlen(line);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->col_len++;
		if (data->row_len != ft_strlen(line))
			return (free(line), 0);
		free(line);
	}
	return (data->col_len);
}
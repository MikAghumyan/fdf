/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:41:53 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/07 17:01:27 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static ssize_t	check_hex(char **s)
{
	if (!s || !*s)
		return (-1);
	if ((*s)[0] == ',' && (*s)[1] == '0' && (*s)[2] == 'x')
	{
		*s += 3;
		while (**s && **s != ' ' && **s != '\n')
		{
			if (!(**s >= '0' && **s <= '9') && !(**s >= 'a' && **s <= 'f')
				&& !(**s >= 'A' && **s <= 'F'))
				return (-1);
			(*s)++;
		}
		return (0);
	}
	return (-1);
}

static ssize_t	count_points(char *s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == ' ' || *s == '\n')
			s++;
		if (*s == '-')
			s++;
		if (*s)
			count++;
		while (*s && (*s != ' ' && *s != '\n'))
		{
			if (!(*s >= '0' && *s <= '9'))
			{
				if (check_hex(&s) == -1)
					return (-1);
			}
			else
				s++;
		}
	}
	return (count);
}

ssize_t	validate_file(t_data *data, char *file_path)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		handle_error("error opening file", NULL, -1);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), -1);
	data->row_len = count_points(line);
	free(line);
	if (data->row_len < 0)
		return (close(fd), -1);
	data->col_len = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->col_len++;
		if (count_points(line) != data->row_len)
			return (close(fd), free(line), -1);
		free(line);
	}
	return (close(fd), data->col_len);
}

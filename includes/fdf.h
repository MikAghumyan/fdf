/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:43:43 by maghumya          #+#    #+#             */
/*   Updated: 2025/04/29 15:17:18 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

typedef struct s_data
{
	int		**matrix;
	ssize_t	row_len;
	ssize_t	col_len;
}			t_data;

void		handle_error(char *err_msg, t_data *data);

ssize_t		validate_file(t_data *data, char *file_path);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:43:43 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/03 21:43:09 by maghumya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

# define WINDOW_X 1980
# define WINDOW_Y 1080

# define ESC_KEY 65307

typedef struct s_data
{
	int		**matrix;
	ssize_t	row_len;
	ssize_t	col_len;

	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

void		handle_error(char *err_msg, t_data *data, int fd);
void		handle_exit(t_data *data, int fd);

ssize_t		validate_file(t_data *data, char *file_path);

int			key_hook(int keycode, t_data *data);
int			win_close_hook(t_data *data);

void		initialize_data(t_data *data);
void		initialize_window(t_data *data);
void		free_window(t_data *data);

void		free_matrix(void **matrix);
ssize_t		fill_line(t_data *data, int fd, int *row);
void		make_matrix(t_data *data, char *file_path);

#endif
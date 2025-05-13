/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghumya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:43:43 by maghumya          #+#    #+#             */
/*   Updated: 2025/05/13 14:25:21 by maghumya         ###   ########.fr       */
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
# include <math.h>
# include <stdio.h>
# include <string.h>

# ifndef WINDOW_X
#  define WINDOW_X 1980
# endif
# ifndef WINDOW_Y
#  define WINDOW_Y 1080
# endif
# ifndef TRANSLATE
#  define TRANSLATE 5
# endif
# ifndef SCALE
#  define SCALE 53
# endif

# define ESC_KEY 65307
# define MINUS_KEY 65453
# define PLUS_KEY 65451
# define ARROW_UP_KEY 65362
# define ARROW_DOWN_KEY 65364
# define ARROW_LEFT_KEY 65361
# define ARROW_RIGHT_KEY 65363
# define T_KEY 116
# define F_KEY 102
# define S_KEY 115
# define I_KEY 105

typedef struct s_data
{
	int		**matrix;
	int		**colors;
	int		def_color;
	ssize_t	row_len;
	ssize_t	col_len;
	int		zoom;
	int		position_x;
	int		position_y;
	int		alpha;
	int		tetha;
	int		gamma;
	int		ortho;

	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_point
{
	int		x;
	int		y;
	int		color;
}			t_point;

typedef struct s_line
{
	t_point	p0;
	t_point	p1;
	t_point	m;
	int		dx;
	int		dy;
	int		dir;
	double	p;
}			t_line;

typedef struct s_rgb
{
	int		red;
	int		green;
	int		blue;
}			t_rgb;

void		swap_line(t_line *line);
t_point		get_isometric(t_data *data, int x, int y, int z);
float		get_line_ratio(t_line *line);
int			get_color(t_line *line);
int			get_random_int(void);

t_point		get_orthographic(t_data *data, int x, int y, int z);
void		draw_orthographic(t_data *data);

void		rotate_z(t_data *data, int *x, int *y);
void		rotate_y(t_data *data, int *x, int *z);
void		rotate_x(t_data *data, int *y, int *z);

void		handle_move(int keycode, t_data *data);
void		handle_view(int keycode, t_data *data);
void		handle_error(char *err_msg, t_data *data, int fd);
void		handle_exit(t_data *data, int fd);

ssize_t		validate_file(t_data *data, char *file_path);

int			key_hook(int keycode, t_data *data);
int			win_close_hook(t_data *data);

void		initialize_data(t_data *data);

void		initialize_image(t_data *data);
void		initialize_window(t_data *data);
void		free_window(t_data *data);

void		pixel_put_image(t_data *data, int x, int y, int color);
void		draw_line(t_data *data, t_line line);
void		draw_mesh(t_data *data);

void		free_matrix(void **matrix);
ssize_t		fill_line(t_data *data, int fd, int row_i);
void		make_matrix(t_data *data, char *file_path);

#endif
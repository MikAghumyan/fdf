#include "../includes/fdf.h"

void	handle_move(int keycode, t_data *data)
{
	int	handled;

	handled = 1;
	if (keycode == PLUS_KEY)
		data->zoom += TRANSLATE;
	else if (keycode == MINUS_KEY)
		data->zoom -= TRANSLATE;
	else if (keycode == ARROW_UP_KEY)
		data->position_y -= TRANSLATE;
	else if (keycode == ARROW_DOWN_KEY)
		data->position_y += TRANSLATE;
	else if (keycode == ARROW_LEFT_KEY)
		data->position_x -= TRANSLATE;
	else if (keycode == ARROW_RIGHT_KEY)
		data->position_x += TRANSLATE;
	else
		handled = 0;
	if (handled)
		initialize_image(data);
}
void	handle_transform(int keycode, t_data *data)
{
	int	handled;
	int	i;
	int	j;

	handled = (keycode == Z_KEY) - (keycode == X_KEY);
	if (handled)
	{
		i = -1;
		while (++i < data->col_len)
		{
			j = -1;
			while (++j < data->row_len)
				if (data->matrix[i][j])
				{
					data->matrix[i][j] += handled;
					if (!data->matrix[i][j])
						data->matrix[i][j] += handled;
				}
		}
		initialize_image(data);
	}
}

void	handle_view(int keycode, t_data *data)
{
	int	handled;

	handled = 1;
	if (keycode == KEY_2)
		data->ortho = 1;
	else if (keycode == KEY_3)
		data->ortho = 2;
	else if (keycode == KEY_4)
		data->ortho = 3;
	else if (keycode == KEY_1)
	{
		data->ortho = 0;
		data->alpha = 0;
		data->tetha = 0;
		data->gamma = 0;
	}
	else
		handled = 0;
	if (handled)
		initialize_image(data);
}

void	handle_rotation(int keycode, t_data *data)
{
	int handled;

	handled = 1;
	if (keycode == A_KEY)
		data->gamma += 0.02;
	else if (keycode == D_KEY)
		data->gamma -= 0.02;
	else if (keycode == W_KEY)
		data->alpha += 0.02;
	else if (keycode == S_KEY)
		data->alpha -= 0.02;
	else if (keycode == Q_KEY)
		data->tetha -= 0.02;
	else if (keycode == E_KEY)
		data->tetha += 0.02;
	else
		handled = 0;
	if (handled)
		initialize_image(data);
}
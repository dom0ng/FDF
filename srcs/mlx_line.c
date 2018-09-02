#include "fdf.h"

static int		mlx_isneg(int nb)
{
	if (nb > 0)
		return (1);
	return (-1);
}

static void		mlx_print_x(t_pos dep, t_pos end, t_lim *win)
{
	int		index;
	int		tmp;

	index = 1;
	tmp = abs(dep.inc_x) / 2;
	while (index <= abs(dep.inc_x))
	{
		dep.x = dep.x + mlx_isneg(dep.inc_x);
		tmp = tmp + abs(dep.inc_y);
		if (tmp >= abs(dep.inc_x))
		{
			tmp = tmp - (abs(dep.inc_x));
			dep.y = dep.y + mlx_isneg(dep.inc_y);
		}
		index++;
		mlx_put_pixel_img(dep.x, dep.y, mlx_colorset(dep.color,
				end.color, (double)index / (double)(abs(dep.inc_x))), win);
	}
}

static void		mlx_print_y(t_pos dep, t_pos end, t_lim *win)
{
	int		index;
	int		tmp;

	index = 1;
	tmp = abs(dep.inc_y) / 2;
	while (index <= abs(dep.inc_y))
	{
		dep.y = dep.y + mlx_isneg(dep.inc_y);
		tmp = tmp + abs(dep.inc_x);
		if (tmp >= abs(dep.inc_y))
		{
			tmp = tmp - (abs(dep.inc_y));
			dep.x = dep.x + mlx_isneg(dep.inc_x);
		}
		index++;
		mlx_put_pixel_img(dep.x, dep.y, mlx_colorset(dep.color,
				end.color, (double)index / (double)(abs(dep.inc_y))), win);
	}
}

void			mlx_line(t_pos dep, t_pos end, t_lim *win)
{
	dep.inc_x = end.x - dep.x;
	dep.inc_y = end.y - dep.y;
	mlx_put_pixel_img(dep.x, dep.y, dep.color, win);
	dep.color_inc = dep.color - end.color;
	if (abs(dep.inc_x) > abs(dep.inc_y))
		mlx_print_x(dep, end, win);
	else
		mlx_print_y(dep, end, win);
}

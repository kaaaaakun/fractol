/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:55:38 by tokazaki          #+#    #+#             */
/*   Updated: 2023/09/29 17:22:32 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_julia(double cre, double cim)
{
	t_vars	vars;

	vars.height = 500;
	vars.width = 500;
	vars.depth = 60;
	vars.color = 0;
	vars.mag = 20;
	vars.ver = 0;
	vars.hor = 0;
	vars.cre = cre;
	vars.cim = cim;
	vars.status = JULIA;
	vars.x = vars.height / 2;
	vars.y = vars.width / 2;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.height, vars.width, "fractal");
	vars.img = mlx_new_image(vars.mlx, vars.height, vars.width);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, \
			&vars.line_length, &vars.endian);
	img_put_m(&vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 0, exit_wind, (void *)&vars);
	mlx_loop(vars.mlx);
	exit(0);
}

void	make_mandel(void)
{
	t_vars	vars;

	vars.height = 500;
	vars.width = 500;
	vars.depth = 60;
	vars.color = 0;
	vars.mag = 20;
	vars.ver = 0;
	vars.hor = 0;
	vars.cre = -1;
	vars.cim = -1;
	vars.status = MANDEL;
	vars.x = vars.height / 2;
	vars.y = vars.width / 2;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.height, vars.width, "fractal");
	vars.img = mlx_new_image(vars.mlx, vars.height, vars.width);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, \
			&vars.line_length, &vars.endian);
	img_put_m(&vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 0, exit_wind, (void *)&vars);
	mlx_loop(vars.mlx);
	exit(0);
}

unsigned int	check_color_j(t_vars *vars, double zre, double zim)
{
	int		i;
	double	tmp;

	i = 0;
	while (zre * zre + zim * zim <= 4 && i < vars->depth)
	{
		tmp = zre * zre - zim * zim + vars->cre;
		zim = 2 * zre * zim + vars->cim;
		zre = tmp;
		i++;
	}
	if (zre * zre + zim * zim > 4)
	{
		if (1 < i)
			return (0x1234567890 + i * 190 + vars->color);
		else
			return (0x0);
	}
	else
		return (0xe2e627 + vars->color);
}

unsigned int	check_color_m(t_vars *vars, double cre, double cim)
{
	int		i;
	double	tmp;
	double	zim;
	double	zre;

	zim = 0;
	zre = 0;
	i = 0;
	while (zre * zre + zim * zim <= 4 && i < vars->depth)
	{
		tmp = zre * zre - zim * zim + cre;
		zim = 2 * zre * zim + cim;
		zre = tmp;
		i++;
	}
	if (zre * zre + zim * zim > 4)
	{
		if (1 < i)
			return (0x1234567890 + i * 190 + vars->color);
		else
			return (0x0);
	}
	else
		return (0xe2e627 + vars->color);
}

void	img_put_m(t_vars *vars)
{
	int		row;
	int		col;
	int		color;
	double	x;
	double	y;

	row = 0;
	while (row < vars->height)
	{
		col = 0;
		while (col < vars->width)
		{
			x = (col - vars->x + vars->hor) / (vars->width / vars->mag);
			y = (row - vars->y + vars->ver) / (vars->height / vars->mag);
			if (vars->status == MANDEL)
				color = check_color_m(vars, x, y);
			if (vars->status == JULIA)
				color = check_color_j(vars, x, y);
			my_mlx_pixel_put(vars, col, row, color);
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:55:38 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/07 15:23:18 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	make_mandel(void)
{
	t_vars	vars;

	vars.height = 500;
	vars.width = 500;
	vars.depth = 25;
	vars.mag = 20;
	vars.ver = 0;
	vars.hor = 0;
	vars.x = vars.height / 2;
	vars.y = vars.width / 2;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.height, vars.width, "fractal");
	img_put_m(&vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 0, exit_wind, (void *)&vars);
	mlx_loop(vars.mlx);
	exit(0);
}

void	img_put_m(t_vars *vars)
{
	int	row = 0;
	int	col = 0;

	while (row < vars->height)
	{
		col = 0;
		while (col < vars->width)
		{
			double	cre = (col - vars->x + vars->hor) / (vars->width / vars->mag);
			double	cim = (row - vars->y + vars->ver) / (vars->height / vars->mag);
			double	xx = 0;
			double	yy = 0;
			int		i = 0;

			//vars->depth = vars->width / 10 / vars->mag ;
			//printf("[cre:%f,cim:%f]\n",cre,cim);
			while(xx * xx + yy * yy <= 4 && i < vars->depth)
			{
				double	tmpx = xx * xx - yy * yy + cre;
				yy = 2 * xx * yy + cim;
				xx = tmpx;
				i++;
			}
			if (xx * xx + yy * yy > 4)
			{
				if (1 < i)
					mlx_pixel_put(vars->mlx, vars->win, col , row,  0x0 + i * 190);
				else
					mlx_pixel_put(vars->mlx, vars->win, col, row, 0x3333333);
			}
			else
				mlx_pixel_put(vars->mlx, vars->win, col, row,  0xe2e627);
			col++;
		}
		row++;
	}
}

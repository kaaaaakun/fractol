/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:50:16 by tokazaki          #+#    #+#             */
/*   Updated: 2023/09/29 17:22:29 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//キーボードによる入力を判定する関数
int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 123)
	{
		vars->color += 10;
		vars->hor -= 25;
	}
	if (keycode == 124)
	{
		vars->color += 10;
		vars->hor += 25;
	}
	if (keycode == 126)
	{
		vars->color += 10;
		vars->ver -= 25;
	}
	if (keycode == 125)
	{
		vars->color -= 10;
		vars->ver += 25;
	}
	if (keycode == 53)
		return (esc_close (keycode, vars));
	img_put_m(vars);
	return (0);
}

//マウス操作による入力を判定する関数
int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (vars->mag == 0.0)
		vars->mag = 0.000001;
	if (button == 4)
	{
		vars->mag *= 1.2;
	}
	else if (button == 5)
	{
		vars->mag *= 0.8;
	}
	else
		return (0);
	img_put_m(vars);
	return (0);
}

//escで画面を閉じる関数
int	esc_close(int keycode, t_vars *vars)
{
	(void) keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

//win上のxボタンをしても正常終了する関数
int	exit_wind(t_vars *vars)
{
	(void)vars;
	exit(0);
}

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

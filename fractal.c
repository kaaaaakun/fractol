/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:50:16 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/07 15:22:19 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

//キーボードによる入力を判定する関数
int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook![%d]\n", keycode);
	if (keycode == 123)
		vars->hor += 25;
	if (keycode == 124)
		vars->hor -= 25;
	if (keycode == 126)
		vars->ver += 25;
	if (keycode == 125)
		vars->ver -= 25;
	if (keycode == 53)
		return(esc_close(keycode, vars));
	img_put_m(vars);
	return (0);
}

//マウス操作による入力を判定する関数
int mouse_hook(int button, int x, int y, t_vars *vars)
{
	x = vars->width - x;
    if (button == 4)
    {
        vars->mag *= 1.2;
		//vars->x = x - (x - vars->x) * 1.2;
		///vars->y = y - (y - vars->y) * 1.2;
    }
    else if (button == 5)
    {
        vars->mag *= 0.8;
       // vars->x = x + (x - vars->x) * 0.8;
       // vars->y = y - (y - vars->y) * 0.8;
    }
    else
    {
        return (0);
    }
    printf("Hello from mouse_hook![button:%d][x:%d][y:%d][va->x:%f][va->y:%f][mag:%f]\n", button, x, y, vars->x, vars->y, vars->mag);
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



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:46:27 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/07 15:25:51 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <limits.h>

typedef struct	s_vars {
	void	*mlx;		//初期化
	void	*win;		//画面のアドレス
	int		height;		//画面の高さ
	int		width;		//画面の幅
	double	depth;		//フラクタルの計算回数
	double	x;			//中心点のx座標
	double	y;			//中心点のy座標
	int		ver;		//中心点のx座標の位置
	int		hor;		//中心点のy座標のいち
	double	mag;		//拡大率
}	t_vars;

int	main(int argc,char *argv[]);
int		exit_wind(t_vars *vars);
int 	mouse_hook(int button, int x, int y, t_vars *vars);
int		esc_close(int keycode, t_vars *vars);

int	key_hook(int keycode, t_vars *vars);
void	make_mandel(void);
void	img_put_m(t_vars *vars);

#endif


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:46:27 by tokazaki          #+#    #+#             */
/*   Updated: 2023/09/29 17:22:30 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

# define MANDEL 1
# define JULIA 2

typedef struct s_vars {
	void			*mlx;
	void			*win;
	struct s_vars	*img;
	char			*addr;
	int				height;
	int				width;
	int				color;
	int				status;
	double			cre;
	double			cim;
	double			depth;
	double			x;
	double			y;
	int				ver;
	int				hor;
	double			mag;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_vars;

int		main(int argc, char *argv[]);
int		exit_wind(t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);
int		esc_close(int keycode, t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
void	make_mandel(void);
void	make_julia(double cre, double cim);
void	img_put_m(t_vars *vars);
void	img_put_j(t_vars *vars);
int		error_massage(void);
int		my_atof(char *chr, double *num);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);

#endif

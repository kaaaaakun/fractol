/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:01:54 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/07 15:28:09 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q fractal");
}

int	main(int argc,char *argv[])
{
	int	i;

	char	mandel[] = "Mandelbrot";
//	char	julia[] = "Julia";
	i = 0;
	if (argc == 2)
	{
		while(argv[1][i] == mandel[i])
			i++;
		if (i == 11)
			make_mandel();
		printf("[%d]\n",i);
	}
//	if (argc == 3)
//	{
//		while(argv[1][i] == julia[i])
//			i++;
//		if (i == 6)
//			make_julia(argv[2]);
//		printf("[%d]\n",i);
//	}
	if (argc != 2)
	printf("plese collect word\n	Mandelbrot\n	");
	return(0);
}

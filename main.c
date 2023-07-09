/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:01:54 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/10 00:54:42 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

//__attribute__((destructor))
//static void destructor() {
//    system("leaks -q fractal");
//}

int	main(int argc, char *argv[])
{
	int		i;
	double	cre;
	double	cim;
	int		check_cim;
	int		check_cre;

	i = 0;
	if (argc == 2 && argv[1][0] == 'm' && argv[1][1] == '\0')
		make_mandel();
	else if (argc == 4 && argv[1][0] == 'j' && argv[1][1] == '\0')
	{
		check_cre = my_atof(argv[2], &cre);
		check_cim = my_atof(argv[3], &cim);
		if (check_cre == 0 || check_cim == 0)
			return (error_massage());
		make_julia(cre, cim);
	}
	return (error_massage());
}

int	my_atof(char *chr, double *num)
{
	int	i;

	i = 0;
	if (5 < ft_strlen(chr))
		return (0);
	while (chr[i])
	{
		if (!('0' <= chr[i] && chr[i] <= '9') && chr[i] != '-')
			return (0);
		i++;
	}
	*num = (double)ft_atoi(chr) / 1000;
	return (1);
}

int	error_massage(void)
{
	printf("Please enter correct value\n	m = Mandelbrot\n\
	j = Julia\n	EX: ./fractal j -345 654\n");
	return (0);
}

size_t	ft_strlen(const char *src)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	while (src[i])
		i++;
	return (i);
}

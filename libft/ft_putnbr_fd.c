/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:58:06 by tokazaki          #+#    #+#             */
/*   Updated: 2023/05/28 10:56:09 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	wrt(int b, int fd)
{
	char	a;

	a = b + 48;
	write (fd, &a, 1);
}

void	ft_putnbr_fd(int c, int fd)
{
	int	tmp;

	if (fd < 0)
		return ;
	if (c == -2147483648)
	{
		write (fd, "-", 1);
		wrt(2, fd);
		ft_putnbr_fd (147483648, fd);
	}
	else if (c < 0)
	{
		write(fd, "-", 1);
		c = c * -1;
		ft_putnbr_fd(c, fd);
	}
	else if (0 <= c && c <= 9)
		wrt(c, fd);
	else
	{
		tmp = c % 10;
		ft_putnbr_fd (c / 10, fd);
		wrt(tmp, fd);
	}
}

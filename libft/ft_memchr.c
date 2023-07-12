/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:15:00 by tokazaki          #+#    #+#             */
/*   Updated: 2023/06/04 14:30:47 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char	chr;

	if (s == NULL)
		return (NULL);
	chr = (char)c;
	str = (char *)s;
	while (n--)
	{
		if (*str == chr)
			return (str);
		str++;
	}
	return (NULL);
}

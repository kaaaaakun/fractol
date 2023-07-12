/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:39:56 by tokazaki          #+#    #+#             */
/*   Updated: 2023/06/04 14:05:01 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	chr;

	if (!s)
		return (NULL);
	str = (char *)s;
	chr = (char)c;
	while (*str || chr == '\0')
	{
		if (*str == chr)
			return (str);
		str++;
	}
	return (NULL);
}

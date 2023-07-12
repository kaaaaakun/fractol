/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:56:19 by tokazaki          #+#    #+#             */
/*   Updated: 2023/05/23 19:02:53 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	chr;
	size_t	len;

	if (s == NULL )
		return (NULL);
	str = (char *)s;
	chr = (char)c;
	len = ft_strlen(str);
	if (chr == '\0')
		return (&str[len]);
	while (len--)
	{
		if (str[len] == chr)
			return (&str[len]);
	}
	return (NULL);
}

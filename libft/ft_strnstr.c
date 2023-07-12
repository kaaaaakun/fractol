/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:22:24 by tokazaki          #+#    #+#             */
/*   Updated: 2023/06/06 20:40:05 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*str;
	char	*need;

	if (haystack == NULL || needle == NULL)
		return (NULL);
	str = (char *)haystack;
	need = (char *)needle;
	if (*need == '\0')
		return (str);
	while (len && *str != '\0')
	{
		i = 0;
		while (str[i] == need[i] && i < len)
		{
			i ++;
			if (need[i] == '\0')
				return (str);
		}
		str++;
		len--;
	}
	return (NULL);
}

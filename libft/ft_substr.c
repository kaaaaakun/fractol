/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:47:44 by tokazaki          #+#    #+#             */
/*   Updated: 2023/06/06 21:27:44 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	length;
	char			*result;
	char			*str;

	str = (char *)s;
	if (s == NULL)
		return (NULL);
	length = ft_strlen((char *)s);
	if (len == 0 || length <= start)
		return (ft_strdup (""));
	length = ft_strlen(&str[start]);
	if (len < length)
		length = len;
	result = (char *)ft_calloc(length + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	return (ft_memcpy(result, &str[start], length));
}
//s文字列のstart番目からlen文字分or *s=='\0'になる文字列分コピー
//24:
//25:
//27:
//28-29:
//30:
//33:

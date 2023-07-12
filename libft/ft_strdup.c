/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:21:13 by tokazaki          #+#    #+#             */
/*   Updated: 2023/06/06 20:42:16 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*result;

	if (!src)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (result == 0)
		return (NULL);
	ft_memcpy(result, src, (ft_strlen(src) + 1));
	return (result);
}

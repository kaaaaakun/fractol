/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:44:32 by tokazaki          #+#    #+#             */
/*   Updated: 2023/06/06 22:04:36 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
//'\0'が現れるまでの文字数をカウント
//19-20:本家にはないエラー処理追加
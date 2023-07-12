/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:06:53 by tokazaki          #+#    #+#             */
/*   Updated: 2023/05/30 11:19:11 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intcount(int nbr);
static void		ft_pucpynbr(int nbr, char *str);
static void		ft_micpynbr(int nbr, char *str);

char	*ft_itoa(int nbr)
{
	char	*result;
	size_t	len;
	int		flag;

	flag = 0;
	len = ft_intcount(nbr);
	result = (char *)ft_calloc(len + 1, sizeof(char));
	if (result == 0)
		return (NULL);
	if (0 <= nbr)
		ft_pucpynbr(nbr, &result[len - 1]);
	else
		ft_micpynbr(nbr, &result[len - 1]);
	return (result);
}

static size_t	ft_intcount(int nbr)
{
	size_t	count;

	count = 0;
	while (1)
	{
		if (-9 <= nbr && nbr < 0)
			return (count + 2);
		if (0 <= nbr && nbr <= 9)
			return (count + 1);
		nbr = nbr / 10;
		count++;
	}
}

static void	ft_pucpynbr(int nbr, char *str)
{
	if (nbr <= 0 && nbr <= 9)
		*str = nbr + 48;
	else
	{
		*str = nbr % 10 + 48;
		ft_pucpynbr(nbr / 10, str - 1);
	}
}

static void	ft_micpynbr(int nbr, char *str)
{
	if (-9 <= nbr && nbr < 0)
	{
		*str = -nbr + 48;
		str--;
		*str = '-';
	}
	else
	{
		*str = (nbr % 10) * -1 + 48;
		ft_micpynbr(nbr / 10, str - 1);
	}
}
//intの値をcahrに変更する機構
//26,37:int型が何文字分あるのかをカウント
//27:文字数＋'\0'分をmalloc
//30,53:値が'+'だった時の処理(再起)
//33,64:値が'-'だった時の処理
//＊最後の一桁になった時にif文で処理を終わる

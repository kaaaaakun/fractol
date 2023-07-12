/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:52:37 by tokazaki          #+#    #+#             */
/*   Updated: 2023/06/04 14:28:51 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				ft_isspace(int c);
static long long int	minus_atoi(const char *str);
static long long int	plus_atoi(const char *str);

int	ft_atoi(const char *str)
{
	size_t			i;
	int				flag;
	long long int	nbr;

	i = 0;
	nbr = 0;
	flag = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		str++;
		return ((int)minus_atoi(str));
	}
	else if (*str == '+')
		str++;
	return ((int)plus_atoi(str));
}

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n'
		|| c == '\t' || c == '\r'
		|| c == '\f' || c == '\v')
		return (1);
	return (0);
}

static long long int	plus_atoi(const char *str)
{
	long long int	result;
	long long int	l_divis;
	char			l_remain;

	result = 0;
	l_divis = LONG_MAX / 10;
	l_remain = LONG_MAX % 10 + '0';
	while (ft_isdigit(*str))
	{
		if ((l_divis == result && l_remain < *str)
			|| l_divis < result)
			return (LONG_MAX);
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}

static long long int	minus_atoi(const char *str)
{
	long long int	result;
	long long int	l_divis;
	char			l_remain;

	result = 0;
	l_divis = LONG_MIN / 10;
	l_remain = (LONG_MIN % 10 * -1) + '0';
	while (ft_isdigit(*str))
	{
		if ((l_divis == result && l_remain < *str)
			|| l_divis > result)
			return (LONG_MIN);
		result = result * 10 - (*str - '0');
		str++;
	}
	return (result);
}
//intをcharに変換
//40:スペース系のものをスキップ
//30:intの値の±を判定して、それぞれ別の関数に飛ばす
//49,69:±をcharに変換する機構
//60,80:LONG_MAX/LONG_MINをオーバーフローして時は
//		オーバーフロー前の値を返すので、
//		その仕様に倣って実装
//※どのみち返り値はintなので、longからintにキャストした時点で
//intでオーバーフローした値は変な感じにはなる。

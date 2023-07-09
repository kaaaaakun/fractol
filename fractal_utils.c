/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:40:22 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/10 00:47:26 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

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

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:58:06 by tokazaki          #+#    #+#             */
/*   Updated: 2023/06/06 22:04:49 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char *str, int c);
static void	ft_strdup_cpy(char *str, char **result, char c);
static void	*free_split(char **result);

char	**ft_split(const char *str, char c)
{
	char	**result;

	if (!str)
		return (NULL);
	if (*str == '\0' || ft_count((char *)str, c) == 0)
	{
		result = (char **)ft_calloc (1, sizeof(char **));
		if (! (result))
			return (NULL);
		return (result);
	}
	result = (char **)ft_calloc (ft_count((char *)str, c) + 1, sizeof(char **));
	if (result == NULL)
		return (NULL);
	if (ft_count((char *)str, c) == 0 || c == '\0')
	{
		result[0] = (char *)ft_calloc(ft_strlen((char *)str) + 1, sizeof(char));
		ft_memcpy(result[0], str, ft_strlen((char *)str));
	}
	else
		ft_strdup_cpy((char *)str, result, c);
	if (result[ft_count((char *)str, c) - 1] == NULL)
		return (free_split(result));
	return (result);
}

static int	ft_count(char *str, int c)
{
	size_t	count;

	count = 0;
	while (*str == c && *str != '\0')
		str++;
	while (*str != '\0')
	{
		if (*str != c && *str != '\0')
		{
			count++;
			while (*str != c && *str != '\0')
				str++;
		}
		while (*str == c && *str != '\0')
			str++;
	}
	return (count);
}

void	ft_strdup_cpy(char *str, char **result, char c)
{
	char	*word_start;
	size_t	i;

	i = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			word_start = str;
			while (*str && *str != c)
				str++;
			result[i] = (char *)ft_calloc (str - word_start + 1, sizeof(char));
			if (result[i] == NULL)
				return ;
			ft_memcpy (result[i], word_start, str - word_start);
			i++;
		}
	}
}

static void	*free_split(char **result)
{
	size_t	i;

	i = 0;
	while (result[i])
	{
		free (result[i]);
		i++;
	}
	free (result);
	return (NULL);
}

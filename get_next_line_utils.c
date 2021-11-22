/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:15:59 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/19 21:30:08 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_stock(char *buff, char const *str, size_t start, size_t len)
{
	size_t	index;

	index = 0;
	while (str[index] && index < len)
	{
		buff[index] = str[start];
		start++;
		index++;
	}
	buff[index] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buff;
	size_t	index;

	buff = (void *)0;
	if (s == NULL)
		return (NULL);
	index = ft_strlen(s);
	if (index == 0 || start >= index)
	{
		buff = (char *)malloc(1 * sizeof(char));
		*buff = '\0';
		return (buff);
	}
	if (index < len)
		len = index;
	buff = (char *)malloc((len + 1) * sizeof(char));
	if (!buff)
		return (buff);
	ft_stock(buff, s, start, len);
	return (buff);
}

char	*ft_strdup(const char *s1)
{
	char	*buff;
	int		len;

	buff = (void *)0;
	len = ft_strlen(s1);
	buff = (char *)malloc((len + 1) * sizeof(char));
	if (!buff)
		return (buff);
	len = -1;
	while (s1[++len])
		buff[len] = s1[len];
	buff[len] = '\0';
	return (buff);
}

static void	ft_stock_join(char const *str_1, char const *str_2, char *str_new)
{
	int		index_1;
	int		index_2;

	index_1 = 0;
	while (str_1[index_1])
	{
		str_new[index_1] = str_1[index_1];
		index_1++;
	}
	index_2 = 0;
	while (str_2[index_2])
	{
		str_new[index_1] = str_2[index_2];
		index_1++;
		index_2++;
	}
	str_new[index_1] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (void *)0;
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	str = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_stock_join(s1, s2, str);
	return (str);
}

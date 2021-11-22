/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 02:23:00 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/20 16:31:27 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int		index;

	index = 0;
	while (s[index] != (char)c && s[index])
		index++;
	if (s[index] == (char)c)
		return ((char *)s + index);
	return (0);
}

int	ft_strlen(const char *str)
{
	int		index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

int	ft_bufflen(char *buff)
{
	int		index;

	index = 0;
	while (buff[index] != '\n' && buff[index])
		index++;
	return (index);
}

static char	*ft_stock_and_return(char **s, int r_read, char *buff)
{
	int		len;
	char	*tmp;
	char	*tmp_1;

	free(buff);
	if (!(*s) || r_read < 0)
		return (NULL);
	len = ft_bufflen(*s);
	tmp = ft_substr(*s, 0, len + 1);
	tmp_1 = ft_substr(*s, len + 1, ft_strlen(*s) - len);
	free(*s);
	if (tmp_1[0] == '\0')
	{
		*s = NULL;
		free(tmp_1);
	}
	else
		*s = tmp_1;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char		*s[255];
	char			*buff;
	char			*tmp;
	int				r_read;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	r_read = read(fd, buff, BUFFER_SIZE);
	while (r_read > 0)
	{
		buff[r_read] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup(buff);
		else if (buff)
		{
			tmp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n') != NULL)
			break ;
		r_read = read(fd, buff, BUFFER_SIZE);
	}
	return (ft_stock_and_return(&s[fd], r_read, buff));
}

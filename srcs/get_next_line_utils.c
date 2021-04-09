/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:45:18 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:39:43 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*str;

	len = ft_strlen(s);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	len = 0;
	while (s[len])
	{
		str[len] = s[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_strcpy(const char *src, char *dst)
{
	int	i;

	i = 0;
	if (!src || !dst)
		return (NULL);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_strchrn(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strcat(char *dst, char *src)
{
	int		dlen;
	int		slen;
	char	*tmp;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	tmp = NULL;
	if (dst)
		tmp = dst;
	dst = malloc(dlen + slen + 1);
	if (!dst)
		return (NULL);
	if (tmp)
		dst = ft_strcpy(tmp, dst);
	slen = -1;
	while (src[++slen])
		dst[dlen + slen] = src[slen];
	dst[slen + dlen] = '\0';
	return (dst);
}

int	ft_add_line(char **line, char *buff, int n)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strcat(*line, buff);
	if (!*line)
		n = -2;
	if (tmp)
		free(tmp);
	return (n);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:32:13 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:40:18 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

int		get_num(int i, const char *text, int *n)
{
	while (ft_isdigit(text[i]))
	{
		*n = *n * 10 + (text[i] - '0');
		i++;
	}
	return (i);
}

int		get_n(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		get_len(const char *str)
{
	int i;
	int end;
	int del;

	i = 0;
	end = 0;
	del = 0;
	while (str[i] && str[i] != '\n')
	{
		if (!(ft_isspace(str[i])) && end == 1)
			return (-1);
		if (ft_isspace(str[i]))
		{
			del++;
			end = 1;
		}
		i++;
	}
	return (i - del);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	res;

	i = 0;
	if (!dst || !src)
		return (0);
	if (!dstsize)
		return (ft_strlen(src));
	res = ft_strlen(src);
	while (i < res && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (res);
}

char	*ft_strcat_text(char *dst, char *src)
{
	size_t	dlen;
	size_t	slen;
	char	*tmp;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	tmp = NULL;
	if (dst)
	{
		tmp = ft_strdup(dst);
		free(dst);
	}
	if (!(dst = malloc(dlen + slen + 2)))
		return (NULL);
	if (tmp)
	{
		dst = ft_strcpy(tmp, dst);
		free(tmp);
	}
	slen = -1;
	dst[dlen] = '\n';
	while (src[++slen])
		dst[dlen + slen + 1] = src[slen];
	dst[slen + dlen + 1] = '\0';
	return (dst);
}

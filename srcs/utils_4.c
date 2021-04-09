/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:37:30 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/09 16:37:31 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat_copy(char *dst, const char *src, int dlen)
{
	int	slen;

	slen = -1;
	dst[dlen] = '\n';
	while (src[++slen])
		dst[dlen + slen + 1] = src[slen];
	dst[slen + dlen + 1] = '\0';
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:37:49 by lcierra           #+#    #+#             */
/*   Updated: 2020/11/24 18:01:08 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

int	copy_saver(char *saver, char **line)
{
	int	n;

	n = ft_strchrn(saver);
	if (n != -1)
	{
		saver[n] = '\0';
		*line = ft_strdup(saver);
		if (!*line)
		{
			free(saver);
			return (-2);
		}
		ft_strcpy(saver + n + 1, saver);
	}
	else
	{
		*line = ft_strdup(saver);
		if (!*line)
		{
			free(saver);
			return (-2);
		}
		free(saver);
	}
	return (n);
}

int	check_saver(char *saver, char **line)
{
	int	n;

	n = -1;
	if (saver)
		n = copy_saver(saver, line);
	else
	{
		*line = malloc(1);
		*line[0] = '\0';
	}
	return (n);
}

int	gnl_return(int n, int len, char *buff)
{
	free(buff);
	if (n == -2 || len == -1)
		return (-1);
	if ((len < 32 && len != 0) || n != -1)
		return (1);
	return (0);
}

int	gnl_init(char **line, char **buff, char **saver)
{
	int	n;

	if (!line)
		return (-1);
	*buff = malloc(33);
	if (!*buff)
		return (-1);
	n = check_saver(*saver, line);
	if (n == -1)
		saver = NULL;
	return (n);
}

int	get_next_line(int fd, char **line)
{
	static char	*saver;
	char		*buff;
	int			len;
	int			n;

	n = gnl_init(line, &buff, &saver);
	while (n == -1)
	{
		len = (int)read(fd, buff, 32);
		if (len <= 0)
			break ;
		buff[len] = '\0';
		n = ft_strchrn(buff);
		if (n != -1)
		{
			buff[n] = '\0';
			saver = ft_strdup(buff + n + 1);
			if (!saver)
				n = -2;
		}
		n = ft_add_line(line, buff, n);
	}
	return (gnl_return(n, len, buff));
}

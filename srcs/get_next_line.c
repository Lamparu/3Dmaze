/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:37:49 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:39:45 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/get_next_line.h"

int	ft_free(char *str)
{
	free(str);
	return (-2);
}

int	check_saver(char *saver, char **line)
{
	int n;

	n = -1;
	if (saver)
	{
		if ((n = ft_strchrn(saver)) != -1)
		{
			saver[n] = '\0';
			if (!(*line = ft_strdup(saver)))
				return (ft_free(saver));
			ft_strcpy(saver + n + 1, saver);
		}
		else
		{
			if (!(*line = ft_strdup(saver)))
				return (ft_free(saver));
			free(saver);
		}
	}
	else
	{
		*line = malloc(1);
		*line[0] = '\0';
	}
	return (n);
}

int	ft_add_line(char **line, char *buff, int n)
{
	char *tmp;

	tmp = *line;
	if (n == -2 || !(*line = ft_strcat(*line, buff)))
		n = -2;
	if (tmp)
		free(tmp);
	return (n);
}

int	get_next_line(int fd, char **line)
{
	static char	*saver;
	char		*buff;
	int			len;
	int			n;

	if ((BUFFER_SIZE < 1) || !line || !(buff = malloc(BUFFER_SIZE + 1)))
		return (-1);
	if ((n = check_saver(saver, line)) == -1)
		saver = NULL;
	while ((n == -1) && ((len = read(fd, buff, BUFFER_SIZE)) > 0))
	{
		buff[len] = '\0';
		if ((n = ft_strchrn(buff)) != -1)
		{
			buff[n] = '\0';
			if (!(saver = ft_strdup(buff + n + 1)))
				n = -2;
		}
		n = ft_add_line(line, buff, n);
	}
	free(buff);
	if (n == -2 || len == -1)
		return (-1);
	return (((len < BUFFER_SIZE && len != 0) || n != -1) ? 1 : 0);
}

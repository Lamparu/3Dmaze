/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:31:01 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:39:58 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

int	check_digit(const char *str, int i)
{
	if (ft_isdigit(str[i]))
		return (0);
	else
		return (-1);
}

int	check_color(const char *str, int i, int *color, char c)
{
	i = check_spaces(i, str);
	*color = check_digit(str, i);
	i = get_num(i, str, color);
	i = check_spaces(i, str);
	if (c == 'R' || c == 'G')
		i = check_comma(str, i);
	return (i);
}

int	check_comma(const char *str, int i)
{
	if (str[i])
	{
		if (str[i] == ',')
			i++;
		else
			return (-1);
	}
	return (i);
}

int	check_spaces(int i, const char *text)
{
	while (ft_isspace(text[i]))
		i++;
	return (i);
}

int	check_open_tex(char *path, char *tex)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nWrong path to %s texture", tex);
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

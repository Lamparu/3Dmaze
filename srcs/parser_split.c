/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:31:20 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:40:05 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

int		check_line_spaces(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

char	**ft_split(char *str)
{
	int		len;
	int		i;
	int		n_str;
	char	**arr;

	i = -1;
	if (!(n_str = check_before_split(str)))
		return (NULL);
	if (!(arr = malloc(sizeof(char *) * (n_str + 1))))
	{
		printf("Error\nMalloc error");
		return (NULL);
	}
	while (++i < n_str)
	{
		len = ft_split_lenstr(str);
		if (!(arr[i] = malloc(sizeof(char) * (len + 1))))
			return (ft_split_error(arr, i - 1, "Malloc"));
		ft_strlcpy(arr[i], str, len + 1);
		if (check_line_spaces(arr[i]))
			return (ft_split_error(arr, i, "Map content"));
		str += len + 1;
	}
	arr[n_str] = NULL;
	return (arr);
}

int		check_before_split(char *str)
{
	int n_str;

	n_str = get_num_str(str);
	if (n_str < 3)
	{
		printf("Error\nMap content error");
		return (0);
	}
	return (n_str);
}

int		ft_split_lenstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

/*
** To count last \n as valid
** if (str[i - 1] != '\n')
**		res++;
*/

int		get_num_str(const char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] == '\n')
		i++;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			res++;
			i = check_spaces(i, str);
			if (str[i + 1] && str[i + 1] == '\n')
				return (-1);
		}
		i++;
	}
	res++;
	if (str[i - 1] == '\n')
		return (0);
	return (res);
}

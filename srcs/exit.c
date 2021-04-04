/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:30:24 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:39:39 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

int		ft_exit(t_all *all)
{
	all->on = 0;
	return (0);
}

void	exit_err(t_all *all, char *er, int ner)
{
	if (er)
		printf("Error\n%s", er);
	all_destroy(all);
	exit(ner);
}

void	exit_screenshot(t_all *all, int fd, char *er)
{
	printf("Error\n%s", er);
	all_destroy(all);
	if (fd > 0)
		close(fd);
	exit(2);
}

char	**ft_split_error(char **arr, int n, char *er)
{
	int	i;

	i = 0;
	printf("Error\n%s error", er);
	if (!arr)
		return (NULL);
	while (i <= n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

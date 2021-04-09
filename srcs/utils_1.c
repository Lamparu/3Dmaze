/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:32:05 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:40:15 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*(str + i) = 0;
		i++;
	}
}

char	*get_img_path(t_all *all, int i)
{
	if (i == 0)
		return (all->info->text->no);
	if (i == 1)
		return (all->info->text->ea);
	if (i == 2)
		return (all->info->text->so);
	if (i == 3)
		return (all->info->text->we);
	if (i == 4)
		return (all->info->text->sprite);
	return (NULL);
}

double	ft_abs(double n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}

int	get_color(t_color *c)
{
	return ((c->red << 16) | (c->green << 8) | (c->blue << 0));
}

t_all	*bubble_sort(t_all *all)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < all->snum - 1)
	{
		j = all->snum - 1;
		while (j > i)
		{
			if (all->sprs[j - 1].dst < all->sprs[j].dst)
			{
				tmp = all->sprs[j - 1];
				all->sprs[j - 1] = all->sprs[j];
				all->sprs[j] = tmp;
			}
			j--;
		}
		i++;
	}
	return (all);
}

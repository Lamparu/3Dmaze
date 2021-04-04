/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:31:31 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 22:48:08 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

int		fill_header(int fd, int size)
{
	BYTE	header[14];

	ft_bzero(header, 14);
	header[0] = (BYTE)'B';
	header[1] = (BYTE)'M';
	header[2] = (BYTE)size;
	header[3] = (BYTE)(size >> 8);
	header[4] = (BYTE)(size >> 16);
	header[5] = (BYTE)(size >> 24);
	header[10] = (BYTE)(54);
	if (write(fd, header, 14) < 0)
		return (0);
	return (1);
}

int		fill_info(int fd, int w, int h)
{
	BYTE info[40];

	ft_bzero(info, 40);
	info[0] = (BYTE)(40);
	info[4] = (BYTE)w;
	info[5] = (BYTE)(w >> 8);
	info[6] = (BYTE)(w >> 16);
	info[7] = (BYTE)(w >> 24);
	info[8] = (BYTE)h;
	info[9] = (BYTE)(h >> 8);
	info[10] = (BYTE)(h >> 16);
	info[11] = (BYTE)(h >> 24);
	info[12] = (BYTE)1;
	info[14] = (BYTE)(24);
	if (write(fd, info, 40) < 0)
		return (0);
	return (1);
}

int		fill_img(int fd, int w, int h, t_all *all)
{
	int		i;
	int		j;
	BYTE	data[3];
	BYTE	zero[3];
	int		add_zero;

	add_zero = (4 - (w * 3) % 4) % 4;
	ft_bzero(data, 3);
	ft_bzero(zero, 3);
	i = -1;
	while (++i < h)
	{
		j = -1;
		while (++j < w)
		{
			data[0] = (BYTE)(((int*)all->win->addr)[(h - i) * w + j]);
			data[1] = (BYTE)((((int*)all->win->addr)[(h - i) * w + j]) >> 8);
			data[2] = (BYTE)((((int*)all->win->addr)[(h - i) * w + j]) >> 16);
			if (write(fd, data, 3) < 0)
				return (0);
		}
		if (write(fd, &zero, add_zero) < 0)
			return (0);
	}
	return (1);
}

void	screenshot(t_all *all)
{
	int fd;
	int size;
	int add_zero;

	if (all->on != 1)
		exit_err(all, "No window", 3);
	fd = open("screenshot.bmp", O_WRONLY | O_CREAT, S_IREAD | S_IWRITE);
	if (fd < 0)
		exit_screenshot(all, fd, "Can't create screenshot file");
	add_zero = (4 - (all->info->r_x * 3 * all->info->r_y) % 4) % 4;
	size = 54 + 3 * (all->info->r_x + add_zero) * all->info->r_y;
	if (!(fill_header(fd, size)))
		exit_screenshot(all, fd, "Write header error");
	if (!fill_info(fd, all->info->r_x, all->info->r_y))
		exit_screenshot(all, fd, "Write info error");
	if (!fill_img(fd, all->info->r_x, all->info->r_y, all))
		exit_screenshot(all, fd, "Write img data error");
	close(fd);
}

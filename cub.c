/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:32:21 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:40:19 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head/cub.h"

t_all	*print_window(char *fn)
{
	t_all	*all;

	if (!check_cub(fn))
		exit_err(NULL, "Wrong map file extension", 2);
	all = parse_file(fn);
	all = init_mlx(all);
	all->on = 1;
	all->win->img = mlx_new_image(all->win->mlx, all->info->r_x,
			all->info->r_y);
	if (!all->win->img)
		exit_err(all, "MLX win", 3);
	all->win->addr = mlx_get_data_addr(all->win->img, &all->win->bpp,
			&all->win->line_l, &all->win->en);
	if (!all->win->addr)
		exit_err(all, "MLX addr new win", 3);
	all->zbuf = malloc(sizeof(double) * all->info->r_x);
	if (!all->zbuf)
		exit_err(all, "Malloc zbuf", 1);
	draw_screen(all);
	return (all);
}

t_all	*show_window(char *fn)
{
	t_all	*all;

	all = print_window(fn);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
	return (all);
}

int	main_window(char *map)
{
	t_all	*all;

	all = show_window(map);
	mlx_hook(all->win->win, 2, 0, key_press, all);
	mlx_hook(all->win->win, 3, 0, key_unpress, all);
	mlx_hook(all->win->win, 17, 0, ft_exit, all);
	mlx_loop_hook(all->win->mlx, handle_key, all);
	mlx_loop(all->win->mlx);
	return (0);
}

int	main_picture(char *map, char *save)
{
	t_all	*all;

	if (ft_strcmp(save, "--save") == 0)
	{
		printf("Error\nWrong argument");
		return (1);
	}
	all = print_window(map);
	screenshot(all);
	all->on = 0;
	all_destroy(all);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Error\nNot enough arguments");
		return (1);
	}
	else if (argc == 2)
		return (main_window(argv[1]));
	else if (argc == 3)
		return (main_picture(argv[1], argv[2]));
	else
	{
		printf("Error\nToo many arguments");
		return (1);
	}
}

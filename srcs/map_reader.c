/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:30:50 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:39:56 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

t_map	*get_map_info(const char *text, t_map *map)
{
	size_t	i;
	int		ch;

	i = 0;
	while (text[i])
	{
		while (text[i] == '\n')
			i++;
		if (check_map_begin(text + i))
			break ;
		map = check_letter(text + i, map);
		if (!map)
			return (NULL);
		if ((ch = get_n(text + i)) < 0)
			break ;
		i += ch;
	}
	return (map);
}

char	**cut_map(char *text)
{
	size_t	i;
	char	**nmap;
	int		ch;

	i = 0;
	while (text[i])
	{
		while (text[i] == '\n')
			i++;
		if (check_map_begin(text + i))
			break ;
		if ((ch = get_n(text + i)) < 0)
			break ;
		i += ch;
	}
	nmap = ft_split(text + i);
	return (nmap);
}

void	*err_read_map_info(t_all *all, char *text)
{
	all_destroy(all);
	free(text);
	return (NULL);
}

t_all	*read_map_info(int fd, t_all *all)
{
	char	*line;
	char	*text;
	int		n;

	n = 1;
	text = NULL;
	while (n > 0)
	{
		n = get_next_line(fd, &line);
		text = ft_strcat_text(text, line);
		free(line);
	}
	all->info = get_map_info(text, all->info);
	if (!all->info || !check_map_info(all->info))
		return (err_read_map_info(all, text));
	all->map = cut_map(text);
	if (!all->map)
		return (err_read_map_info(all, text));
	all = get_map_wh(all);
	free(text);
	return (all);
}

t_all	*parse_file(char *fn)
{
	t_all	*all;
	int		fd;

	if ((fd = open(fn, O_RDONLY)) < 0)
	{
		printf("Error\nCan't open map file");
		exit(2);
	}
	if (!(all = init_all()))
	{
		close(fd);
		exit(1);
	}
	all = read_map_info(fd, all);
	close(fd);
	if (!all)
		exit(4);
	all = get_plr(all);
	all = get_sprites(all);
	checker(all);
	return (all);
}

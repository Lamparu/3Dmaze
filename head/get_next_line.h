/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:40:05 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:36:34 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		get_next_line(int fd, char **line);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strcpy(const char *src, char *dst);
int		ft_strchrn(const char *str);
char	*ft_strcat(char *dst, char *src);
int		ft_free(char *str);
int		check_saver(char *saver, char **line);
int		ft_add_line(char **line, char *buff, int n);

#endif

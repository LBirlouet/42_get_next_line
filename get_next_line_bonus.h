/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:39:10 by lbirloue          #+#    #+#             */
/*   Updated: 2023/11/23 09:24:25 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*gnl2(int fd, char *test);
char	*next_line(char *test);
char	*refresh(char *test);
char	*ft_strchr(char *s, size_t c);
char	*ft_strjoin(char *s1, char *s2, size_t j);
char	*freeall(char *str);
size_t	ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);

#endif
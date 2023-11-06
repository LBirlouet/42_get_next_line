/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:39:10 by lbirloue          #+#    #+#             */
/*   Updated: 2023/11/06 11:12:35 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif



#include "stdio.h"


char	*get_next_line(int fd);
char	*gnl2(int fd, char *test);
char	*next_line(char *test);
char	*refresh(char *test);
char	*ft_strchr(const char *s, size_t c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*freeall(char *str);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:38:44 by lbirloue          #+#    #+#             */
/*   Updated: 2023/11/03 17:22:33 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl2(int fd, char *tempo)
{
	char	*str;
	ssize_t	i;

	i = 1;
	
	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i != 0 || ft_strchr(tempo, '\n') == 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
			return (free(str), NULL);
		str[i] = 0;
		tempo = ft_strjoin(tempo, str);
		if (!tempo)
			return (NULL);
	}
	free(str);
	return (tempo);
}
char	*next_line(char *tempo)
{
	char *ret;
	int i;
	
	i = 0;
	while (tempo[i] != '\n' && tempo[i] != 0)
		i++;
	ret = malloc(sizeof(char) * i + 2);
	if (!ret)
		return (NULL);
	i = 0;
	while (tempo[i] != '\n' && tempo[i] != 0)
	{
		ret[i] = tempo[i];
		i++;
	}
	if (tempo[i] == '\n')
		ret[i++] = '\n';
	ret[i] = '\0';
	return (ret);
}

char	*refresh(char *tempo)
{
	char *ret;
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (tempo[i] != '\n' && tempo[i] != 0)
		i++;
	if (tempo[i] == 0)
		return (NULL);
	ret = malloc(sizeof(char) * ft_strlen(tempo) + 2);
	while (tempo[i] != 0 && tempo[i] != '\n')
	{
		ret[j++] = tempo[i++];
	}
	if (tempo[i] == '\n')
		ret[j++] = '\n';
	ret[j] = 0;
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*tempo;
	char *ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tempo = gnl2(fd, tempo);
	ret = next_line(tempo);
	tempo = refresh(tempo);
	return (ret);
}











 #include <fcntl.h>
int main()
{
	int i = 6;
	char	*line = NULL;
	int fd = open("test", O_RDONLY, 0644);
	
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	printf("\n|%s|\n", line);
	while (i > 0)
	{
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		i--;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 07:05:33 by jbergos           #+#    #+#             */
/*   Updated: 2024/11/05 04:06:15 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buffering(int fd, char *buffer)
{
	char	*ptr;
	int		read_bytes;

	ptr = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!ptr)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, ptr, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		ptr[read_bytes] = '\0';
		buffer = add_ptr(buffer, ptr);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(ptr);
	if (!ft_strlen(buffer) || read_bytes == -1)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*cut_line(char *s)
{
	char	*ptr;
	size_t	i;

	if (!ft_strchr(s, '\n'))
	{
		free(s);
		return (NULL);
	}
	i = 0;
	while (s[i] && s[i] != '\n')
		++i;
	ptr = ft_substr(s, i + 1, ft_strlen(s) - (i + 1));
	free(s);
	return (ptr);
}

char	*find_line(char	*s)
{
	char	*ptr;
	size_t	i;

	if (!ft_strchr(s, '\n'))
	{
		ptr = malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!ptr)
			return (NULL);
		ft_strlcpy(ptr, s, ft_strlen(s) + 1);
		return (ptr);
	}
	i = 0;
	while (s[i] && s[i] != '\n')
		++i;
	ptr = malloc(sizeof(char) * (i + 2));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, i + 2);
	return (ptr);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer = NULL;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		if (buffer)
			free(buffer);
		return (NULL);
	}
	if (!buffer)
	{
		buffer = malloc(sizeof(char) * 1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	buffer = buffering(fd, buffer);
	if (!buffer)
	{
		return (NULL);
	}
	line = find_line(buffer);
	buffer = cut_line(buffer);
	return (line);
}
/*
int main(void)
{
	int	fd = open("text.text", O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur d'ouverture");
		return (1);
	}
	char	*line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}*/
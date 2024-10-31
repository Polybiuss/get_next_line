/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:06:20 by jbergos           #+#    #+#             */
/*   Updated: 2024/10/31 05:50:32 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;
	size_t		i;
	//ssize_t		bytes_read;

	i = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!buffer)
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		++i;
	line = ft_cpy_line(buffer, i);
	//printf("Line : %s\n", line);
	buffer = ft_cut_buffer(buffer, i);
	if (line[i] == '\n')
		return (line);
	//bytes_read = read(fd, buffer, BUFFER_SIZE);
	// while (read(fd, buffer, BUFFER_SIZE) > 0)
	// {
	// 	i = 0;
	// 	while (buffer[i] && buffer[i] != '\n')
	// 		++i;
	// 	line = ft_strjoin(line, ft_cpy_line(buffer, i));
	// 	if (buffer[i] == '\n')
	// 	{
	// 	buffer = ft_cut_buffer(buffer, i);
	// 	return (line);
	// 	}
	// 	buffer = ft_cut_buffer(buffer, i);
	// }
	// if (bytes_read == 0)
	// {
	// 	free(buffer);
	// 	return (NULL);
	// // }
	// if (read(fd, buffer, BUFFER_SIZE) == 0)
	// {
	// 	free(buffer);
	// 	return (NULL);
	// }
	while (read(fd, buffer, BUFFER_SIZE))
	{
		i = 0;
		while (buffer[i] && buffer[i] != '\n')
			++i;
		//printf("buffer[i] : %c\n", buffer[i - 1]);
		//printf("BUffer : %s\n", buffer);
		line = ft_strjoin(line, ft_cpy_line(buffer, i + 1));
		buffer = ft_cut_buffer(buffer, i);
		//printf("buffer after cut : %s\n", buffer);
		if(line[ft_strlen(line) - 1] == '\n')
		{
			printf("size line : %lu\n", ft_strlen(line));
			return (line);
		}
	}
	//printf("size line : %lu\n", ft_strlen(line));
	return (line);
}

int main(void)
{
	int fd = open("text.text", O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur d'ouverture");
		return 1;
	}
	char	*line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}

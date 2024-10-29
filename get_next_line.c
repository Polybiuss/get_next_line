/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:06:20 by jbergos           #+#    #+#             */
/*   Updated: 2024/10/29 02:46:17 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


char	*get_next_line(int fd)
{
	char 		*line;
	static char	*buffer;
	size_t		i;
	i = 0;
	if (buffer) {
	while (buffer[i])
	{
		if (buffer[i] == '\n' || buffer[i] == -1)
		{
			line = ft_cpy_line(buffer, i + 1);
			buffer = ft_cut_buffer(buffer, i + 1);
			return (line);
		}
		++i;
	}
	}
	line = ft_cpy_line(buffer, i);
	buffer = malloc(sizeof(char) *  BUFFER_SIZE);
	printf("BUFFER SIZE : %d\n", BUFFER_SIZE);
	while (read(fd , buffer, sizeof(buffer)) > 0)
	 {
		i = 0;
		while (buffer[i])
		{
			if(buffer[i] == '\n' || buffer[i] == -1)
			{
				line = ft_strjoin(line, ft_cpy_line(buffer, i + 1));
				buffer = ft_cut_buffer(buffer, i + 1);
				return (line);
			}
			++i;
		}
		line = ft_strjoin(line, ft_cpy_line(buffer, sizeof(buffer)));
	 }
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
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	close(fd);
	return (0);
}
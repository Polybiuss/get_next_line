/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:06:54 by jbergos           #+#    #+#             */
/*   Updated: 2024/10/30 01:11:57 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cpy_line(char *src, size_t size)
{
	size_t	i;
	char	*ptr;
	ptr = malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = src[i];
		++i;
	}
	ptr[i] = '\0';
	return (ptr);
}
size_t ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while(s[i])
		++i;
	return (i);
}

char	*ft_cut_buffer(char *buff, size_t start)
{
	size_t	i;
	char	*ptr;

	ptr = malloc(sizeof(char) * ft_strlen(buff) + 1);

	i = 0;
	while (buff[i + start])
	{
		ptr[i] = buff[i + start];
		++i;
	}
	while(i < ft_strlen(buff))
	{
		ptr[i] = '\0';
		++i;
	}
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t len;
	size_t	i;
	size_t	j;
	char	*ptr;

	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		++j;
	}
	ptr[i + j] = '\0';
	return (ptr);
}

char	*ft_end_buffer(char *s)
{
	char *ptr;
	free(s);
	ptr = malloc(sizeof(char) * 2);
	ptr[0] = -1;
	ptr[1] = '\0';
	return ptr;
}

char	*ft_strdup()
{
	char *ptr;

	ptr = malloc(sizeof(char) * 1);
	ptr[0] = '\0';
	return ptr;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:27:41 by jbergos           #+#    #+#             */
/*   Updated: 2024/10/31 04:52:37 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>

char	*ft_cpy_line(char *src, size_t size);
char	*ft_cut_buffer(char *buff, size_t start);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_end_buffer(char *s);
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
#endif
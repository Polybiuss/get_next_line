#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>

char	*ft_cpy_line(char *src, size_t size);
char	*ft_cut_buffer(char *buff, size_t start);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_end_buffer(char *s);
char	*ft_strdup();
#endif
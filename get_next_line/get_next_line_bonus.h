#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char const *str);
char	*ft_alloc(int buffer);
char	*ft_strchr(char *s, int c);
char	*read_str(int fd, char *str);
char	*get_line(char *str);
char	*next_line(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
size_t	len_key(char *str, char key);

#endif


# ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# define BUFFER_SIZE	1024
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdint.h>
# include <stddef.h>
# include "get_next_line_utils.c"

void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char	*s, int c);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const	*s, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif

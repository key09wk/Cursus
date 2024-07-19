# ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
#	define BUFFER_SIZE 2

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdint.h>
# include <stddef.h>
# include "get_next_line_utils.c"

char 	*ft_strchr(const char *str, int c);
size_t	ft_str_len(char const *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*get_next_line(int fd);
char	*ft_strdup(char const *src);

#endif

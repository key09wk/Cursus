# ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
#	define BUFFER_SIZE 1
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdint.h>
# include <stddef.h>
# include "get_next_line_utils.c"

char	*ft_strchr(const char	*s, int c);
char 	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);

#endif

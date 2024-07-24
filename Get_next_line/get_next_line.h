#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>
# include<limits.h>
# include<stddef.h>

char 	*ft_strchr(const char *str, int c);
size_t	ft_str_len(const char  *str);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif

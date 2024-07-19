#include "get_next_line.h"

char  *ft_strchr(const char *str, int c)
{
  while (*str != (char) c)
  {
	
    if (!*str)
      return (NULL);
	str++;
  }
  return ((char *) str);
}

size_t	ft_str_len(char const *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	char	*start;
	int		lens1;
	int		lens2;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_str_len(s1);
	lens2 = ft_str_len(s2);
	newstr = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!newstr)
		return (NULL);
	start = newstr;
	while (*s1)
		*newstr++ = *s1++;
	while (*s2)
		*newstr++ = *s2++;
	*newstr = '\0';
	return (start);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*ptr;

	ptr = dst;
	if (!dst && !src)
		return (dst);
	while (n--)
		*(char *)dst++ = *(char *)src++;
	return (ptr);
}

char	*ft_strdup(char const *src)
{
	char	*dest;
	char	*start;
	size_t n;

	n = ft_str_len(src);
	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	start = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (start);
}

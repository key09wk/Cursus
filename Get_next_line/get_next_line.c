#include "get_next_line.h"

char	*get_buffer(int fd, char **storage)
{
	int		nbytes;

	*storage = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!storage)
		return (NULL);
	nbytes = read(fd, *storage, BUFFER_SIZE);
	if (nbytes < 0)
		return (NULL);
	return (*storage);
}

char	*get_line(char *storage)
{
	char	*line;
	char	*ptr;
	int		len;

	if (!storage)
		return (NULL);
	ptr = ft_strchr(storage, '\n');
	len = ((ptr - storage) + 1);
	line = ft_substr(storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = get_buffer(fd, &storage);
	if (!storage)
		return (NULL);
	line = get_line(storage);
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (printf("error"), 0);
	printf("%s", get_next_line(fd));
	close (fd);
	return (0);
}

#include "get_next_line.h"

void get_buffer(int fd, char **storage)
{
	int		nbytes;

	*storage = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!storage)
		return ;
	nbytes = read(fd, *storage, BUFFER_SIZE);
	if (nbytes < 0)
		return ;
}

////////////////////////////////////////////////////////////////////////////////

char	*refresh_line(char **storage)
{
	



}

////////////////////////////////////////////////////////////////////////////////

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	get_buffer(fd, &storage);
	if (!storage)
		return (NULL);
	line = refresh_line(&storage);
	if (!line)
		return (NULL);
	return (line);
}

////////////////////////////////////////////////////////////////////////////////

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

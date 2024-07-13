#include "get_next_line.h"

////////////////////////////////////////////////////////////////////////////////

char *get_storage(int fd, char *storage)
{
	char *buffer;
	long int nb;
	int i;

	if (!storage)
		storage = ft_strjoin("", "");
	i = 0;
	nb = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (nb > 0)
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		if (nb == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nb] = '\0';
		storage = ft_strjoin(storage, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
		i++;
	}
	printf("the numbers of BUFFER_SIZE is : %i\n", BUFFER_SIZE);
	free(buffer);
	return (storage);
}

////////////////////////////////////////////////////////////////////////////////

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		close(fd);
		return (NULL);
	}
	storage = get_storage(fd, storage);
	if (!storage)
		return (NULL);
	return (storage);
}

////////////////////////////////////////////////////////////////////////////////

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (0);
	}
	printf("%s", get_next_line(fd));
	close (fd);
	return (0);
}

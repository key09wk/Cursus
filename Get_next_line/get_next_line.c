/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skey09 <skey09@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:54:06 by kpalacio          #+#    #+#             */
/*   Updated: 2024/07/19 00:16:31 by skey09           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

////////////////////////////////////////////////////////////////////////////////

char *get_storage(int fd, char *storage)
{
	char *buffer;
	long int nb;
	char *tmp;

	if (!storage)
		storage = ft_strjoin("", "");
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nb = 1;
	while (nb > 0)
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		if (nb == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nb] = '\0';
		tmp = ft_strjoin(storage, buffer);
		free(storage);
		storage = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (storage);
} //OK!

////////////////////////////////////////////////////////////////////////////////

char *get_line(const char *storage)
{
    char *line;
    long int bytes;
	
	bytes = 0;
	if (!storage[bytes])
		return (NULL);
    while (storage[bytes] && storage[bytes] != '\n')
        bytes++;
    line = (char *)malloc(sizeof(char) * (bytes + 1));
    if (!line)
        return (NULL);
	bytes = 0;
	while (storage[bytes] && storage[bytes] != '\n')
	{
		line[bytes] = storage[bytes];
		bytes++;
	}
	if (storage[bytes] && storage[bytes] == '\n')
		line[bytes++] = '\0';
    return (line);
}

////////////////////////////////////////////////////////////////////////////////

char *update_storage(char *storage) //error
{
	char *new_storage;
    long int bytes;
	long int aux;
	
	bytes = 0;
	while(storage[bytes] && storage[bytes] != '\n')
		bytes++;
	if (!storage[bytes])
	{
		free(storage);
		return (NULL);
	}
	new_storage = (char *)malloc(sizeof(char) * (ft_str_len(storage) - (bytes + 1)));
	if (!new_storage)
		return (NULL);
	bytes++;
	aux = 0;
	while(storage[bytes])
		new_storage[aux++] = storage[bytes++];
	free(storage);
	return (new_storage);
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
	line = get_line(storage);
	if (!line)
		return (NULL);
	storage = update_storage(storage);
	if (!storage)
		return (NULL);
	return (line);
}

////////////////////////////////////////////////////////////////////////////////

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close (fd);
	return (0);
}

////////////////////////////////////////////////////////////////////////////////
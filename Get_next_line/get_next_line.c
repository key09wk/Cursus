/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpalacio <kpalacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:54:06 by kpalacio          #+#    #+#             */
/*   Updated: 2024/07/25 00:08:24 by kpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

////////////////////////////////////////////////////////////////////////////////

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

////////////////////////////////////////////////////////////////////////////////

char *get_storage(int fd, char *storage)
{
	char *buffer;
	long int nb;

	nb = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&storage));
	buffer[0] = '\0';
	while (nb > 0 && !ft_strchr(buffer, '\n'))
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		if (nb > 0)
		{
			buffer[nb] = '\0';
			storage = ft_strjoin(storage, buffer);
		}	
	}
	free(buffer);
	if (nb == -1)
		return (ft_free(&storage));
	return (storage);
} //OK!

////////////////////////////////////////////////////////////////////////////////

char *get_line(char *storage)
{
    char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(storage, '\n');
	len = (ptr - storage) + 1;
	line = ft_substr(storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

////////////////////////////////////////////////////////////////////////////////

char *update_storage(char *storage)
{
	char	*new_storage;
	char	*ptr;
	int		len;

	ptr = ft_strchr(storage, '\n');
	if (!ptr)
	{
		new_storage = NULL;
		return (ft_free(&storage));
	}
	else
		len = (ptr - storage) + 1;
	if (!storage[len])
		return (ft_free(&storage));
	new_storage = ft_substr(storage, len, ft_str_len(storage) - len);
	ft_free(&storage);
	if (!new_storage)
		return (NULL);
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
	if ((storage && !ft_strchr(storage, '\n')) || !storage)
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
/*
int	main(void)
{
	int	fd;
	update_storage(char *storage);
	char *get_line(const char *storage);
	char *get_storage(int fd, char *storage);

	fd = open("file.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close (fd);
	return (0);
}
*/
////////////////////////////////////////////////////////////////////////////////
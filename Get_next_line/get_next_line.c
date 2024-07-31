/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpalacio <kpalacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:34:06 by kpalacio          #+#    #+#             */
/*   Updated: 2024/07/31 18:31:58 by kpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_free(char **str)
{
    if (str && *str)
    {
        free(*str);
        *str = NULL;
    }
    return (NULL);
}

static char *get_storage(int fd, char *storage)
{
    char *buffer;
    ssize_t nb;

    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    nb = 1;
    while (nb > 0 && !ft_strchr(storage, '\n'))
    {
        nb = read(fd, buffer, BUFFER_SIZE);
        if (nb > 0)
        {
            buffer[nb] = '\0';
            storage = ft_strjoin(storage, buffer);
            if (!storage)
            {
                free(buffer);
                return (NULL);
            }
        }
    }
    free(buffer);
    if (nb == -1)
        return (ft_free(&storage));
    return (storage);
}

static char *get_line(const char *storage)
{
    char *line;
    char *ptr;
    size_t len;

    ptr = ft_strchr(storage, '\n');
    if (!ptr)
        len = ft_str_len(storage);
    else
        len = (ptr - storage) + 1;
    line = ft_substr(storage, 0, len);
    return (line);
}

static char *update_storage(char *storage)
{
    char    *new_storage;
    char    *ptr;
    size_t  len;

    ptr = ft_strchr(storage, '\n');
    if (!ptr)
        return (ft_free(&storage));
    len = (ptr - storage) + 1;
    new_storage = ft_substr(storage, len, ft_str_len(storage) - len);
    ft_free(&storage);
    return (new_storage);
}

char *get_next_line(int fd)
{
    static char *storage;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!storage || !ft_strchr(storage, '\n'))
    {
        storage = get_storage(fd, storage);
        if (!storage)
            return (NULL);
    }
    line = get_line(storage);
    if (!line)
        return (ft_free(&storage));
    storage = update_storage(storage);
    return (line);
}

/*
int main(void)
{
    int fd;

    fd = open("file.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    close(fd);
    return (0);
}
*/

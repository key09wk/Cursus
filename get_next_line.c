/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:34:06 by kpalacio          #+#    #+#             */
/*   Updated: 2024/10/05 102:32 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_free(char **str) //OK
{
    if (str && *str)
    {
        free(*str);
        *str = NULL;
    }
    return (NULL);
}

static char *get_storage(int fd, char *storage, char *buffer) //OK
{
    char *temp;
    long int nb;

    nb = 1;
    while (nb > 0)
    {
        nb = read(fd, buffer, BUFFER_SIZE);
        if (nb == -1)
            return (free(storage), free(buffer), NULL);
        else if (nb == 0)
            break ;
        buffer[nb] = '\0';
        if (!storage)
            storage = ft_strdup("");
        temp = storage;
        storage = ft_strjoin(temp, buffer);
        free(temp);
        temp = NULL;
        if (ft_strchr(storage, '\n'))
            break ;
    }
    return (free(buffer), storage);
}

static char *get_line(char *storage) //OK
{
    char *line;
    char *ptr;
    size_t len;

    ptr = ft_strchr(storage, '\n');
    if (!ptr)
        len = ft_strlen(storage);
    else
        len = (ptr - storage) + 1;
    line = ft_substr(storage, 0, len);
    return (line);
}

static char *update_storage(char *storage) //OK
{
    char    *new_storage;
    char    *ptr;
    size_t  len;

    ptr = ft_strchr(storage, '\n');
    if (!ptr)
        return (ft_free(&storage));
    len = (ptr - storage) + 1;
    new_storage = ft_substr(storage, len, ft_strlen(storage) - len);
    ft_free(&storage);
    return (new_storage);
}

char *get_next_line(int fd) //OK
{
    static char *storage;
    char *buffer;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    if (!storage || !ft_strchr(storage, '\n'))
    {
        storage = get_storage(fd, storage, buffer);
        if (!storage)
            return (NULL);
    }
    line = get_line(storage);
    if (!line)
        return (ft_free(&storage));
    storage = update_storage(storage);
    return (line);
}

int main(void)
{
    int fd;

    fd = open("file.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
    close(fd);
    return (0);
}
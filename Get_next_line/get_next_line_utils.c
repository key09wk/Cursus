/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpalacio <kpalacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:34:15 by kpalacio          #+#    #+#             */
/*   Updated: 2024/10/05 10:23:57 by kpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    size_t  n;

    n = 0;
    while (s[n] != '\0')
        n++;
    return (n);
}

char    *ft_strchr(char *str, int c)
{
    while (*str != (char)c)
    {
        if (!*str)
            return (NULL);
        str++;
    }
    return ((char *)str);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *new;
    char    *start;
    int     len1;
    int     len2;

    if (!s1 || !s2)
        return (NULL);
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    new = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
    if (!new)
        return (NULL);
    start = new;
    while (*s1)
        *new++ = *s1++;
    while (*s2)
        *new++ = *s2++;
    *new = '\0';
    return (start);
}

char    *ft_substr(char *s, unsigned int start, size_t len)
{
    char    *str;
    char    *str_ptr;

    if (!s)
        return (NULL);
    if (start > ft_strlen(s))
        len = 0;
    else if (len > (ft_strlen(s) - start))
        len = ft_strlen(s) - start;
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    s += start;
    str_ptr = str;
    *(str + len) = '\0';
    while (len-- && *s)
        *str++ = *s++;
    return (str_ptr);
}

char *ft_strdup(const char *s1)
{
    char *ptr;
    int     i;

    ptr = malloc(ft_strlen(s1) + 1);
    if (!ptr)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        ptr[i] = s1[i];
        i++;
    }
    ptr[i] = '\0';
    return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpalacio <kpalacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:13:03 by kpalacio          #+#    #+#             */
/*   Updated: 2024/02/12 21:13:09 by kpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if ((c >= 0) && (c <= 127))
		return (1);
	else
		return (0);
}
/*
int main()
{
    int c = 128;
    int rest = ft_isascii(c);
    printf("el resultado es : %i\n", rest);
    return 0;
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:03:39 by abellion          #+#    #+#             */
/*   Updated: 2014/11/26 12:59:46 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	unsigned int index;

	if (!dst || !src)
		return (0);
	index = 0;
	while (index < n)
	{
		dst[index] = src[index];
		index++;
	}
	return (dst);
}

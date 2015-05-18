/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:36:32 by abellion          #+#    #+#             */
/*   Updated: 2014/11/26 12:56:54 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	index;
	unsigned int	len_s1;
	unsigned int	len_s2;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	index = 0;
	while (index <= len_s1 && (int)(len_s2 - index) <= (int)len_s1)
	{
		if (ft_strcmp(ft_strsub(s1, index, ft_strlen(s2)), s2) == 0)
			return ((char *)&s1[index]);
		index++;
	}
	return (0);
}

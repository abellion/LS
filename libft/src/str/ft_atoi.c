/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:33:28 by abellion          #+#    #+#             */
/*   Updated: 2014/12/29 18:12:42 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*clear_str(char *str)
{
	int		index;
	int		start;

	index = 0;
	start = 0;
	while (str[index])
	{
		if (str[index] == '\v' || str[index] == '\f' || str[index] == '\r')
			start++;
		index++;
	}
	str = ft_strtrim(&str[start]);
	return (&str[start]);
}

int		ft_atoi(const char *str)
{
	int number;
	int negative;

	number = 0;
	negative = 1;
	if (!str || !ft_strlen(str))
		return (0);
	str = clear_str((char *)str);
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number * negative);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:10:19 by abellion          #+#    #+#             */
/*   Updated: 2014/11/26 12:59:58 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	unsigned int	i_start;
	unsigned int	nb_splits;
	char			**splits;

	i = 0;
	nb_splits = 0;
	i_start = 0;
	if (!s || !c || !(splits = (char **)malloc(sizeof(char *) * ft_strlen(s))))
		return (0);
	while (i < ft_strlen(s))
	{
		if (s[i] == c && s[i + 1] != c)
			i_start = i + 1;
		else if ((s[i] != c && s[i + 1] == c) || i == ft_strlen(s) - 1)
		{
			splits[nb_splits] = ft_strnew(i - i_start + 1);
			splits[nb_splits] = ft_strsub(s, i_start, (i - i_start + 1));
			nb_splits++;
		}
		i++;
	}
	splits[nb_splits] = NULL;
	return (splits);
}

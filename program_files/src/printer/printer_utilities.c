/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/21 19:07:32 by abellion          #+#    #+#             */
/*   Updated: 2014/12/29 17:55:48 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "../../ft_ls.h"

void			spaces(int nb_spaces)
{
	int i;

	i = 0;
	while (i < nb_spaces)
	{
		ft_putchar(' ');
		i++;
	}
}

unsigned int	nbrlen(int nbr)
{
	return (ft_strlen(ft_itoa(nbr)));
}

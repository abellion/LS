/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 20:20:53 by abellion          #+#    #+#             */
/*   Updated: 2014/12/11 20:23:55 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "../../ft_ls.h"

t_list		*sort_reverse(t_list *sequence)
{
	t_list		*tmp;
	t_list		*prev;

	if (!sequence)
		return (0);
	prev = NULL;
	while (sequence)
	{
		tmp = sequence->next;
		if (!prev)
			sequence->next = NULL;
		else
			sequence->next = prev;
		prev = sequence;
		sequence = tmp;
	}
	return (prev);
}

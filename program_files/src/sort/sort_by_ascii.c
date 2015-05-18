/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_ascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 22:19:26 by abellion          #+#    #+#             */
/*   Updated: 2014/12/29 19:58:25 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "../../ft_ls.h"

t_list	*insert_ascii(t_list *elem, t_list *sequence)
{
	if (ft_strcmp(elem->content, sequence->content) <= 0)
		return (elem->next = sequence, elem);
	if (!sequence->next)
	{
		if (ft_strcmp(elem->content, sequence->content) > 0)
			return (sequence->next = elem, sequence);
		else
			return (elem);
	}
	else
		sequence->next = insert_ascii(elem, sequence->next);
	return (sequence);
}

t_list	*sort_by_ascii(t_list *sequence)
{
	if (!sequence)
		return (0);
	return (merge_sort(sequence, &insert_ascii));
}

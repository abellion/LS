/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 14:24:56 by abellion          #+#    #+#             */
/*   Updated: 2014/12/29 19:58:17 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "../../ft_ls.h"

t_list	*merge(t_list *part1, t_list *part2, t_insert_type insert)
{
	t_list	*elem;
	t_list	*next;

	if (!part1)
		return (part2);
	else if (!part2)
		return (part1);
	elem = ft_lstnew(part1->content, ft_strlen(part1->content) + 1);
	next = part1->next;
	ft_lstdelone(&part1, &del);
	return (merge(next, insert(elem, part2), insert));
}

t_list	*separe_lst(t_list *lst)
{
	t_list *prev;
	t_list *slow;

	slow = lst;
	prev = NULL;
	while (lst && lst->next)
	{
		lst = lst->next->next;
		prev = slow;
		slow = slow->next;
	}
	if (prev)
		prev->next = NULL;
	return (slow);
}

t_list	*merge_sort(t_list *sequence, t_insert_type insert)
{
	t_list		*prt1;
	t_list		*prt2;

	if (!sequence || !sequence->next)
		return (sequence);
	prt1 = sequence;
	prt2 = separe_lst(sequence);
	return (merge(merge_sort(prt1, insert), merge_sort(prt2, insert), insert));
}

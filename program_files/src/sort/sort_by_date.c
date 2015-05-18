/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_date.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 14:26:23 by abellion          #+#    #+#             */
/*   Updated: 2014/12/29 19:59:11 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "../../ft_ls.h"

t_list	*insert_date(t_list *elem, t_list *sequence)
{
	struct stat		infos_elem;
	struct stat		infos_seq;

	lstat(elem->content, &infos_elem), lstat(sequence->content, &infos_seq);
	if (infos_elem.st_mtime >= infos_seq.st_mtime)
		return (elem->next = sequence, elem);
	else if (!sequence->next)
	{
		if (infos_elem.st_mtime < infos_seq.st_mtime)
			return (sequence->next = elem, sequence);
		else
			return (elem);
	}
	else
		sequence->next = insert_date(elem, sequence->next);
	return (sequence);
}

int		count_parts(t_list *lst_sorted)
{
	struct stat		infos;
	time_t			last_time;
	int				nb_parts;

	nb_parts = 0;
	while (lst_sorted)
	{
		lstat(lst_sorted->content, &infos);
		if (last_time && last_time != infos.st_mtime)
			nb_parts++;
		last_time = infos.st_mtime;
		lst_sorted = lst_sorted->next;
	}
	return (nb_parts + 1);
}

t_list	**make_sort_parts(t_list *lst_sorted, t_list **parts)
{
	struct stat		infos;
	time_t			last_time;
	t_list			*part;
	t_list			*prev;
	int				index;

	part = lst_sorted;
	index = 0;
	last_time = 0;
	while (lst_sorted)
	{
		lstat(lst_sorted->content, &infos);
		if (last_time && last_time != infos.st_mtime)
		{
			prev->next = NULL;
			parts[index] = sort_by_ascii(part);
			part = lst_sorted;
			index++;
		}
		last_time = infos.st_mtime;
		prev = lst_sorted;
		lst_sorted = lst_sorted->next;
	}
	parts[index] = sort_by_ascii(part);
	return (parts[index + 1] = NULL, parts);
}

t_list	*sort_by_date(t_list *sequence)
{
	t_list		*lst_sorted;
	t_list		**parts;
	t_list		*prev;
	t_list		*begin;
	int			index;

	if (!sequence)
		return (0);
	lst_sorted = merge_sort(sequence, &insert_date);
	parts = (t_list **)malloc(sizeof(parts) * (count_parts(lst_sorted) + 1));
	parts = make_sort_parts(lst_sorted, parts);
	begin = parts[0];
	prev = NULL;
	index = 0;
	while (parts[index])
	{
		if (prev)
			prev->next = parts[index];
		while (parts[index]->next)
			parts[index] = parts[index]->next;
		prev = parts[index];
		index++;
	}
	return (begin);
}

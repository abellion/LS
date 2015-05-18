/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 16:28:09 by abellion          #+#    #+#             */
/*   Updated: 2014/11/26 12:58:25 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (lst && f)
	{
		while (lst)
		{
			(*f)(lst);
			lst = lst->next;
		}
	}
}

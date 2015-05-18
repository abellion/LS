/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 14:39:18 by abellion          #+#    #+#             */
/*   Updated: 2015/01/05 18:38:59 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	void	*content_cpy;
	t_list	*tmp;

	if (!(tmp = malloc(sizeof(t_list))))
		return (0);
	if (content)
	{
		if (!(content_cpy = (void *)malloc(sizeof(content) * content_size)))
			return (0);
		ft_memcpy(content_cpy, content, content_size - 1);
		tmp->content = content_cpy;
		tmp->content_size = content_size;
	}
	else
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	tmp->next = NULL;
	return (tmp);
}

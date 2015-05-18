/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saver_lst_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 18:40:48 by abellion          #+#    #+#             */
/*   Updated: 2015/01/16 14:15:54 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "../../ft_ls.h"

t_files_infos	*saver_lst_new(void)
{
	t_files_infos *link;

	if (!(link = (t_files_infos *)malloc(sizeof(t_files_infos))))
		return (0);
	link->path = NULL;
	link->name = NULL;
	link->linked_name = ft_strnew(1024);
	link->rights = NULL;
	link->nb_links = 0;
	link->size = 0;
	link->dev_values = NULL;
	link->date = NULL;
	link->printer = NULL;
	link->next = NULL;
	return (link);
}

void			saver_lst_del(t_files_infos **lst)
{
	if (lst)
	{
		if (*lst)
		{
			free((*lst)->path);
			free((*lst)->name);
			free((*lst)->linked_name);
			free((*lst)->rights);
			free((*lst)->dev_values);
			free((*lst)->date);
			delete_printer(&(*lst)->printer);
		}
		free(*lst);
		*lst = NULL;
	}
}

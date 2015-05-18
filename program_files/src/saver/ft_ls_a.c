/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 20:32:40 by abellion          #+#    #+#             */
/*   Updated: 2014/12/28 23:12:35 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "../../ft_ls.h"

t_files_infos	*ft_ls_a(t_files_infos *files_infos)
{
	t_files_infos	*begin;
	t_files_infos	*prev;
	t_files_infos	*tmp;
	char			*file_name;

	prev = NULL;
	begin = files_infos;
	while (files_infos)
	{
		tmp = files_infos->next;
		file_name = ft_strrchr(files_infos->path, '/');
		if (file_name[1] == '.')
		{
			if (prev)
				prev->next = files_infos->next;
			else
				begin = files_infos->next;
			saver_lst_del(&files_infos);
		}
		else
			prev = files_infos;
		files_infos = tmp;
	}
	return (begin);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saver_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 21:21:12 by abellion          #+#    #+#             */
/*   Updated: 2015/01/05 19:12:05 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "../../ft_ls.h"

t_files_infos	*create_files_infos(t_list *lst, char type)
{
	t_files_infos	*files_infos;
	t_files_infos	*begin_files_infos;

	begin_files_infos = NULL;
	while (lst)
	{
		if (!begin_files_infos)
		{
			files_infos = saver_lst_new();
			begin_files_infos = files_infos;
		}
		else
		{
			files_infos->next = saver_lst_new();
			files_infos = files_infos->next;
		}
		files_infos->path = ft_strdup(lst->content);
		if (ft_strrchr(lst->content, '/') && type == 'd')
			files_infos->name = ft_strdup(ft_strrchr(lst->content, '/') + 1);
		else
			files_infos->name = ft_strdup(lst->content);
		lst = lst->next;
	}
	return (begin_files_infos);
}

t_list			*sort_options(t_list *files_name, char *options)
{
	files_name = sort_by_ascii(files_name);
	if (ft_strchr(options, 't'))
		files_name = sort_by_date(files_name);
	if (ft_strchr(options, 'r'))
		files_name = sort_reverse(files_name);
	return (files_name);
}

t_files_infos	*print_options(t_files_infos *infos, char *options, char type)
{
	if (type == 'd')
	{
		if (infos && !ft_strchr(options, 'a'))
			infos = ft_ls_a(infos);
	}
	if (infos && ft_strchr(options, 'l'))
		infos = ft_ls_l(infos);
	return (infos);
}

t_files_infos	*dirs_controller(t_args *args)
{
	t_list			*files_name;
	t_files_infos	*files_infos;

	if (ft_strchr(args->options, 'R'))
	{
		ft_ls_r(args);
		return (0);
	}
	if (!(files_name = files_name_saver(args->dirs->content)))
		return (0);
	files_name = sort_options(files_name, args->options);
	files_infos = create_files_infos(files_name, 'd');
	files_infos = print_options(files_infos, args->options, 'd');
	return (files_infos);
}

t_files_infos	*files_controller(t_list **files_name, char *options)
{
	t_files_infos	*files_infos;

	*files_name = sort_options(*files_name, options);
	files_infos = create_files_infos(*files_name, 'f');
	files_infos = print_options(files_infos, options, 'f');
	return (files_infos);
}

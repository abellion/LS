/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 18:09:34 by abellion          #+#    #+#             */
/*   Updated: 2015/01/05 19:07:18 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "../../ft_ls.h"

void		ft_ls_r(t_args *args)
{
	explorer(args, args->dirs->content);
}

int			forbid_dir(char *dir_name)
{
	dir_name = ft_strrchr(dir_name, '/');
	if (!ft_strcmp(dir_name + 1, "..") || !ft_strcmp(dir_name + 1, "."))
		return (0);
	return (1);
}

int			hidden_dir(char *dir_name, char *options)
{
	dir_name = ft_strrchr(dir_name, '/');
	if (!ft_strchr(options, 'a') && dir_name && dir_name[1] == '.')
		return (0);
	return (1);
}

void		explorer(t_args *args, char *path)
{
	char			*file;
	t_list			*files_name;

	files_name = files_name_saver(path);
	files_name = sort_options(files_name, args->options);
	if (hidden_dir(path, args->options))
		printer(files_name, args, path);
	while (files_name)
	{
		file = files_name->content;
		if (dir_checker(file, args->options) && forbid_dir(file))
			explorer(args, file);
		files_name = files_name->next;
	}
	ft_lstdel(&files_name, &del);
}

void		printer(t_list *files_name, t_args *args, char *path)
{
	t_files_infos	*files_infos;

	files_infos = create_files_infos(files_name, 'd');
	files_infos = print_options(files_infos, args->options, 'd');
	args->dirs->content = path;
	printer_top(args, files_infos);
	printer_controller(files_infos, args);
	saver_lst_del(&files_infos);
	free(args->dirs->content);
}

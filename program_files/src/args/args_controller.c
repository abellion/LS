/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 19:53:17 by abellion          #+#    #+#             */
/*   Updated: 2014/12/30 15:37:11 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "../../ft_ls.h"

t_list		*files_dirs_traitment(t_list *files_dirs, char *options)
{
	t_list			*lst;
	t_error			error;
	char			*content;

	lst = NULL;
	files_dirs = sort_by_ascii(files_dirs);
	while (files_dirs)
	{
		content = files_dirs->content;
		error = file_dir_checker(files_dirs->content, options);
		if (error.number == 1)
			ft_lstadd(&lst, ft_lstnew(content, ft_strlen(content) + 1));
		else
			files_errors_printer(error);
		if (!strcmp(error.details, "fts_open"))
			return (0);
		files_dirs = files_dirs->next;
	}
	return (lst);
}

t_args		*args_controller(char **args)
{
	t_list			*files_dirs;
	t_error			error;
	t_args			*arguments;
	char			*options;

	options = options_saver(args);
	error = options_checker(options);
	options_errors_printer(error);
	if (error.number < 1)
		return (0);
	files_dirs = files_dirs_saver(args);
	files_dirs = files_dirs_traitment(files_dirs, options);
	arguments = final_args_saver(files_dirs, options);
	if (ft_strchr(arguments->options, 't'))
		arguments->dirs = sort_by_date(arguments->dirs);
	if (ft_strchr(arguments->options, 'r'))
		arguments->dirs = sort_reverse(arguments->dirs);
	return (arguments);
}

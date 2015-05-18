/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_saver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 18:54:48 by abellion          #+#    #+#             */
/*   Updated: 2014/12/30 15:56:57 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "../../ft_ls.h"

int			is_option(char *str)
{
	if ((str[0] != '-' || !str[1]) || (str[1] == '-' && ft_strequ(str, "--")))
		return (0);
	return (1);
}

t_list		*files_dirs_saver(char **args)
{
	t_list		*lst;
	t_list		*new;
	int			index;

	index = 1;
	lst = NULL;
	while (args[index] && is_option(args[index]))
		index++;
	if (args[index] && args[index][0] == '-' && args[index][1] == '-')
		index++;
	if (!args[index])
		return (ft_lstnew(".", 2));
	while (args[index])
	{
		new = ft_lstnew(args[index], ft_strlen(args[index]) + 1);
		ft_lstadd(&lst, new);
		index++;
	}
	return (lst);
}

char		*options_saver(char **args)
{
	int			index;
	int			sous_index;
	char		*options;

	index = 1;
	sous_index = 0;
	options = ft_strnew(26);
	while (args[index] && is_option(args[index]))
	{
		sous_index = 1;
		while (args[index][sous_index])
		{
			if (!ft_strchr(options, args[index][sous_index]))
				options[ft_strlen(options)] = args[index][sous_index];
			sous_index++;
		}
		index++;
	}
	return (options);
}

t_args		*final_args_saver(t_list *files_dirs, char *options)
{
	t_args		*args;
	t_list		*new;
	t_list		*begin;
	char		*content;

	begin = files_dirs;
	args = initialize_args();
	while (files_dirs)
	{
		content = files_dirs->content;
		if (file_checker(content, options))
		{
			new = ft_lstnew(content, ft_strlen(content) + 1);
			ft_lstadd(&args->files, new);
		}
		else if (dir_checker(content, options))
		{
			new = ft_lstnew(content, ft_strlen(content) + 1);
			ft_lstadd(&args->dirs, new);
		}
		files_dirs = files_dirs->next;
	}
	args->options = options;
	ft_lstdel(&begin, &del);
	return (args);
}

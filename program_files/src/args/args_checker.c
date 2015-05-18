/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:18:53 by abellion          #+#    #+#             */
/*   Updated: 2015/02/03 17:06:11 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "../../ft_ls.h"

t_error		options_checker(char *options)
{
	char		*available_options;
	int			index;
	t_error		error;

	available_options = ft_strdup("lRart1");
	index = 0;
	while (options[index])
	{
		if (!(ft_strchr(available_options, options[index])))
		{
			error.number = -1;
			error.details = &options[index];
			return (error);
		}
		index++;
	}
	return (error.number = 1, error);
}

int			file_checker(char *path, char *options)
{
	struct stat		infos;

	if (!stat(path, &infos) && S_ISREG(infos.st_mode))
		return (1);
	else if (!lstat(path, &infos) && S_ISLNK(infos.st_mode)
			&& ft_strchr(options, 'l'))
		return (1);
	else if (!lstat(path, &infos) && stat(path, &infos) == -1)
		return (1);
	return (0);
}

int			dir_checker(char *path, char *options)
{
	struct stat		infos;

	if (!lstat(path, &infos) && S_ISDIR(infos.st_mode))
		return (1);
	else if (!lstat(path, &infos) && S_ISLNK(infos.st_mode)
			&& !ft_strchr(options, 'l'))
		return (1);
	return (0);
}

t_error		file_dir_checker(char *path, char *options)
{
	t_error		error;

	error.details = path;
	if (!file_checker(path, options) && !dir_checker(path, options))
		return (error.number = -1, error);
	return (error.number = 1, error);
}

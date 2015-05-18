/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_name_saver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 17:39:35 by abellion          #+#    #+#             */
/*   Updated: 2014/12/18 19:37:33 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "../../ft_ls.h"

t_list		*files_name_saver(char *curent_dir)
{
	t_list			*lst;
	char			*path;
	DIR				*d_stream;
	struct dirent	*read;

	lst = NULL;
	if (!(d_stream = opendir(curent_dir)))
		return (0);
	while ((read = readdir(d_stream)))
	{
		path = ft_strjoin(ft_strjoin(curent_dir, "/"), read->d_name);
		ft_lstadd(&lst, ft_lstnew(path, ft_strlen(path) + 1));
		free(path);
	}
	closedir(d_stream);
	return (lst);
}

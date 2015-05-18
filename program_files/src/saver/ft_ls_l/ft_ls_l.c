/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 20:41:35 by abellion          #+#    #+#             */
/*   Updated: 2014/12/30 16:29:15 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../libft/includes/libft.h"
#include "../../../ft_ls.h"

t_files_infos	*saver_process(t_files_infos *files_infos, struct stat infos)
{
	if (S_ISLNK(infos.st_mode))
		readlink(files_infos->path, files_infos->linked_name, 1024);
	if (S_ISBLK(infos.st_mode) || S_ISCHR(infos.st_mode))
	{
		files_infos->dev_values = (int *)malloc(sizeof(int *) * 2);
		files_infos->dev_values[0] = major(infos.st_rdev);
		files_infos->dev_values[1] = minor(infos.st_rdev);
	}
	files_infos->rights = format_rights(infos.st_mode);
	files_infos->nb_links = infos.st_nlink;
	if (!(getpwuid(infos.st_uid)))
		files_infos->user_name = ft_itoa(infos.st_uid);
	else
		files_infos->user_name = ft_strdup(getpwuid(infos.st_uid)->pw_name);
	if (!(getgrgid(infos.st_gid)))
		files_infos->user_group = ft_itoa(infos.st_gid);
	else
		files_infos->user_group = getgrgid(infos.st_gid)->gr_name;
	files_infos->date = format_date(infos.st_mtime);
	files_infos->size = infos.st_size;
	return (files_infos);
}

t_printer		*printer_val(t_printer *printer, t_files_infos *infos)
{
	if (printer->nb_links < ft_strlen(ft_itoa(infos->nb_links)))
		printer->nb_links = ft_strlen(ft_itoa(infos->nb_links));
	if (printer->user_name < ft_strlen(infos->user_name))
		printer->user_name = ft_strlen(infos->user_name);
	if (printer->user_group < ft_strlen(infos->user_group))
		printer->user_group = ft_strlen(infos->user_group);
	if (printer->size < ft_strlen(ft_itoa(infos->size)))
		printer->size = ft_strlen(ft_itoa(infos->size));
	if (infos->dev_values)
	{
		if (printer->dev_values[0] < ft_strlen(ft_itoa(infos->dev_values[0])))
			printer->dev_values[0] = ft_strlen(ft_itoa(infos->dev_values[0]));
		if (printer->dev_values[1] < ft_strlen(ft_itoa(infos->dev_values[1])))
			printer->dev_values[1] = ft_strlen(ft_itoa(infos->dev_values[1]));
	}
	if (printer->date_day < ft_strlen(infos->date[0]))
		printer->date_day = ft_strlen(infos->date[0]);
	return (printer);
}

t_files_infos	*ft_ls_l(t_files_infos *files_infos)
{
	struct stat		filestats;
	t_files_infos	*begin;
	t_printer		*printer;

	printer = initialize_printer();
	begin = files_infos;
	while (files_infos)
	{
		if (lstat(files_infos->path, &filestats) < 0)
			return (0);
		files_infos = saver_process(files_infos, filestats);
		printer = printer_val(printer, files_infos);
		printer->total_size += filestats.st_blocks;
		files_infos = files_infos->next;
	}
	begin->printer = printer;
	return (begin);
}

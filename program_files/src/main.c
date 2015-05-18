/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 21:50:19 by abellion          #+#    #+#             */
/*   Updated: 2015/02/06 17:03:32 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"
#include "../ft_ls.h"

void	read_tlst(t_list *lst)
{
	while (lst)
	{
		ft_putstr(lst->content);
		ft_putstr("\n");
		lst = lst->next;
	}
}

int		main(int ac, char **av)
{
	t_args			*args;
	t_args			*begin_args;
	t_files_infos	*files_infos;

	(void)ac;
	args = args_controller(av);
	begin_args = args;
	if (args && args->files)
	{
		files_infos = files_controller(&args->files, args->options);
		printer_controller(files_infos, args);
		saver_lst_del(&files_infos);
	}
	while (args && args->dirs)
	{
		files_infos = dirs_controller(args);
		if (!ft_strchr(args->options, 'R'))
			printer_top(args, files_infos);
		printer_controller(files_infos, args);
		saver_lst_del(&files_infos);
		args->dirs = args->dirs->next;
	}
	delete_args(&begin_args);
	return (0);
}

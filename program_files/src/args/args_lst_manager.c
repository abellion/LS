/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_lst_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/21 19:27:36 by abellion          #+#    #+#             */
/*   Updated: 2015/01/16 14:13:15 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "../../ft_ls.h"

t_args		*initialize_args(void)
{
	t_args		*args;

	if (!(args = (t_args *)malloc(sizeof(*args))))
		return (0);
	args->files = NULL;
	args->dirs = NULL;
	args->options = NULL;
	return (args);
}

void		delete_args(t_args **args)
{
	if (args && *args)
	{
		if ((*args)->options)
			free((*args)->options);
		ft_lstdel(&(*args)->files, &del);
		ft_lstdel(&(*args)->dirs, &del);
		free(*args);
	}
}

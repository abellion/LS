/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saver_errors_printer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 15:36:47 by abellion          #+#    #+#             */
/*   Updated: 2015/02/06 17:11:32 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "../../ft_ls.h"

void	saver_errors_printer(t_error error)
{
	char	*file_name;

	if (error.number == -1 && errno)
	{
		ft_putstr_fd("ft_ls: ", 2);
		file_name = ft_strrchr(error.details, '/');
		if (file_name)
			error.details = file_name + 1;
		ft_putstr_fd(error.details, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putchar_fd('\n', 2);
		errno = 0;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_errors_printer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 17:46:59 by abellion          #+#    #+#             */
/*   Updated: 2014/12/29 16:18:22 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "../../ft_ls.h"

void	options_errors_printer(t_error error)
{
	if (error.number == -1)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(error.details[0], 2);
		ft_putstr_fd("\nusage: ft_ls [-Ralrt]", 2);
		ft_putstr_fd(" [file ...]", 2);
		ft_putchar_fd('\n', 2);
	}
}

void	files_errors_printer(t_error error)
{
	if (error.number == -1 && errno)
	{
		printer_top(NULL, NULL);
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(error.details, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putchar_fd('\n', 2);
		errno = 0;
	}
}
